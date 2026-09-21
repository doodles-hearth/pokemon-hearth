#include "global.h"
#include "event_data.h"
#include "malloc.h"
#include "pokemon.h"
#include "pokemon_memories.h"
#include "random.h"
#include "region_map.h"
#include "script.h"
#include "string_util.h"
#include "tv.h"
#include "constants/characters.h"
#include "constants/pokemon_memories.h"

// Where the Pokémon came from
static const u8 sText_MetAtYZ[] = _("{STR_VAR_1} was caught by {STR_VAR_3} at\n{STR_VAR_2}.");
static const u8 sText_HatchedAtYZ[] = _("{STR_VAR_1} was hatched by {STR_VAR_3}\nat {STR_VAR_2}.");
static const u8 sText_ObtainedInTrade[] = _("{STR_VAR_1} was traded to you\nfrom {STR_VAR_3}.");
static const u8 sText_FatefulEncounter[] = _("{STR_VAR_1} was obtained in a\nfateful encounter at {LV_2}{STR_VAR_2}.");
static const u8 sText_MetSomewhereAt[] = _("{STR_VAR_1} was caught somewhere\nat {LV_2}{STR_VAR_2}.");
static const u8 sText_HatchedSomewhereAt[] = _("{STR_VAR_1} hatched from an egg\nsomewhere, at {LV_2}{STR_VAR_2}.");
static const u8 sText_ProbablyMetAt[] = _("{STR_VAR_1} seems to have met\n{STR_VAR_3} at {STR_VAR_2}");
static const u8 sText_AtLevelLocation[] = _("{LV_2}{STR_VAR_2}, at {STR_VAR_3}");
static const u8 sText_MemoryGirlCaughtByTrainer[] = _("{STR_VAR_1} was caught by\n{STR_VAR_3} and…\l");

// What the Pokémon remembers doing
static const u8 MemoryStrings_NoMemory[] = _(".");
static const u8 MemoryStrings_WentCamping[] = _("{STR_VAR_1} went camping{STR_VAR_3}");
static const u8 MemoryStrings_FoughtTheEliteFour[] = _("{STR_VAR_1} fought and defeated\nThe Elite Four{STR_VAR_3}");
static const u8 MemoryStrings_ClearedHideout[] = _("{STR_VAR_1} busted a hideout full\nof bandits{STR_VAR_3}");
static const u8 MemoryStrings_BeatDojo[] = _("{STR_VAR_1} triumphed against\na Dojo Master{STR_VAR_3}");

static const u8 sMemoryStrings_SpecialBread[] = _("{STR_VAR_2} gave him a prestigious name!");

static const u8 MemoryStrings_FullStop[] = _(".");
static const u8 MemoryStrings_FullStopExclamationMark[] = _("!");
static const u8 MemoryStrings_You[] = _("you");
static const u8 MemoryStrings_ByX[] = _(" by {STR_VAR_2}.");
static const u8 MemoryStrings_WithX[] = _(" with {STR_VAR_2}!");

static const u8 *const sMemoryStrings[MEMORY_COUNT][2] = {
    [MEMORY_NONE]               = {MemoryStrings_NoMemory,                  MemoryStrings_NoMemory},
    [MEMORY_WENT_CAMPING]       = {MemoryStrings_WentCamping,               MemoryStrings_WithX},
    [MEMORY_CLEARED_HIDEOUT]    = {MemoryStrings_ClearedHideout,            MemoryStrings_WithX}, // Start of Special Memories
    [MEMORY_BEAT_DOJO]          = {MemoryStrings_BeatDojo,                  MemoryStrings_WithX},
    [MEMORY_ELITE_FOUR]         = {MemoryStrings_FoughtTheEliteFour,        MemoryStrings_WithX},
};

// Fluff messages
static const u8 sText_MemoryGirlIntroTogether[] = _("{STR_VAR_1} and {STR_VAR_3}\ntravelled together until…");
static const u8 sText_MemoryGirlIntroWith[] = _("{STR_VAR_1} was with {STR_VAR_3}\nwhen…");
static const u8 *const sText_MemoryGirlIntroVariants[] = {
    sText_MemoryGirlIntroTogether,
    sText_MemoryGirlIntroWith,
};

