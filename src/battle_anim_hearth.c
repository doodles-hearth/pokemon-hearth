#include "global.h"
#include "battle_anim.h"

static const union AnimCmd sLeafAnim[] =
{
    ANIMCMD_FRAME(0,  4),
    ANIMCMD_FRAME(4,  4),
    ANIMCMD_FRAME(8,  4),
    ANIMCMD_FRAME(12, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(20, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_FRAME(28, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd* const sBlossomAnimTable[] = {sLeafAnim};

const struct SpriteTemplate gFallingLeavesSpriteTemplate =
{
    .tileTag = ANIM_TAG_LEAF,
    .paletteTag = ANIM_TAG_LEAF,
    .oam = &gOamData_AffineOff_ObjNormal_16x16,
    .anims = sBlossomAnimTable,
    .callback = AnimFlyingLeaves,
};

// Animates the leaves that fly diagonally across the screen

#define sState       data[0]
#define sVelocityX   data[1] // 256ths of a pixel // init'd from gBattleAnimArgs[1]
#define sVelocityY   data[2] // 256ths of a pixel // init'd from gBattleAnimArgs[2]
#define sFractionalX data[3] // 256ths of a pixel
#define sFractionalY data[4] // 256ths of a pixel

// The fields named "velocity" are arguably more like "acceleration,"
// and the fields named "fractional" are arguably more like "velocity."
//
// ...is what I WOULD say if the "fractional" fields weren't AND'd with
// 0xFF after every frame.

void AnimFlyingLeaves(struct Sprite *sprite)
{
    if (sprite->sState == 0)
    {
        sprite->x = DISPLAY_WIDTH + 64;
        gBattleAnimArgs[1] = -gBattleAnimArgs[1];
        sprite->oam.affineMode = ST_OAM_AFFINE_NORMAL;
        sprite->affineAnimPaused = FALSE;

        sprite->y = gBattleAnimArgs[0];
        sprite->sVelocityX = gBattleAnimArgs[1];
        sprite->sVelocityY = gBattleAnimArgs[2];
        sprite->sState++;
    }
    else
    {
        sprite->sFractionalX += sprite->sVelocityX;
        sprite->sFractionalY += sprite->sVelocityY;
        sprite->x2 += (sprite->sFractionalX >> 8);
        sprite->y2 += (sprite->sFractionalY >> 8);
        sprite->sFractionalX &= 0xFF;
        sprite->sFractionalY &= 0xFF;

        if (sprite->x + sprite->x2 < -32)
        {
            sprite->callback = DestroyAnimSprite;
        }
    }
}

#undef sState
#undef sVelocityX
#undef sVelocityY
#undef sFractionalX
#undef sFractionalY
#undef sMirroredX
