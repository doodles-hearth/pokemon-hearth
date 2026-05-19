#include "global.h"
#include "event_data.h"
#include "random.h"

#define SHAMISHEN_PLAYERS_COUNT 3
#define SHAMISHEN_PLAYERS_LOCATIONS_COUNT 3

static const u16 sShamishenPlayersVar[SHAMISHEN_PLAYERS_COUNT] =
{
    VAR_SHAMISHEN_PLAYER_BLUE,
    VAR_SHAMISHEN_PLAYER_RED,
    VAR_SHAMISHEN_PLAYER_GREEN
};

static const u16 sShamishenPlayersEventsFlag[SHAMISHEN_PLAYERS_COUNT] =
{
    FLAG_TEMP_1D,
    FLAG_TEMP_1E,
    FLAG_TEMP_1F
};

static const u16 sShamishenPlayersLocations[SHAMISHEN_PLAYERS_LOCATIONS_COUNT][2] =
{
    {MAP_CHII_TOWN_POKEMON_CENTER, FLAG_VISITED_CHII_TOWN},
    {MAP_SAKU_TOWN_POKEMON_CENTER, FLAG_VISITED_SAKU_TOWN},
    {MAP_MAGURO_HARBOR_REFUGE, FLAG_VISITED_MAGURO_HARBOR}
};

static s8 GetShamishenPlayerCurrentLocation(u32 index)
{
    s16 varValue = VarGet(sShamishenPlayersVar[index]);
    return (varValue >> 8);
}

static void SetShamishenPlayerLocation(u32 index, s8 location)
{
    s16 varValue = VarGet(sShamishenPlayersVar[index]);
    u8 state = varValue & 0xFF;
    s16 newValue = (location << 8) | state;
    VarSet(sShamishenPlayersVar[index], newValue);
}

static u32 GetPossibleLocations(u32 index, s8 *alreadySet, s8 *possibleLocations)
{
    u32 possibleLocationsCount = 0;
    for (u32 i = 0; i < SHAMISHEN_PLAYERS_LOCATIONS_COUNT; i++)
    {
        if (!FlagGet(sShamishenPlayersLocations[i][1]))
            continue;

        if (GetShamishenPlayerCurrentLocation(index) == i)
            continue;

        bool32 alreadySetFlag = FALSE;
        for (u32 j = 0; j < SHAMISHEN_PLAYERS_COUNT; j++)
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
    for (u32 i = possibleLocationsCount; i < SHAMISHEN_PLAYERS_LOCATIONS_COUNT; i++)
        possibleLocations[i] = -1;
    return possibleLocationsCount;
}

void UpdateShamishenPlayersLocations(void)
{
    u32 seed = gSaveBlock1Ptr->dailySeed ^ 0x0C6F200F; // bytes corresponding to しゃみせ(ん is missing) "shamishe(n)"
    rng_value_t localRngState = LocalRandomSeed(seed);

    s8 newLocations[SHAMISHEN_PLAYERS_COUNT];
    s8 possibleLocations[SHAMISHEN_PLAYERS_LOCATIONS_COUNT];

    for (u32 i = 0; i < SHAMISHEN_PLAYERS_COUNT; i++)
        newLocations[i] = -1;

    for (u32 i = 0; i < SHAMISHEN_PLAYERS_COUNT; i++)
    {
        u32 possibleLocationsCount = GetPossibleLocations(i, newLocations, possibleLocations);
        if (possibleLocationsCount == 0)
            newLocations[i] = -1;
        newLocations[i] = possibleLocations[LocalRandom32(&localRngState) % possibleLocationsCount];
    }

    for (u32 i = 0; i < SHAMISHEN_PLAYERS_COUNT; i++)
        SetShamishenPlayerLocation(i, newLocations[i]);
}

void SetShamishenPlayersFlags(u32 mapGroup, u32 mapNum)
{
    s8 location = -1;
    for (u32 i = 0; i < SHAMISHEN_PLAYERS_LOCATIONS_COUNT; i++)
    {
        if (MAP_GROUP(sShamishenPlayersLocations[i][0]) == mapGroup && MAP_NUM(sShamishenPlayersLocations[i][0]) == mapNum)
        {
            location = i;
            break;
        }
    }

    if (location == -1)
        return;

    for (u32 i = 0; i < SHAMISHEN_PLAYERS_COUNT; i++)
    {
        s8 location = GetShamishenPlayerCurrentLocation(i);
        if (location == i)
            FlagSet(sShamishenPlayersEventsFlag[i]);
        else
            FlagClear(sShamishenPlayersEventsFlag[i]);
    }
}
