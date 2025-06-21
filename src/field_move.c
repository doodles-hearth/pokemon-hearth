#include "global.h"
#include "event_data.h"
#include "field_move.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "item.h"
#include "move.h"
#include "party_menu.h"
#include "constants/field_move.h"
#include "constants/moves.h"
#include "constants/party_menu.h"

static bool32 IsFieldMoveUnlocked_Cut(void)
{
    return FlagGet(FLAG_BADGE01_GET) && CheckBagHasItem(ITEM_SECRET_CUT, 1);
}

static bool32 IsFieldMoveUnlocked_Flash(void)
{
    return FlagGet(FLAG_BADGE02_GET) && CheckBagHasItem(ITEM_SECRET_FLASH, 1);
}

static bool32 IsFieldMoveUnlocked_RockSmash(void)
{
    return FlagGet(FLAG_BADGE03_GET) && CheckBagHasItem(ITEM_SECRET_SMASH, 1);
}

static bool32 IsFieldMoveUnlocked_Strength(void)
{
    return FlagGet(FLAG_BADGE04_GET) && CheckBagHasItem(ITEM_SECRET_STRENGTH, 1);
}

static bool32 IsFieldMoveUnlocked_Surf(void)
{
    return FlagGet(FLAG_BADGE05_GET) && CheckBagHasItem(ITEM_SECRET_SURF, 1);
}

static bool32 IsFieldMoveUnlocked_Fly(void)
{
    return FlagGet(FLAG_BADGE06_GET) && CheckBagHasItem(ITEM_SECRET_FLY, 1);
}

static bool32 IsFieldMoveUnlocked_Dive(void)
{
    return FlagGet(FLAG_BADGE07_GET) && CheckBagHasItem(ITEM_SECRET_DIVE, 1);
}

static bool32 IsFieldMoveUnlocked_Waterfall(void)
{
    return FlagGet(FLAG_BADGE08_GET) && CheckBagHasItem(ITEM_SECRET_WATERFALL, 1);
}

static bool32 IsFieldMoveUnlocked_Teleport(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_Dig(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_SecretPower(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_MilkDrink(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_SoftBoiled(void)
{
    return TRUE;
}

static bool32 IsFieldMoveUnlocked_SweetScent(void)
{
    return TRUE;
}

#if OW_DEFOG_FIELD_MOVE == TRUE
static bool32 IsFieldMoveUnlocked_Defog(void)
{
    return TRUE;
}
#endif

const struct FieldMoveInfo gFieldMoveInfo[FIELD_MOVES_COUNT] =
{
    [FIELD_MOVE_CUT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Cut,
        .isUnlockedFunc = IsFieldMoveUnlocked_Cut,
        .moveID = MOVE_CUT,
        .partyMsgID = PARTY_MSG_NOTHING_TO_CUT,
    },

    [FIELD_MOVE_FLASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Flash,
        .isUnlockedFunc = IsFieldMoveUnlocked_Flash,
        .moveID = MOVE_FLASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_ROCK_SMASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_RockSmash,
        .isUnlockedFunc = IsFieldMoveUnlocked_RockSmash,
        .moveID = MOVE_ROCK_SMASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_STRENGTH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Strength,
        .isUnlockedFunc = IsFieldMoveUnlocked_Strength,
        .moveID = MOVE_STRENGTH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_SURF] =
    {
        .fieldMoveFunc = SetUpFieldMove_Surf,
        .isUnlockedFunc = IsFieldMoveUnlocked_Surf,
        .moveID = MOVE_SURF,
        .partyMsgID = PARTY_MSG_CANT_SURF_HERE,
    },

    [FIELD_MOVE_FLY] =
    {
        .fieldMoveFunc = SetUpFieldMove_Fly,
        .isUnlockedFunc = IsFieldMoveUnlocked_Fly,
        .moveID = MOVE_FLY,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_DIVE] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dive,
        .isUnlockedFunc = IsFieldMoveUnlocked_Dive,
        .moveID = MOVE_DIVE,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_WATERFALL] =
    {
        .fieldMoveFunc = SetUpFieldMove_Waterfall,
        .isUnlockedFunc = IsFieldMoveUnlocked_Waterfall,
        .moveID = MOVE_WATERFALL,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_TELEPORT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Teleport,
        .isUnlockedFunc = IsFieldMoveUnlocked_Teleport,
        .moveID = MOVE_TELEPORT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_DIG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dig,
        .isUnlockedFunc = IsFieldMoveUnlocked_Dig,
        .moveID = MOVE_DIG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_SECRET_POWER] =
    {
        .fieldMoveFunc = SetUpFieldMove_SecretPower,
        .isUnlockedFunc = IsFieldMoveUnlocked_SecretPower,
        .moveID = MOVE_SECRET_POWER,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_MILK_DRINK] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .isUnlockedFunc = IsFieldMoveUnlocked_MilkDrink,
        .moveID = MOVE_MILK_DRINK,
        .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SOFT_BOILED] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .isUnlockedFunc = IsFieldMoveUnlocked_SoftBoiled,
        .moveID = MOVE_SOFT_BOILED,
        .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SWEET_SCENT] =
    {
        .fieldMoveFunc = SetUpFieldMove_SweetScent,
        .isUnlockedFunc = IsFieldMoveUnlocked_SweetScent,
        .moveID = MOVE_SWEET_SCENT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

#if OW_DEFOG_FIELD_MOVE == TRUE
    [FIELD_MOVE_DEFOG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Defog,
        .isUnlockedFunc = IsFieldMoveUnlocked_Defog,
        .moveID = MOVE_DEFOG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },
#endif

};




/**
 * Checks if the given Pokémon knows at least one move of the given field move type.
 *
 * @param mon           Pokémon
 * @param fieldMoveType field move type
 * @return true if the Pokémon knows the field move, false otherwise
 */
bool32 KnowsFieldMove(struct Pokemon *mon, u32 fieldMoveType)
{
    if (GetMonData(mon, MON_DATA_IS_EGG)) {
        return FALSE;
    }

    // Check the field move flags of each of the Pokémon's 4 moves
    for (u32 iMoveSlot = 0; iMoveSlot < MAX_MON_MOVES; iMoveSlot += 1)
    {
        u16 move = GetMonData(mon, MON_DATA_MOVE1 + iMoveSlot, NULL);

        if (move == MOVE_NONE)
        {
            break;
        }

        if (gMovesInfo[move].fieldMove == fieldMoveType)
        {
            return TRUE;
        }
    }
    
    return FALSE;
}

/**
 * Checks if the given field move is known by at least one Pokémon other than the given one.
 *
 * @param fieldMoveType field move type
 * @param monPartyIndex index of the selected Pokémon in the party
 * @param mons          party mons
 * @return true if the field move is known by another party mon, false otherwise
 */
bool32 IsFieldMoveKnownByAnotherPartyMon(u32 fieldMoveType, u32 monPartyIndex, struct Pokemon * mons)
{
    bool32 otherMonAlsoKnowsFieldMove = FALSE;
    // For each of the other mons in the party
    for (u32 j = 0; j < PARTY_SIZE; j += 1)
    {
        if (
            monPartyIndex != j
            && GetMonData(&mons[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
            && GetMonData(&mons[j], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
        )
        {
            // If the mon knows the field move, we're good
            if (KnowsFieldMove(&mons[j], fieldMoveType))
            {
                otherMonAlsoKnowsFieldMove = TRUE;
                break;
            }
        }
    }
    
    // No other mon knows this field move, so the move has to stay
    if (!otherMonAlsoKnowsFieldMove) {
        return FALSE;
    }

    return TRUE;
}
