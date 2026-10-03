#include "config/limited_shop.h"
#include "constants/limited_shop.h"
#include "constants/items.h"
#include "constants/layouts.h"

#define UNLIMITED 0

struct LimitedShopItems
{
    const u16 item;
    const u16 quantity;
};

const struct LimitedShopItems gLimitedShops[LIMITED_SHOP_COUNT][LIMITED_SHOP_MAX_ITEMS + 1] =
{
    [TRAVELLING_SHOP_FIRST_TIME] = 
    {
        {ITEM_GREAT_BALL, 3},
        {ITEM_SUPER_OINTMENT, 5},
        {ITEM_REVIVAL_BALM, 3},
        {ITEM_UUMEGIRI, 2},
        {ITEM_TM_AERIAL_ACE, 1},
        {ITEM_NONE, UNLIMITED},
    },
};

// =========================================
// === TRAVELING MERCHANT'S LIMITED SHOP ===
// =========================================

// Items specific to a location
const struct LimitedShopItems gTravellingMerchantLocation[LAYOUT_SILVER_TUNNEL_3F][LIMITED_SHOP_MAX_ITEMS + 1] = {
    /*gMapHeader.mapLayoutId*/
    [LAYOUT_BURNFOOT_PASS_BOTTOM] = 
    {
        {ITEM_LAVA_COOKIE, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [LAYOUT_WHITESLATE_ROUTE] = 
    { 
        {ITEM_LUM_BERRY, 3},
        {ITEM_NONE, UNLIMITED},
    },
    [LAYOUT_SCENIC_ROUTE] = 
    { 
        {ITEM_FISHCAKE, 2},
        {ITEM_NONE, UNLIMITED},
    },
};

// Rare items (only present at random some of the time) specific to a location
const struct LimitedShopItems gTravellingMerchantRareItemsLocation[LAYOUT_SILVER_TUNNEL_3F][LIMITED_SHOP_MAX_ITEMS + 1] = {
    /*gMapHeader.mapLayoutId*/
    [LAYOUT_TRANQUIL_ROUTE] = 
    {
        {ITEM_NEST_BALL, 5},
        {ITEM_NONE, UNLIMITED},
    },
    [LAYOUT_BEACHBOUND_ROUTE] = 
    {
        {ITEM_WATER_STONE, 1},
        {ITEM_NONE, UNLIMITED},
    },
    [LAYOUT_BURNFOOT_PASS] = 
    {
        {ITEM_TM_FLAMETHROWER, 1},
        {ITEM_MAGMARIZER, 1},
        {ITEM_NONE, UNLIMITED},
    },
    [LAYOUT_WINDSWEPT_ROUTE] = 
    {
        {ITEM_THUNDER_STONE, 1},
        {ITEM_NONE, UNLIMITED},
    },
    [LAYOUT_ORCHARD_PATH] = 
    {
        {ITEM_TM_SHADOW_BALL, 1},
        {ITEM_NONE, UNLIMITED},
    },
};

// Items per number of badges obtained
const struct LimitedShopItems gTravellingMerchantProgression[NUM_BADGES + 2][LIMITED_SHOP_MAX_ITEMS + 1] = {
    /*Badges obtained*/
    [0] = 
    {
        {ITEM_POKE_BALL, 5},
        {ITEM_UUMEGIRI, 2},
        {ITEM_REVIVAL_POWDER, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [1] = 
    { 
        {ITEM_POKE_BALL, 5},
        {ITEM_UUMEGIRI, 2},
        {ITEM_REVIVAL_POWDER, 2},
        {ITEM_SUPERGIRI, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [2] = 
    {   {ITEM_POKE_BALL, 5},
        {ITEM_GREAT_BALL, 5},
        {ITEM_UUMEGIRI, 2},
        {ITEM_SUPERGIRI, 2},
        {ITEM_REVIVAL_POWDER, 2},
        {ITEM_REVIVAL_BALM, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [3] = 
    {
        {ITEM_GREAT_BALL, 5},
        {ITEM_SUPERGIRI, 2},
        {ITEM_HYPERGIRI, 1},
        {ITEM_REVIVAL_BALM, 2},
        {ITEM_REVIVAL_HERB, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [4] = 
    {
        {ITEM_GREAT_BALL, 5},
        {ITEM_ULTRA_BALL, 3},
        {ITEM_HYPERGIRI, 1},
        {ITEM_REVIVAL_BALM, 2},
        {ITEM_REVIVAL_HERB, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [5] = 
    {
        {ITEM_GREAT_BALL, 5},
        {ITEM_ULTRA_BALL, 3},
        {ITEM_HYPERGIRI, 1},
        {ITEM_REVIVAL_BALM, 2},
        {ITEM_REVIVAL_HERB, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [6] = 
    {
        {ITEM_GREAT_BALL, 5},
        {ITEM_ULTRA_BALL, 3},
        {ITEM_HYPERGIRI, 1},
        {ITEM_REVIVAL_BALM, 2},
        {ITEM_REVIVAL_HERB, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [7] = 
    {
        {ITEM_GREAT_BALL, 5},
        {ITEM_ULTRA_BALL, 3},
        {ITEM_HYPERGIRI, 1},
        {ITEM_REVIVAL_BALM, 2},
        {ITEM_REVIVAL_HERB, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [8] = 
    {
        {ITEM_GREAT_BALL, 5},
        {ITEM_ULTRA_BALL, 3},
        {ITEM_HYPERGIRI, 1},
        {ITEM_REVIVAL_BALM, 2},
        {ITEM_REVIVAL_HERB, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [9] = /*Is champion = 9*/
    {
        {ITEM_GREAT_BALL, 5},
        {ITEM_ULTRA_BALL, 3},
        {ITEM_SUPERGIRI, 2},
        {ITEM_HYPERGIRI, 1},
        {ITEM_REVIVAL_BALM, 2},
        {ITEM_REVIVAL_HERB, 2},
        {ITEM_NONE, UNLIMITED},
    },
};

#undef UNLIMITED
