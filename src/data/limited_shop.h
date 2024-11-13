#include "config/limited_shop.h"
#include "constants/limited_shop.h"
#include "constants/items.h"

struct LimitedShopItems
{
    u16 items;
    u16 quantity;
};

const struct LimitedShopItems gLimitedShops[LIMITED_SHOP_COUNT][LIMITED_SHOP_MAX_ITEMS] =
{
    [LIMITED_SHOP_1] = 
    {
        {ITEM_GREAT_BALL, 0},
        {ITEM_ULTRA_BALL, 0},
        {ITEM_SUPER_POTION, 0},
        {ITEM_HYPER_POTION, 15},
        {ITEM_ANTIDOTE, 10},
        {ITEM_PARALYZE_HEAL, 10},
        {ITEM_AWAKENING, 10},
        {ITEM_REVIVE, 5},
        {ITEM_SUPER_REPEL, 5},
        {ITEM_WOOD_MAIL, 1},
        {ITEM_NONE, 0}
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
        {ITEM_MAX_REPEL, 5},
        {ITEM_NONE, 0}
    },
};
