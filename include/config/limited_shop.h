#ifndef GUARD_CONFIG_LIMITED_SHOP_H
#define GUARD_CONFIG_LIMITED_SHOP_H

#define LIMITED_SHOP_COUNT 4
#define LIMITED_SHOP_MAX_ITEMS 8
#define BITS_PER_ITEM 4 // The number of bits set aside for each item.
                        // This means the maximum stock of each item can only be equal to
                        // the maximum value capable of being stored in that many bits.
                        // 1 bit = 1 item
                        // 2 bits = 3 items
                        // 4 bits = 15 items
                        // 8 bits = 255 items

#endif // GUARD_CONFIG_LIMITED_SHOP_H