static const u8 sText_MemoryGirlReactionFun[] = _("Sounds fun!");
static const u8 sText_MemoryGirlReactionWish[] = _("Wow! I wish I could do that!");
static const u8 *const sText_MemoryGirlReactionVariants[] = {
    sText_MemoryGirlReactionFun,
    sText_MemoryGirlReactionWish,
};

static const u8 sText_MemoryGirlThenOrigin[] = _("That's when…\n… … …");
static const u8 sText_MemoryGirlThenNew[] = _("Then…\n… … …");
static const u8 *const sText_MemoryGirlThenVariants[] = {
    sText_MemoryGirlThenOrigin,
    sText_MemoryGirlThenNew,
};

// Reading end
static const u8 sText_MemoryGirlNoMemoriesOwn[] = _("That's all…\pIt looks like {STR_VAR_1}\nhasn't done much!");
static const u8 sText_MemoryGirlNoMemoriesOtherOutro[] = _("That's all!\pIt looks like {STR_VAR_1}\nhasn't done much!");
static const u8 sText_MemoryGirlTravelled[] = _("Wowie! Your Pokémon has done a lot\nof travelling!");
static const u8 sText_MemoryGirlTravellerPrelude[] = _("I'm going to give them a\nsuper-duper badge!");
static const u8 sText_MemoryGirlHistoricPrelude[] = _("Wowie! Your Pokémon has a lot of\ngreat memories!\pI'm going to give them a\nsuper-duper badge!");
static const u8 sText_MemoryGirlTravellerRibbon[] = _("{STR_VAR_1} received the\nTraveller Ribbon.");
static const u8 sText_MemoryGirlHistoricRibbon[] = _("{STR_VAR_1} received the\nHistoric Ribbon.");
static const u8 sText_MemoryGirlTravellerOutro[] = _("Now they can show off how\nadventurous they are!");
static const u8 sText_MemoryGirlHistoricOutro[] = _("Now they can show off how\nimportant they are!");
static const u8 sText_MemoryGirlGoodMemories[] = _("Wowie! Your Pokémon has a lot\nof good memories!");
static const u8 sText_MemoryGirlOnlyNew[] = _("…And… that's it!\pYour Pokémon has done some things,\nbut not many!");

enum MemoryGirlLine {
    MEMORY_GIRL_LINE_ORIGIN,
    MEMORY_GIRL_LINE_NO_MEMORIES,
    MEMORY_GIRL_LINE_INTRO,
    MEMORY_GIRL_LINE_OLD,
    MEMORY_GIRL_LINE_REACTION,
    MEMORY_GIRL_LINE_THEN_ORIGIN,
    MEMORY_GIRL_LINE_THEN_NEW,
    MEMORY_GIRL_LINE_NEW,
    MEMORY_GIRL_LINE_TRAVELLED,
    MEMORY_GIRL_LINE_REWARD,
    MEMORY_GIRL_LINE_ONLY_NEW,
};

enum MemoryGirlRibbon {
    MEMORY_GIRL_RIBBON_NONE,
    MEMORY_GIRL_RIBBON_TRAVELLER,
    MEMORY_GIRL_RIBBON_HISTORIC,
};

#define MEMORY_GIRL_MAX_LINES 12

struct MemoryGirlReading {
    u8 partyIndex;
    u8 lines[MEMORY_GIRL_MAX_LINES];
    u8 lineCount;
    u8 nextLine;
    u8 ribbonStage;
    u8 ribbon;
    bool8 otherTrainer;
    u8 thenVariant;
    u8 reactionVariant;
};

static EWRAM_DATA struct MemoryGirlReading *sMemoryGirlReading = NULL;

