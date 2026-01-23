#include "global.h"
#include "event_data.h"
#include "malloc.h"
#include "pokemon.h"
#include "region_map.h"
#include "script.h"
#include "string_util.h"
#include "tv.h"
#include "constants/pokemon_memories.h"

static const u8 sText_MetAtYZ[] = _("{STR_VAR_1} was caught by {STR_VAR_3} at\n{STR_VAR_2}.");
static const u8 sText_HatchedAtYZ[] = _("{STR_VAR_1} was hatched by {STR_VAR_3} at\n{STR_VAR_2}.");
static const u8 sText_ObtainedInTrade[] = _("{STR_VAR_1} was traded to you\nfrom {STR_VAR_3}.");
static const u8 sText_FatefulEncounter[] = _("{STR_VAR_1} was obtained in a fateful encounter\nat {LV_2}{STR_VAR_2}.");
static const u8 sText_MetSomewhereAt[] = _("{STR_VAR_1} was caught somewhere at {LV_2}{STR_VAR_2}.");
static const u8 sText_HatchedSomewhereAt[] = _("{STR_VAR_1} hatched from an egg somewhere,\nat {LV_2}{STR_VAR_2}.");
static const u8 sText_ProbablyMetAt[] = _("{STR_VAR_1} seems to have met {STR_VAR_3}\nat {STR_VAR_2}");
static const u8 sText_AtLevelLocation[] = _("{LV_2}{STR_VAR_2}, at {STR_VAR_3}");

static const u8 MemoryStrings_NoMemory[] = _(".");
static const u8 MemoryStrings_WentCamping[] = _("{STR_VAR_1} went camping{STR_VAR_3}");
static const u8 MemoryStrings_FoughtTheEliteFour[] = _("{STR_VAR_1} fought and defeated The\nElite Four{STR_VAR_3}");

static const u8 sMemoryStrings_SpecialBread[] = _("{STR_VAR_2} gave him a prestigious name!");

static const u8 MemoryStrings_FullStop[] = _(".");
static const u8 MemoryStrings_You[] = _("you");
static const u8 MemoryStrings_ByX[] = _(" by {STR_VAR_2}.");
static const u8 MemoryStrings_WithX[] = _(" with {STR_VAR_2}.");

static const u8 *const sMemoryStrings[MEMORY_COUNT][2] = {
    [MEMORY_NONE]               = {MemoryStrings_NoMemory,                  MemoryStrings_NoMemory},
    [MEMORY_WENT_CAMPING]       = {MemoryStrings_WentCamping,               MemoryStrings_WithX},
    [MEMORY_ELITE_FOUR]         = {MemoryStrings_FoughtTheEliteFour,        MemoryStrings_WithX}, // Start of Special Memories
};

void GetMemory(struct ScriptContext *ctx)
{
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));
    u32 memorySlot = ScriptReadByte(ctx);

    gSpecialVar_Result = FALSE;

    if (partyIndex < PARTY_SIZE)
        gSpecialVar_Result = GetMonData(&gPlayerParty[partyIndex], (memorySlot == MON_MEMORY_OLD) ? MON_DATA_MEMORY_OLD : MON_DATA_MEMORY_NEW);
}

