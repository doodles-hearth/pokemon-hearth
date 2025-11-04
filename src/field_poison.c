#include "global.h"
#include "battle.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "fieldmap.h"
#include "field_message_box.h"
#include "field_poison.h"
#include "fldeff_misc.h"
#include "frontier_util.h"
#include "party_menu.h"
#include "pokenav.h"
#include "script.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "trainer_hill.h"
#include "constants/field_poison.h"
#include "constants/form_change_types.h"
#include "constants/metatile_behaviors.h"
#include "constants/party_menu.h"

static u32 sFaintedFromDecayMask; // bitmask to determine if the pokemon just fainted from decay

static bool32 IsWalkingOnDecay() // helper function to check if the player is on a decayed metatile
{
    return MapGridGetMetatileBehaviorAt(gSaveBlock1Ptr->pos.x + MAP_OFFSET, gSaveBlock1Ptr->pos.y + MAP_OFFSET) == MB_DECAY;
}

static bool32 IsMonValidSpecies(struct Pokemon *pokemon)
{
    u16 species = GetMonData(pokemon, MON_DATA_SPECIES_OR_EGG);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return FALSE;

    return TRUE;
}

static bool32 AllMonsFainted(void)
{
    int i;
    struct Pokemon *pokemon = gPlayerParty;

    for (i = 0; i < PARTY_SIZE; i++, pokemon++)
    {
        if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) != 0)
            return FALSE;
    }
    return TRUE;
}

static void FaintFromFieldPoison(u8 partyIdx)
{
    struct Pokemon *pokemon = &gPlayerParty[partyIdx];
    u32 status = STATUS1_NONE;

    if (OW_POISON_DAMAGE < GEN_4)
        AdjustFriendship(pokemon, FRIENDSHIP_EVENT_FAINT_FIELD_PSN);

    SetMonData(pokemon, MON_DATA_STATUS, &status);
    GetMonData(pokemon, MON_DATA_NICKNAME, gStringVar1);
    StringGet_Nickname(gStringVar1);
}

static void FaintFromDecay(u8 partyIdx) 
{
    struct Pokemon *pokemon = &gPlayerParty[partyIdx];
    u32 status = STATUS1_NONE;

    AdjustFriendship(pokemon, FRIENDSHIP_EVENT_FAINT_FIELD_PSN);

    SetMonData(pokemon, MON_DATA_STATUS, &status);
    GetMonData(pokemon, MON_DATA_NICKNAME, gStringVar1);
    StringGet_Nickname(gStringVar1);
}

static bool32 MonFaintedFromPoison(u8 partyIdx)
{
    struct Pokemon *pokemon = &gPlayerParty[partyIdx];
    if (IsMonValidSpecies(pokemon) && GetMonData(pokemon, MON_DATA_HP) == ((OW_POISON_DAMAGE < GEN_4) ? 0 : 1) && GetAilmentFromStatus(GetMonData(pokemon, MON_DATA_STATUS)) == AILMENT_PSN)
        return TRUE;

    return FALSE;
}

static bool32 MonFaintedFromDecay(u8 partyIdx)
{
    struct Pokemon *pokemon = &gPlayerParty[partyIdx];

    if (
        IsMonValidSpecies(pokemon) &&
        GetMonData(pokemon, MON_DATA_HP) == 0 &&
        (sFaintedFromDecayMask & (1 << partyIdx))
    )
        {
        sFaintedFromDecayMask &= ~(1 << partyIdx);
        return TRUE;
        }
    return FALSE;
}

#define tState    data[0]
#define tPartyIdx data[1]