void GetMemory(struct ScriptContext *ctx)
{
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));
    u32 memorySlot = ScriptReadByte(ctx);

    gSpecialVar_Result = FALSE;

    if (partyIndex < PARTY_SIZE)
        gSpecialVar_Result = GetMonData(
            &gParties[B_TRAINER_PLAYER][partyIndex],
            (memorySlot == MON_MEMORY_OLD) ? MON_DATA_MEMORY_OLD : MON_DATA_MEMORY_NEW
        );
}

static bool8 IsMemorySpecial(u8 memory)
{
    if (memory >= SPECIAL_MEMORIES_START && memory < MEMORY_COUNT)
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
        if (
            GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
            && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
        )
        {
            SetMemoryWithRules(&gParties[B_TRAINER_PLAYER][i], memory);
        }
    }
}

void SetMemory(struct ScriptContext *ctx)
{
    u8 memory = ScriptReadByte(ctx);
    u32 partyIndex = VarGet(ScriptReadHalfword(ctx));

    if (partyIndex < PARTY_SIZE)
        SetMemoryWithRules(&gParties[B_TRAINER_PLAYER][partyIndex], memory);
}

void SetMemoryAll(struct ScriptContext *ctx)
{
    u8 memory = ScriptReadByte(ctx);
    u32 i = 0;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        if (
            GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) != SPECIES_NONE
            && GetMonData(&gParties[B_TRAINER_PLAYER][i], MON_DATA_SPECIES_OR_EGG) != SPECIES_EGG
        )
        {
            SetMemoryWithRules(&gParties[B_TRAINER_PLAYER][i], memory);
        }
    }
}

static bool8 IsMemoryFromOtherTrainer(struct Pokemon *mon)
{
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u32 otId = GetMonData(mon, MON_DATA_OT_ID);

    GetMonData(mon, MON_DATA_OT_NAME, otName);
    return otId != READ_OTID_FROM_SAVE
        || GetMonData(mon, MON_DATA_LANGUAGE) != GAME_LANGUAGE
        || StringCompare(otName, gSaveBlock2Ptr->playerName) != 0;
}

void ResolveMemoriesAfterTrade(u8 partyIdx)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIdx];
    u8 oldestMem = GetMonData(mon, MON_DATA_MEMORY_OLD);
    u8 newestMem = GetMonData(mon, MON_DATA_MEMORY_NEW);
    u8 clearMem = 0;

    if (!GetMonData(mon, MON_DATA_IS_EGG))
    {
        // puts the most important memory into the old slot so it can no longer be overwritten
        if (newestMem > oldestMem)
        {
            SetMonData(mon, MON_DATA_MEMORY_OLD, &newestMem);
        }
        SetMonData(mon, MON_DATA_MEMORY_NEW, &clearMem);
    }
}

static bool8 GiveMonTravellerRibbon(struct Pokemon *mon)
{
    // Is given to a Pokemon that has at least one memory from multiple trainers
    u8 hasTravellerRibbon = GetMonData(mon, MON_DATA_TRAVELLER_RIBBON);

    if (!hasTravellerRibbon)
    {
        hasTravellerRibbon = 1;
        SetMonData(mon, MON_DATA_TRAVELLER_RIBBON, &hasTravellerRibbon);
        if (GetRibbonCount(mon) > NUM_CUTIES_RIBBONS)
            TryPutSpotTheCutiesOnAir(mon, MON_DATA_TRAVELLER_RIBBON);
        FlagSet(FLAG_SYS_RIBBON_GET);
        return TRUE;
    }

    return FALSE;
}

static bool8 GiveMonHistoricRibbon(struct Pokemon *mon)
{
    // Is given to a Pokemon that has two memories in the special category
    u8 hasHistoricRibbon = GetMonData(mon, MON_DATA_HISTORIC_RIBBON);
    if (
        !hasHistoricRibbon
        && IsMemorySpecial(GetMonData(mon, MON_DATA_MEMORY_OLD))
        && IsMemorySpecial(GetMonData(mon, MON_DATA_MEMORY_NEW))
    )
    {
        hasHistoricRibbon = 1;
        SetMonData(mon, MON_DATA_HISTORIC_RIBBON, &hasHistoricRibbon);
        if (GetRibbonCount(mon) > NUM_CUTIES_RIBBONS)
            TryPutSpotTheCutiesOnAir(mon, MON_DATA_HISTORIC_RIBBON);
        FlagSet(FLAG_SYS_RIBBON_GET);
        return TRUE;
    }

    return FALSE;
}

