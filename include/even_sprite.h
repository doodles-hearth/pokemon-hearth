#ifndef GUARD_EVEN_SPRITE_H
#define GUARD_EVEN_SPRITE_H

#include "gba/types.h"
#include "sprite.h"

struct Even_CreateSpriteStruct {
    const u32* sprite;
    const u16* palette;
    u16 tileTag;
    u16 palTag;
    s16 posX;
    s16 posY;
    bool8 spriteCompressed;
    u8 subpriority;
    u8 spriteShape : 2;
    u8 spriteSize : 2;
    SpriteCallback callback;
};

u32 Even_CreateSprite(struct Even_CreateSpriteStruct* createStruct);
u32 Even_CreateSpriteParametrized(const u32* sprite, u16 tileTag, const u16* palette, u16 palTag, u8 size, u8 shape,
                                  s16 x, s16 y, u8 subpriority, SpriteCallback callback, bool32 spriteCompressed);

void TestDrawSprite(void);

#endif