static void Task_TryFieldPoisonWhiteOut(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    switch (tState)
    {
    case 0:
        for (; tPartyIdx < PARTY_SIZE; tPartyIdx++)
        {
            if (MonFaintedFromPoison(tPartyIdx))
            {
                FaintFromFieldPoison(tPartyIdx);
                ShowFieldMessage(gText_PkmnFainted_FldPsn);
                tState++;
                return;
            }
            else if (MonFaintedFromDecay(tPartyIdx))
            {
                FaintFromDecay(tPartyIdx);
                ShowFieldMessage(gText_PkmnFainted_FldPsn);
                tState++;
                return;
            }
        }
        tState = 2; // Finished checking party
        break;
    case 1:
        // Wait for "{mon} fainted" message, then return to party loop
        if (IsFieldMessageBoxHidden())
            tState--;
        break;
    case 2:
        if (AllMonsFainted())
        {
            // Battle facilities have their own white out script to handle the challenge loss
#ifdef BUGFIX
            if (CurrentBattlePyramidLocation() || InBattlePike() || InTrainerHillChallenge())
#else
            if (CurrentBattlePyramidLocation() | InBattlePike() || InTrainerHillChallenge())
#endif
                gSpecialVar_Result = FLDPSN_FRONTIER_WHITEOUT;
            else
                gSpecialVar_Result = FLDPSN_WHITEOUT;
        }
        else
        {
            gSpecialVar_Result = FLDPSN_NO_WHITEOUT;
            UpdateFollowingPokemon();
        }
        ScriptContext_Enable();
        DestroyTask(taskId);
        break;
    }
}

#undef tState
#undef tPartyIdx

void TryFieldPoisonWhiteOut(void)
{
    CreateTask(Task_TryFieldPoisonWhiteOut, 80);
    ScriptContext_Stop();
}

s32 DoPoisonDecayFieldEffect(void)
{
    u32 hp;
    struct Pokemon *pokemon = gPlayerParty;
    u32 numPoisoned = 0;
    u32 numFainted = 0;

    bool32 isWalkingOnDecay = IsWalkingOnDecay();
    sFaintedFromDecayMask = 0; //Reset the bitmask so we can track which pokemon are going to faint when the effect is activated

    for (u32 i = 0; i < PARTY_SIZE; i++)
    {
        bool32 isPoisoned = GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES) && 
                            GetAilmentFromStatus(GetMonData(pokemon, MON_DATA_STATUS)) == AILMENT_PSN;

        u32 maxhp = GetMonData(pokemon, MON_DATA_MAX_HP); // For Poison Heal
        u32 initialhp = GetMonData(pokemon, MON_DATA_HP);
        u32 ability = GetMonAbility(pokemon);

        if (ability == ABILITY_MAGIC_GUARD) // Magic Guard mons take damage from neither poison nor decay
        {
            pokemon++;
            continue;
        }

        hp = initialhp;

        if (isPoisoned)
        {
            // Apply poison damage

            if (ability == ABILITY_POISON_HEAL) // Heal and skip the rest
                hp++;

            else if (OW_POISON_DAMAGE < GEN_4 && (hp == 0 || --hp == 0))
                TryFormChange(i, B_SIDE_PLAYER, FORM_CHANGE_FAINT);

            else if (OW_POISON_DAMAGE >= GEN_4 && (hp > 1))
                hp--;
        }

        if (isWalkingOnDecay)
        {
            if (OW_POISON_DAMAGE < GEN_4)
            {

                if(hp > 1)
                    hp--;
                else if (hp == 1)
                {
                    hp--;
                    TryFormChange(i, B_SIDE_PLAYER, FORM_CHANGE_FAINT);
                    sFaintedFromDecayMask |= (1 << i);
                }
            }
            else if (OW_POISON_DAMAGE >= GEN_4 && (hp > 1))
            {
                hp--;
            }
        }

        if(hp != GetMonData(pokemon, MON_DATA_HP)) //Apply the damage/healing
        {
            hp = (hp > maxhp) ? maxhp : hp; //clamp hp to the pokemon's max hp
            SetMonData(pokemon, MON_DATA_HP, &hp);
            if(hp < initialhp)
                numPoisoned++;
            if(hp == 0)
                numFainted++;
        }
        pokemon++;
    }

    // Do screen flash effect
    if (numFainted != 0 || numPoisoned != 0)
        FldEffPoison_Start();

    if (numFainted != 0)
        return FLDPSN_FNT;

    if (numPoisoned != 0)
        return FLDPSN_PSN;

    return FLDPSN_NONE;
}
