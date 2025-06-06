/* #include "global.h"
#include "event_data.h"
#include "fish_seller.h"
#include "random.h"
#include "script.h"

static struct FishMon GetAcceptedFish(u32 species)
{
    u32 nbFish = ARRAY_COUNT(sAcceptedFish);
    for (u32 i = 0; i < nbFish; i += 1)
    {
        if (sAcceptedFish[i].species == species)
        {
            return sAcceptedFish[i];
        }
    }
    return sAcceptedFish[nbFish - 1];
}

static u32 GetFishPrice(struct FishMon acceptedFish)
{
    switch (acceptedFish.rarity)
    {
        case FISH_RARITY_COMMON:
            return PRICE_FISH_COMMON;
        case FISH_RARITY_UNCOMMON:
            return PRICE_FISH_UNCOMMON;
        case FISH_RARITY_RARE:
            return PRICE_FISH_RARE;
        case FISH_RARITY_RARE_AS_FUCK:
        default:
            return PRICE_FISH_RARE_AS_FUCK;
    }
}

static u32 GetFoundTreasure(struct FishMon acceptedFish)
{
    if (Random() % TREASURE_ODDS == 0)
    {
        // The rarer the fish, the more treasure pools
        u32 treasureRarity = Random() % (acceptedFish.rarity + 1);
        u32 randomTreasureSlot = Random() % TREASURE_PER_RARITY_COUNT;
        return sfoundTreasures[treasureRarity][randomTreasureSlot];
    }
    return ITEM_NONE;
}

void Native_GiveFish(struct ScriptContext *ctx)
{
    Script_RequestEffects(SCREFF_V1);

    u32 species = GetMonData(&gPlayerParty[VarGet(VAR_0x8004)], MON_DATA_SPECIES);
    struct FishMon acceptedFish = GetAcceptedFish(species);
    u32 price = 0;
    u32 treasure = ITEM_NONE;
    if (acceptedFish.species != SPECIES_NONE)
    {
        price = GetFishPrice(acceptedFish);
        treasure = GetFoundTreasure(acceptedFish);
    }
    VarSet(VAR_0x8000, price);
    VarSet(VAR_0x8001, treasure);
} */
