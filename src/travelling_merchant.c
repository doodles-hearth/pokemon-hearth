#include "global.h"
#include "event_data.h"
#include "event_scripts.h"
#include "load_save.h"
#include "random.h"
#include "script.h"
#include "constants/event_objects.h"
#include "constants/region_map_sections.h"
#include "constants/travelling_merchant.h"

#define TRAVELLING_MERCHANT_LOCATIONS_COUNT     10
#define TRAVELLING_MERCHANT_UNDEFINED_LOCATION  0xFF

static const u16 sTravellingMerchantLocations[TRAVELLING_MERCHANT_LOCATIONS_COUNT][2] =
{
    {MAP_TRANQUIL_ROUTE, FLAG_BADGE01_GET},
    {MAP_BEACHBOUND_ROUTE, FLAG_CURED_DECAY_HARVEST_SHRINE},
    {MAP_WHITESLATE_ROUTE, FLAG_BADGE02_GET},
    {MAP_WINDSWEPT_ROUTE, FLAG_BADGE03_GET},
    {MAP_SCENIC_ROUTE, FLAG_BADGE03_GET},
    {MAP_ORCHARD_PATH, FLAG_BADGE03_GET},
    {MAP_BURNFOOT_PASS_BOTTOM, FLAG_BADGE03_GET},
    {MAP_PUDDLE_PATH, FLAG_BADGE04_GET},
    {MAP_BURNFOOT_PASS, FLAG_BADGE05_GET},
    {MAP_DRAGONS_PASS, FLAG_BADGE07_GET}
};

void UpdateTravellingMerchantLocation(void)
{
    if (!FlagGet(FLAG_MET_TRAVELLING_MERCHANT)) {
        return;
    }

    rng_value_t localRngState = LocalRandomSeed(gSaveBlock1Ptr->dailySeed ^ TRAVELLING_MERCHANT_SEED_MODIFIER);

    u32 newLocation = TRAVELLING_MERCHANT_UNDEFINED_LOCATION;
    
    // Keeping only allowed locations
    u32 allowedLocations[TRAVELLING_MERCHANT_LOCATIONS_COUNT];
    u32 allowedLocationsCount = 0;
    for (u32 i = 0; i < TRAVELLING_MERCHANT_LOCATIONS_COUNT; i++)
    {
        if
        (
            FlagGet(sTravellingMerchantLocations[i][1]) &&
            // Can't have the same location twice in a row
            i != gSaveBlock1Ptr->travellingMerchantLocation
        ) {
            allowedLocations[allowedLocationsCount++] = i;
        }
    }

    for (u32 i = allowedLocationsCount; i < TRAVELLING_MERCHANT_LOCATIONS_COUNT; i++)
    {
        allowedLocations[i] = TRAVELLING_MERCHANT_UNDEFINED_LOCATION;
    }

    // Picking a random allowed location
    if (allowedLocationsCount > 0)
    {
        newLocation = allowedLocations[LocalRandom32(&localRngState) % allowedLocationsCount];
    }

    gSaveBlock1Ptr->travellingMerchantLocation = newLocation;
}

static u32 GetPlayerLocationIfIsAllowedMerchantLocation(void)
{
    u32 playerLocation = TRAVELLING_MERCHANT_UNDEFINED_LOCATION;
    for (u32 i = 0; i < TRAVELLING_MERCHANT_LOCATIONS_COUNT; i++)
    {
        if
        (
            sTravellingMerchantLocations[i][1] && // Only allowed locations
            MAP_GROUP(sTravellingMerchantLocations[i][0]) == gSaveBlock1Ptr->location.mapGroup &&
            MAP_NUM(sTravellingMerchantLocations[i][0]) == gSaveBlock1Ptr->location.mapNum
        )
        {
            playerLocation = i;
            break;
        }
    }
    return playerLocation;
}

void UpdateTravellingMerchantFlag(void)
{
    u32 playerLocation = GetPlayerLocationIfIsAllowedMerchantLocation();
    if (playerLocation == TRAVELLING_MERCHANT_UNDEFINED_LOCATION)
        return;

    if (playerLocation == gSaveBlock1Ptr->travellingMerchantLocation)
    {
        FlagClear(TRAVELLING_MERCHANT_EVENT_FLAG);
        return;
    }

    FlagSet(TRAVELLING_MERCHANT_EVENT_FLAG);
}

void ReSetTravellingMerchantNewGame(void)
{
    gSaveBlock1Ptr->travellingMerchantLocation = TRAVELLING_MERCHANT_UNDEFINED_LOCATION;
}