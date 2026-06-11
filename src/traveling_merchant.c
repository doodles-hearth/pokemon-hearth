
// TODO EVA ICI
static void UpdateTravelingMerchantLocation(void)
{
    u32 seed = gSaveBlock1Ptr->dailySeed ^ 0xE59586E4;
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