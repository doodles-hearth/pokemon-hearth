#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "random.h"
#include "script.h"
#include "constants/event_objects.h"
#include "constants/shamisen_players.h"

#define SHAMISEN_PLAYERS_COUNT 3
#define SHAMISEN_PLAYERS_LOCATIONS_COUNT 6

#define UNDEFINED_LOCATION  0xFF
#define NO_SHAMISEN_PLAYER 0xFF

struct ShamisenPlayer {
    u16 graphicsId;
    u16 var;
    const u8 *script;
};

static const struct ShamisenPlayer sShamisenPlayers[SHAMISEN_PLAYERS_COUNT] = 
{
    {OBJ_EVENT_GFX_SHAMISEN_BLUE,  VAR_SHAMISEN_PLAYER_BLUE,  EventScript_ShamisenPlayerBlue},
    {OBJ_EVENT_GFX_SHAMISEN_RED,   VAR_SHAMISEN_PLAYER_RED,   EventScript_ShamisenPlayerRed},
    {OBJ_EVENT_GFX_SHAMISEN_GREEN, VAR_SHAMISEN_PLAYER_GREEN, EventScript_ShamisenPlayerGreen}
};

static const u16 sShamisenPlayersLocations[SHAMISEN_PLAYERS_LOCATIONS_COUNT][2] =
{
    {MAP_SAKU_TOWN_POKEMON_CENTER, FLAG_VISITED_SAKU_TOWN}, // TODO when refuge is built
    {MAP_MAGURO_HARBOR_REFUGE, FLAG_VISITED_MAGURO_HARBOR},
    {MAP_SILVERIDGE_REFUGE, FLAG_VISITED_SILVERIDGE},
    {MAP_SOULKEEP_REFUGE, FLAG_VISITED_SOULKEEP}, // TODO when soulkeep is freed from ghosts
    {MAP_YIFU_CITY_REFUGE, FLAG_VISITED_YIFU_CITY},
    {MAP_SABERSIDE_TOWN_REFUGE, FLAG_VISITED_SABERSIDE_TOWN},
};
// {MAP_WINDYCAPE_REFUGE, FLAG_VISITED_WINDYCAPE},
// {MAP_HANABI_CITY_REFUGE, FLAG_VISITED_HANABI_CITY},

static u32 GetShamisenPlayerCurrentLocation(u32 index)
{
    u16 varValue = VarGet(sShamisenPlayers[index].var);
    return (varValue >> 8);
}

static bool32 GetShamisenPlayerFlag(u32 index, u32 flagIndex)
{
    u16 varValue = VarGet(sShamisenPlayers[index].var);
    return ((varValue >> flagIndex) & 1);
}

static void SetShamisenPlayerFlag(u32 index, u32 flagIndex, u32 value)
{
    u16 varValue = VarGet(sShamisenPlayers[index].var);
    u16 mask = ~(1 << flagIndex);
    varValue = (varValue & mask) | (value << flagIndex);
    VarSet(sShamisenPlayers[index].var, varValue);
}

static void SetShamisenPlayerLocation(u32 index, u8 location)
{
    u16 varValue = VarGet(sShamisenPlayers[index].var);
    u8 state = varValue & 0xFF;
    varValue = (location << 8) | state;
    VarSet(sShamisenPlayers[index].var, varValue);
}

static u32 IsInShamisenLocation(void)
{
    u32 location = UNDEFINED_LOCATION;
    for (u32 i = 0; i < SHAMISEN_PLAYERS_LOCATIONS_COUNT; i++)
    {
        if (MAP_GROUP(sShamisenPlayersLocations[i][0]) == gSaveBlock1Ptr->location.mapGroup &&
            MAP_NUM(sShamisenPlayersLocations[i][0]) == gSaveBlock1Ptr->location.mapNum)
        {
            location = i;
            break;
        }
    }
    return location;
}

static u32 GetActiveShamisenPlayer(void)
{
    u8 location = IsInShamisenLocation();
    if (location == UNDEFINED_LOCATION)
        return NO_SHAMISEN_PLAYER;
    for (u32 i = 0; i < SHAMISEN_PLAYERS_COUNT; i++)
    {
        u32 shamisenPlayerLocation = GetShamisenPlayerCurrentLocation(i);
        if (location == shamisenPlayerLocation)
            return i;
    }
    return NO_SHAMISEN_PLAYER;
}

static u32 GetPossibleLocations(u32 index, u32 *alreadySet, u32 *possibleLocations)
{
    u32 possibleLocationsCount = 0;
    for (u32 i = 0; i < SHAMISEN_PLAYERS_LOCATIONS_COUNT; i++)
    {
        if (!FlagGet(sShamisenPlayersLocations[i][1]))
            continue;

        if (GetShamisenPlayerCurrentLocation(index) == i)
            continue;

        bool32 alreadySetFlag = FALSE;
        for (u32 j = 0; j < SHAMISEN_PLAYERS_COUNT; j++)
        {
            if (alreadySet[j] == i)
            {
                alreadySetFlag = TRUE;
                break;
            }
        }
        if (alreadySetFlag)
            continue;

        possibleLocations[possibleLocationsCount++] = i;
    }
    for (u32 i = possibleLocationsCount; i < SHAMISEN_PLAYERS_LOCATIONS_COUNT; i++)
        possibleLocations[i] = UNDEFINED_LOCATION;
    return possibleLocationsCount;
}