static void QueueMemoryGirlLine(enum MemoryGirlLine line)
{
    if (sMemoryGirlReading->lineCount < ARRAY_COUNT(sMemoryGirlReading->lines))
        sMemoryGirlReading->lines[sMemoryGirlReading->lineCount++] = line;
}

static u16 FinishMemoryGirlReading(void)
{
    Free(sMemoryGirlReading);
    sMemoryGirlReading = NULL;
    return MEMORY_GIRL_READING_DONE;
}

static void BufferMemoryGirlNames(struct Pokemon *mon)
{
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u8 monNickname[POKEMON_NAME_LENGTH + 1];

    GetMonData(mon, MON_DATA_OT_NAME, otName);
    GetMonData(mon, MON_DATA_NICKNAME, monNickname);
    StringCopy(gStringVar1, monNickname);
    StringCopy(gStringVar3, otName);
}

void StartMemoryGirlReading(void)
{
    struct Pokemon *mon;
    u8 oldMemory;
    u8 newMemory;

    Free(sMemoryGirlReading);
    sMemoryGirlReading = NULL;

    if (gSpecialVar_0x8004 >= PARTY_SIZE)
        return;

    mon = &gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004];
    if (GetMonData(mon, MON_DATA_SPECIES_OR_EGG) == SPECIES_NONE
        || GetMonData(mon, MON_DATA_SPECIES_OR_EGG) == SPECIES_EGG)
        return;

    sMemoryGirlReading = AllocZeroed(sizeof(*sMemoryGirlReading));
    if (sMemoryGirlReading == NULL)
        return;

    sMemoryGirlReading->partyIndex = gSpecialVar_0x8004;
    sMemoryGirlReading->otherTrainer = IsMemoryFromOtherTrainer(mon);
    oldMemory = GetMonData(mon, MON_DATA_MEMORY_OLD);
    newMemory = GetMonData(mon, MON_DATA_MEMORY_NEW);
    if (oldMemory >= MEMORY_COUNT)
        oldMemory = MEMORY_NONE;
    if (newMemory >= MEMORY_COUNT)
        newMemory = MEMORY_NONE;

    if (!sMemoryGirlReading->otherTrainer)
        QueueMemoryGirlLine(MEMORY_GIRL_LINE_ORIGIN);

    if (oldMemory == MEMORY_NONE && newMemory == MEMORY_NONE)
    {
        QueueMemoryGirlLine(MEMORY_GIRL_LINE_NO_MEMORIES);
        return;
    }

    sMemoryGirlReading->thenVariant = Random() % ARRAY_COUNT(sText_MemoryGirlIntroVariants);
    QueueMemoryGirlLine(MEMORY_GIRL_LINE_INTRO);

    if (oldMemory != MEMORY_NONE)
    {
        QueueMemoryGirlLine(MEMORY_GIRL_LINE_OLD);
        sMemoryGirlReading->reactionVariant = Random() % ARRAY_COUNT(sText_MemoryGirlReactionVariants);
        QueueMemoryGirlLine(MEMORY_GIRL_LINE_REACTION);

        if (sMemoryGirlReading->otherTrainer)
        {
            QueueMemoryGirlLine(MEMORY_GIRL_LINE_THEN_ORIGIN);
            QueueMemoryGirlLine(MEMORY_GIRL_LINE_ORIGIN);
        }

        if (newMemory != MEMORY_NONE)
        {
            QueueMemoryGirlLine(MEMORY_GIRL_LINE_THEN_NEW);
            QueueMemoryGirlLine(MEMORY_GIRL_LINE_NEW);
            if (sMemoryGirlReading->otherTrainer)
                QueueMemoryGirlLine(MEMORY_GIRL_LINE_TRAVELLED);
            QueueMemoryGirlLine(MEMORY_GIRL_LINE_REWARD);
        }
    }
    else
    {
        QueueMemoryGirlLine(MEMORY_GIRL_LINE_NEW);
        QueueMemoryGirlLine(MEMORY_GIRL_LINE_ONLY_NEW);
    }
}