void BufferMemoryMessage(struct ScriptContext *ctx)
{
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));
    u32 memorySlot = ScriptReadByte(ctx);
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u32 otId = GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_ID);
    GetMonData(&gPlayerParty[partyIndex], MON_DATA_OT_NAME, otName);

    if (partyIndex < PARTY_SIZE)
    {
        if (memorySlot == MON_MEMORY_OLD || memorySlot == MON_MEMORY_NEW)
        {
            u8 memory = GetMonData(&gPlayerParty[partyIndex], (memorySlot == MON_MEMORY_OLD) ? MON_DATA_MEMORY_OLD : MON_DATA_MEMORY_NEW);

            if (memorySlot == MON_MEMORY_OLD && IsOtherTrainer(otId, otName))
            {
                if (otId == 73996)
                {
                    // This replaces the old memory of Bread with a funny joke without
                    // costing a slot in the limited BoxMon memory space by overwriting
                    StringCopy(gStringVar2, otName);
                    StringExpandPlaceholders(gStringVar4, sMemoryStrings_SpecialBread);
                    return;
                }
                else
                {
                    StringCopy(gStringVar2, otName);
                    StringExpandPlaceholders(gStringVar3, sMemoryStrings[memory][1]);
                }
            }
            else
            {
                if (IsOtherTrainer(otId, otName))
                {
                    // Most traded mons should have an old memory with their OT
                    // Thus we specify "with you" for the new memory of traded mons
                    StringCopy(gStringVar2, MemoryStrings_You);
                    StringExpandPlaceholders(gStringVar3, sMemoryStrings[memory][1]);
                }
                else
                {
                    // Otherwise not necessary, just make gStringVar3 a fullstop
                    StringCopy(gStringVar3, MemoryStrings_FullStop);
                }
            }

            StringExpandPlaceholders(gStringVar4, sMemoryStrings[memory][0]);
        }
        else // MON_MEMORY_ORIGIN
        {
            // Almost identical to the code that displays origin in party menu
            const u8 *text;
            u8 metLoc = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MET_LOCATION);
            u8 metLevel = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MET_LEVEL);
            u8 metGame = GetMonData(&gPlayerParty[partyIndex], MON_DATA_MET_GAME);

            if (metLevel == 0)
                ConvertIntToDecimalStringN(gStringVar2, (P_EGG_HATCH_LEVEL >= GEN_4) ? 1 : 5, STR_CONV_MODE_LEFT_ALIGN, 3);
            else
                ConvertIntToDecimalStringN(gStringVar2, metLevel, STR_CONV_MODE_LEFT_ALIGN, 3);

            if (metLoc < MAPSEC_NONE && metLoc != METLOC_FATEFUL_ENCOUNTER)
            {
                GetMapNameHandleAquaHideout(gStringVar3, metLoc);
                StringExpandPlaceholders(gStringVar4, sText_AtLevelLocation);
                StringCopy(gStringVar2, gStringVar4);
            }

            StringCopy(gStringVar3, otName);

            if (!IsOtherTrainer(otId, otName))
            {
                if (metLevel == 0)
                    text = (metLoc >= MAPSEC_NONE) ? sText_HatchedSomewhereAt : sText_HatchedAtYZ;
                else
                    text = (metLoc >= MAPSEC_NONE) ? sText_MetSomewhereAt : sText_MetAtYZ;
            }
            else if (metLoc == METLOC_FATEFUL_ENCOUNTER)
            {
                text = sText_FatefulEncounter;
            }
            else if (metLoc != METLOC_IN_GAME_TRADE && metGame > 0 && metGame <= VERSION_LEAF_GREEN)
            {
                text = (metLoc >= MAPSEC_NONE) ? sText_ObtainedInTrade : sText_ProbablyMetAt;
            }
            else
            {
                text = sText_ObtainedInTrade;
            }

        StringExpandPlaceholders(gStringVar4, text);
        }
    }
}

static bool8 IsMemorySpecial(u8 memory)
{
    if (memory >= SPECIAL_MEMORIES_START)
        return TRUE;
    return FALSE;
}

void SetMemoryWithRules(struct Pokemon *slot, u8 memory)
{
    u8 oldestMem = GetMonData(slot, MON_DATA_MEMORY_OLD);
    u8 newestMem = GetMonData(slot, MON_DATA_MEMORY_NEW);

    bool8 isOtherTrainer;
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u32 otId = GetMonData(slot, MON_DATA_OT_ID);
    GetMonData(slot, MON_DATA_OT_NAME, otName);

    isOtherTrainer = IsOtherTrainer(otId, otName);

    if (memory != newestMem) // if this isn't already the most recent memory
    {
        if (IsMemorySpecial(memory))
        {
            if (!isOtherTrainer)
            {
                if (!IsMemorySpecial(oldestMem) || (newestMem > oldestMem && memory > newestMem) || memory == oldestMem)
                {
                    // Moves the current newest memory to the older slot to make room for this one
                    SetMonData(slot, MON_DATA_MEMORY_OLD, &newestMem);
                    SetMonData(slot, MON_DATA_MEMORY_NEW, &memory);
                }
                else if (memory > newestMem || !IsMemorySpecial(newestMem))
                {
                    // Just overwrites the newest memory because oldest is too important to overwrite
                    SetMonData(slot, MON_DATA_MEMORY_NEW, &memory);
                }
            }
            else
            {
                if (memory > newestMem || !IsMemorySpecial(newestMem))
                {
                    // Just overwrites the newest memory because oldest is from the original trainer
                    SetMonData(slot, MON_DATA_MEMORY_NEW, &memory);
                }
            }
        } 
        else 
        {
            if (!isOtherTrainer)
            {
                if (!IsMemorySpecial(oldestMem) || memory == oldestMem)
                {
                    // Moves the current newest memory to the older slot to make room for this one
                    SetMonData(slot, MON_DATA_MEMORY_OLD, &newestMem);
                    SetMonData(slot, MON_DATA_MEMORY_NEW, &memory);
                }
                else if (!IsMemorySpecial(newestMem))
                {
                    // Just overwrites the newest memory because oldest is too important to overwrite
                    SetMonData(slot, MON_DATA_MEMORY_NEW, &memory);
                }
            }
            else if (!IsMemorySpecial(newestMem))
            {
                // Just overwrites the newest memory because oldest is from the original trainer
                SetMonData(slot, MON_DATA_MEMORY_NEW, &memory);
            }
        }
    }
}