static void UpdateShamisenPlayersLocations(void)
{
    u32 seed = gSaveBlock1Ptr->dailySeed ^ 0x0C6F200F; // bytes corresponding to しゃみせ(ん is missing) "shamise(n)"
    rng_value_t localRngState = LocalRandomSeed(seed);

    u32 newLocations[SHAMISEN_PLAYERS_COUNT];
    u32 possibleLocations[SHAMISEN_PLAYERS_LOCATIONS_COUNT];
    u32 shuffledShamishenPlayers[SHAMISEN_PLAYERS_COUNT];
    for (u32 i = 0; i < SHAMISEN_PLAYERS_COUNT; i++)
    {
        shuffledShamishenPlayers[i] = i;
        newLocations[i] = UNDEFINED_LOCATION;
    }

    Shuffle32(shuffledShamishenPlayers, 3);
    for (u32 i = 0; i < SHAMISEN_PLAYERS_COUNT; i++)
    {
        u32 shamisenPlayer = shuffledShamishenPlayers[i];
        u32 possibleLocationsCount = GetPossibleLocations(shamisenPlayer, newLocations, possibleLocations);
        if (possibleLocationsCount > 0)
            newLocations[shamisenPlayer] = possibleLocations[LocalRandom32(&localRngState) % possibleLocationsCount];
    }

    for (u32 i = 0; i < SHAMISEN_PLAYERS_COUNT; i++)
        SetShamisenPlayerLocation(i, newLocations[i]);
}

static void UpdateShamisenPlayersTalkedFlag(void)
{
    for (u32 i = 0; i < SHAMISEN_PLAYERS_COUNT; i++)
    {
        if (GetShamisenPlayerFlag(i, SHAMISEN_PLAYER_FLAG_TALKED_TODAY))
            SetShamisenPlayerFlag(i, SHAMISEN_PLAYER_FLAG_TALKED_BEFORE, TRUE);
        SetShamisenPlayerFlag(i, SHAMISEN_PLAYER_FLAG_TALKED_TODAY, FALSE);
    }
}

void UpdateShamisenPlayers(void)
{
    UpdateShamisenPlayersLocations();
    UpdateShamisenPlayersTalkedFlag();
}

void ResetShamisenPlayersNewGame(void)
{
    for (u32 i = 0; i < SHAMISEN_PLAYERS_COUNT; i++)
    {
        VarSet(sShamisenPlayers[i].var, 0xFF00);
    }
}

void SetShamisenPlayersFlags(void)
{
    u8 location = IsInShamisenLocation();
    if (location == UNDEFINED_LOCATION)
        return;

    for (u32 i = 0; i < SHAMISEN_PLAYERS_COUNT; i++)
    {
        u32 shamisenPlayerLocation = GetShamisenPlayerCurrentLocation(i);
        if (location == shamisenPlayerLocation)
        {
            FlagClear(SHAMISEN_PLAYERS_EVENT_FLAG);
            VarSet(VAR_OBJ_GFX_ID_0, sShamisenPlayers[i].graphicsId);
            return;
        }
    }
    FlagSet(SHAMISEN_PLAYERS_EVENT_FLAG);
}

void ScrCmd_getshamisenplayerflag(struct ScriptContext *ctx)
{
    u16 flagIndex = ScriptReadByte(ctx);

    Script_RequestEffects(SCREFF_V1);
    u32 shamisenPlayer = GetActiveShamisenPlayer();
    assertf(shamisenPlayer != NO_SHAMISEN_PLAYER, "tried to get shamisen player flag on map with no shamisen player")
    {
         return;
    }
    gSpecialVar_Result = GetShamisenPlayerFlag(shamisenPlayer, flagIndex);
}

void ScrCmd_setshamisenplayerflag(struct ScriptContext *ctx)
{
    u32 flagIndex = ScriptReadByte(ctx);
    bool32 value = ScriptReadByte(ctx);

    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);
    u32 shamisenPlayer = GetActiveShamisenPlayer();
    assertf(shamisenPlayer != NO_SHAMISEN_PLAYER, "tried to get shamisen player flag on map with no shamisen player")
    {
         return;
    }
    SetShamisenPlayerFlag(shamisenPlayer, flagIndex, value);
}

void StartShamisenPlayerScript(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);
    u32 shamisenPlayer = GetActiveShamisenPlayer();
    assertf(shamisenPlayer != NO_SHAMISEN_PLAYER, "tried to start shamisen script on map with no shamisen player")
    {
         return;
    }
    ScriptJump(ctx, sShamisenPlayers[shamisenPlayer].script);
}
