#include "config/limited_shop.h"
#include "constants/limited_shop.h"
#include "constants/items.h"

struct LimitedShopItems
{
    const u16 item;
    const u16 quantity;
};

const struct LimitedShopItems gLimitedShops[LIMITED_SHOP_COUNT][LIMITED_SHOP_MAX_ITEMS + 1] =
{
    [LIMITED_SHOP_1] = 
    {
        {ITEM_GREAT_BALL, 3},
        {ITEM_SUPER_OINTMENT, 5},
        {ITEM_UUMEGIRI, 2},
        {ITEM_TM_AERIAL_ACE, 1},
        {ITEM_NONE, 0},
    },
    [LIMITED_SHOP_2] = 
    {
        {ITEM_POTION, 0},
        {ITEM_HYPER_POTION, 15},
        {ITEM_MAX_POTION, 5},
        {ITEM_ESCAPE_ROPE, 5},
        {ITEM_FULL_HEAL, 10},
        {ITEM_REVIVE, 5},
        {ITEM_REPEL, 15},
        {ITEM_SUPER_REPEL, 10},
        {ITEM_NONE, 0},
    },
};