static void BufferMemoryMessageForMon(struct Pokemon *mon, u8 memorySlot, bool8 otherTrainer)
{
    u8 otName[PLAYER_NAME_LENGTH + 1];
    u8 monNickname[POKEMON_NAME_LENGTH + 1];
    u32 otId = GetMonData(mon, MON_DATA_OT_ID);

    GetMonData(mon, MON_DATA_OT_NAME, otName);
    GetMonData(mon, MON_DATA_NICKNAME, monNickname);
    StringCopy(gStringVar1, monNickname);

    if (memorySlot == MON_MEMORY_OLD || memorySlot == MON_MEMORY_NEW)
    {
        u8 memory = GetMonData(mon, (memorySlot == MON_MEMORY_OLD) ? MON_DATA_MEMORY_OLD : MON_DATA_MEMORY_NEW);

        if (memory >= MEMORY_COUNT)
        {
            gStringVar4[0] = EOS;
            return;
        }
        if (memory == MEMORY_NONE)
        {
            StringCopy(gStringVar4, MemoryStrings_NoMemory);
            return;
        }

        if (memorySlot == MON_MEMORY_OLD && otherTrainer)
        {
            if (otId == 73996)
            {
                // This replaces the old memory of Bread with a funny joke without
                // costing a slot in the limited BoxMon memory space by overwriting
                StringCopy(gStringVar2, otName);
                StringExpandPlaceholders(gStringVar4, sMemoryStrings_SpecialBread);
                return;
            }

            StringCopy(gStringVar2, otName);
            StringExpandPlaceholders(gStringVar3, sMemoryStrings[memory][1]);
        }
        else if (otherTrainer)
        {
            StringCopy(gStringVar2, MemoryStrings_You);
            StringExpandPlaceholders(gStringVar3, sMemoryStrings[memory][1]);
        }
        else
        {
            StringCopy(gStringVar3, MemoryStrings_FullStopExclamationMark);
        }

        StringExpandPlaceholders(gStringVar4, sMemoryStrings[memory][0]);
    }
    else if (memorySlot == MON_MEMORY_ORIGIN)
    {
        // Match the origin text used by the party menu.
        const u8 *text;
        u8 metLoc = GetMonData(mon, MON_DATA_MET_LOCATION);
        u8 metLevel = GetMonData(mon, MON_DATA_MET_LEVEL);
        u8 metGame = GetMonData(mon, MON_DATA_MET_GAME);

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

        if (!otherTrainer)
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
    else
    {
        gStringVar4[0] = EOS;
    }
}

u16 NextMemoryGirlReading(void)
{
    struct Pokemon *mon;
    const u8 *text;
    enum MemoryGirlLine line;

    gStringVar4[0] = EOS;
    if (sMemoryGirlReading == NULL)
        return MEMORY_GIRL_READING_DONE;
    if (sMemoryGirlReading->nextLine >= sMemoryGirlReading->lineCount && sMemoryGirlReading->ribbonStage == 0)
        return FinishMemoryGirlReading();

    mon = &gParties[B_TRAINER_PLAYER][sMemoryGirlReading->partyIndex];
    if (sMemoryGirlReading->ribbonStage == 1)
    {
        sMemoryGirlReading->ribbonStage = 2;
        BufferMemoryGirlNames(mon);
        text = sMemoryGirlReading->ribbon == MEMORY_GIRL_RIBBON_TRAVELLER
            ? sText_MemoryGirlTravellerRibbon : sText_MemoryGirlHistoricRibbon;
        StringExpandPlaceholders(gStringVar4, text);
        return MEMORY_GIRL_READING_RIBBON_NOTIFICATION;
    }
    if (sMemoryGirlReading->ribbonStage == 2)
    {
        sMemoryGirlReading->ribbonStage = 0;
        text = sMemoryGirlReading->ribbon == MEMORY_GIRL_RIBBON_TRAVELLER
            ? sText_MemoryGirlTravellerOutro : sText_MemoryGirlHistoricOutro;
        StringCopy(gStringVar4, text);
        return MEMORY_GIRL_READING_DIALOGUE;
    }

    while (sMemoryGirlReading->nextLine < sMemoryGirlReading->lineCount)
    {
        line = sMemoryGirlReading->lines[sMemoryGirlReading->nextLine++];
        switch (line)
        {
        case MEMORY_GIRL_LINE_ORIGIN:
            BufferMemoryMessageForMon(mon, MON_MEMORY_ORIGIN, sMemoryGirlReading->otherTrainer);
            return MEMORY_GIRL_READING_DIALOGUE;
        case MEMORY_GIRL_LINE_OLD:
            BufferMemoryMessageForMon(mon, MON_MEMORY_OLD, sMemoryGirlReading->otherTrainer);
            return MEMORY_GIRL_READING_DIALOGUE;
        case MEMORY_GIRL_LINE_NEW:
            BufferMemoryMessageForMon(mon, MON_MEMORY_NEW, sMemoryGirlReading->otherTrainer);
            return MEMORY_GIRL_READING_DIALOGUE;
        case MEMORY_GIRL_LINE_REWARD:
            if (sMemoryGirlReading->otherTrainer)
            {
                if (!GiveMonTravellerRibbon(mon))
                    continue;
                sMemoryGirlReading->ribbon = MEMORY_GIRL_RIBBON_TRAVELLER;
                text = sText_MemoryGirlTravellerPrelude;
            }
            else if (GiveMonHistoricRibbon(mon))
            {
                sMemoryGirlReading->ribbon = MEMORY_GIRL_RIBBON_HISTORIC;
                text = sText_MemoryGirlHistoricPrelude;
            }
            else
            {
                text = sText_MemoryGirlGoodMemories;
            }

            if (sMemoryGirlReading->ribbon != MEMORY_GIRL_RIBBON_NONE)
                sMemoryGirlReading->ribbonStage = 1;
            StringCopy(gStringVar4, text);
            return MEMORY_GIRL_READING_DIALOGUE;
        default:
            BufferMemoryGirlNames(mon);
            switch (line)
            {
            case MEMORY_GIRL_LINE_NO_MEMORIES:
                if (sMemoryGirlReading->otherTrainer)
                {
                    StringExpandPlaceholders(gStringVar4, sText_MemoryGirlCaughtByTrainer);
                    StringExpandPlaceholders(gStringVar2, sText_MemoryGirlNoMemoriesOtherOutro);
                    StringAppend(gStringVar4, gStringVar2);
                    return MEMORY_GIRL_READING_DIALOGUE;
                }
                text = sText_MemoryGirlNoMemoriesOwn;
                break;
            case MEMORY_GIRL_LINE_INTRO:
                text = sText_MemoryGirlIntroVariants[sMemoryGirlReading->thenVariant];
                break;
            case MEMORY_GIRL_LINE_REACTION:
                text = sText_MemoryGirlReactionVariants[sMemoryGirlReading->reactionVariant];
                break;
            case MEMORY_GIRL_LINE_THEN_ORIGIN:
                text = sText_MemoryGirlThenVariants[0];
                break;
            case MEMORY_GIRL_LINE_THEN_NEW:
                text = sText_MemoryGirlThenVariants[1];
                break;
            case MEMORY_GIRL_LINE_TRAVELLED:
                text = sText_MemoryGirlTravelled;
                break;
            case MEMORY_GIRL_LINE_ONLY_NEW:
                text = sText_MemoryGirlOnlyNew;
                break;
            default:
                continue;
            }
            StringExpandPlaceholders(gStringVar4, text);
            return MEMORY_GIRL_READING_DIALOGUE;
        }
    }

    return FinishMemoryGirlReading();
}
