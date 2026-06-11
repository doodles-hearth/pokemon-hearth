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
    [LIMITED_SHOP_2] = 
    {
        {ITEM_POTION, UNLIMITED},
        {ITEM_HYPER_POTION, 15},
        {ITEM_MAX_POTION, 5},
        {ITEM_ESCAPE_ROPE, 5},
        {ITEM_FULL_HEAL, 10},
        {ITEM_REVIVE, 5},
        {ITEM_REPEL, 15},
        {ITEM_SUPER_REPEL, 10},
        {ITEM_NONE, UNLIMITED},
    },
};

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

const struct LimitedShopItems gTravellingMerchantRareItemsLocation[LAYOUT_SILVER_TUNNEL_3F][LIMITED_SHOP_MAX_ITEMS + 1] = {
    /*gMapHeader.mapLayoutId*/
    [LAYOUT_BURNFOOT_PASS_BOTTOM] = 
    {
        {ITEM_LAVA_COOKIE, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [LAYOUT_TRANQUIL_ROUTE] = 
    {
        {ITEM_NEST_BALL, 5},
        {ITEM_NONE, UNLIMITED},
    },
};

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
        {ITEM_SUPERGIRI, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [2] = 
    { 
        {ITEM_GREAT_BALL, 5},
        {ITEM_REVIVAL_BALM, 2},
        {ITEM_NONE, UNLIMITED},
    },
    [3] = 
    {
        {ITEM_REVIVAL_HERB, 2},
        {ITEM_HYPERGIRI, 1},
        {ITEM_NONE, UNLIMITED},
    },
    [4] = 
    {
        {ITEM_ULTRA_BALL, 3},
        {ITEM_NONE, UNLIMITED},
    },
    [5] = 
    { 
        {ITEM_NONE, UNLIMITED},
    },
    [6] = 
    { 
        {ITEM_NONE, UNLIMITED},
    },
    [7] = 
    { 
        {ITEM_NONE, UNLIMITED},
    },
    [8] = 
    {
        {ITEM_NONE, UNLIMITED},
    },
    [9] = /*Is champion = 9*/
    {
        {ITEM_NONE, UNLIMITED},
    },
};

#undef UNLIMITED
