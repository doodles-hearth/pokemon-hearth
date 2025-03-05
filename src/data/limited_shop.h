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
    [LIMITED_SHOP_1] = 
    {
        {ITEM_GREAT_BALL, 5},
        {ITEM_SUPER_OINTMENT, 5},
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
    [LAYOUT_SUNRISE_VILLAGE] = 
    {
        {ITEM_POKE_BALL, 10},
        {ITEM_NONE, UNLIMITED},
    },
    [LAYOUT_GINKO_WOODS] = 
    { 
        {ITEM_GREAT_BALL, 6},
        {ITEM_NONE, UNLIMITED},
    },
};

const struct LimitedShopItems gTravellingMerchantProgression[NUM_BADGES + 2][LIMITED_SHOP_MAX_ITEMS + 1] = {
    /*Badges obtained*/
    [0] = 
    { 
        {ITEM_POTION, 10},
        {ITEM_NONE, UNLIMITED},
    },
    [1] = 
    { 
        {ITEM_SUPER_POTION, 8},
        {ITEM_NONE, UNLIMITED},
    },
    [2] = 
    { 
        {ITEM_HYPER_POTION, 6},
        {ITEM_NONE, UNLIMITED},
    },
    [3] = 
    { 
        {ITEM_HYPER_POTION, 8},
        {ITEM_NONE, UNLIMITED},
    },
    [4] = 
    { 
        {ITEM_HYPER_POTION, 10},
        {ITEM_NONE, UNLIMITED},
    },
    [5] = 
    { 
        {ITEM_MAX_POTION, 8},
        {ITEM_NONE, UNLIMITED},
    },
    [6] = 
    { 
        {ITEM_MAX_POTION, 10},
        {ITEM_NONE, UNLIMITED},
    },
    [7] = 
    { 
        {ITEM_MAX_POTION, 10},
        {ITEM_NONE, UNLIMITED},
    },
    [8] = 
    { 
        {ITEM_FULL_RESTORE, 10},
        {ITEM_NONE, UNLIMITED},
    },
    [9] = /*Is champion = 9*/
    { 
        {ITEM_FULL_RESTORE, 10},
        {ITEM_NONE, UNLIMITED},
    },
};

#undef UNLIMITED