void SetMemoryAllWithRules(u8 memory)
{
    u32 i;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
        && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
            SetMemoryWithRules(&gPlayerParty[i], memory);
    }
}

void SetMemory(struct ScriptContext *ctx)
{
    u8 memory = ScriptReadByte(ctx);
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    if (partyIndex < PARTY_SIZE)
        SetMemoryWithRules(&gPlayerParty[partyIndex], memory);
}

void SetMemoryAll(struct ScriptContext *ctx)
{
    u8 memory = ScriptReadByte(ctx);
    u32 i = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
        && GetMonData(&gPlayerParty[i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG)
            SetMemoryWithRules(&gPlayerParty[i], memory);
    }
}

void ResolveMemoriesAfterTrade(u8 partyIdx)
{
    struct Pokemon *mon = &gPlayerParty[partyIdx];
    u8 oldestMem = GetMonData(mon, MON_DATA_MEMORY_OLD);
    u8 newestMem = GetMonData(mon, MON_DATA_MEMORY_NEW);
    u8 clearMem = 0;

    if (!GetMonData(mon, MON_DATA_IS_EGG))
    {
        // puts the most important memory into the old slot so it can no longer be overwritten
        if (newestMem > oldestMem)
            SetMonData(mon, MON_DATA_MEMORY_OLD, &newestMem);
        SetMonData(mon, MON_DATA_MEMORY_NEW, &clearMem);
    }
}

bool8 GiveMonTravellerRibbon(void)
{
    // Is given to a Pokemon that has at least one memory from multiple trainers
    u8 hasTravellerRibbon;
    bool8 retVal = FALSE;

    hasTravellerRibbon = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_TRAVELLER_RIBBON);
    if (!hasTravellerRibbon)
    {
        hasTravellerRibbon = 1;
        SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_TRAVELLER_RIBBON, &hasTravellerRibbon);
        if (GetRibbonCount(&gPlayerParty[gSpecialVar_0x8004]) > NUM_CUTIES_RIBBONS)
            TryPutSpotTheCutiesOnAir(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_TRAVELLER_RIBBON);
        FlagSet(FLAG_SYS_RIBBON_GET);
        retVal = TRUE;
    }
    
    return retVal;
}

bool8 GiveMonHistoricRibbon(void)
{
    // Is given to a Pokemon that has two memories in the special category
    u8 hasHistoricRibbon;
    bool8 retVal = FALSE;

    hasHistoricRibbon = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HISTORIC_RIBBON);
    if (!hasHistoricRibbon && IsMemorySpecial(GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_MEMORY_OLD))
    && IsMemorySpecial(GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_MEMORY_NEW)))
    {
        hasHistoricRibbon = 1;
        SetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HISTORIC_RIBBON, &hasHistoricRibbon);
        if (GetRibbonCount(&gPlayerParty[gSpecialVar_0x8004]) > NUM_CUTIES_RIBBONS)
            TryPutSpotTheCutiesOnAir(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_HISTORIC_RIBBON);
        FlagSet(FLAG_SYS_RIBBON_GET);
        retVal = TRUE;
    }
    
    return retVal;
}
