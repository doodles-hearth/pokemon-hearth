#include "global.h"
#include "assertf.h"
#include "even_live_event.h"
#include "even_live_funcs.h"
#include "even_sprite.h"
#include "event_object_movement.h"
#include "line_break.h"
#include "malloc.h"
#include "script.h"
#include "string_util.h"
#include "text.h"
#include "event_scripts.h"
#include "object_event_graphics.h"

#include "constants/even_live_event.h"
#include "constants/event_objects.h"
#include "constants/eventide_gfx_tags.h"

#define LIVE_TEXT_SPEED 0

EWRAM_DATA u64 sHasTriggered;
EWRAM_DATA u32 sRetriggerDelays[64];
EWRAM_DATA struct ActiveLiveEvent sActiveLiveEvents[64] = {0};
EWRAM_DATA bool8 sAnySpeechBubbleIsActive = FALSE;

const u32 sSpeechBubbleTiles[] = INCBIN_U32("graphics/live_event/speech_bubble_tiles.4bpp");

#include "data/even_live_event.h"
#include "object_event_graphics.h"

static u32 GetStringLines(const u8 *str)
{
    u32 lines = 1;
    u32 currChar = 0;
    while (str[currChar] != EOS)
    {
        if (str[currChar] == CHAR_NEWLINE)
            lines++;
        currChar++;
    }
    return lines;
}

u32 *BuildSpeechBubble(u32 width, u32 lines, enum StartingSide side)
{
    assertf(lines < 4, "Too many lines in string")
    {
        lines = 3;
    }
    u32 tilesX;
    u32 remainder = (width - 10) % 8;
    if (width <= 10)
        tilesX = 2;
    else
        tilesX = 2 + (width - 10) / 8 + ((remainder != 0) ? 1 : 0);

    u32 *sprite;
    if (tilesX > 8)
    {
        u32 edgePixels = width - ((tilesX - 2) * 8 + 5);
        if (width < ((tilesX - 2) * 8 + 5))
            edgePixels = 0;

        sprite = AllocZeroed(2048); // 2 sprites
        switch (side)
        {
        case AUTOMATIC_START:
        case LEFT_START:
            {
            //  Draw entire left sprite first
                u32 currY = 3;
                u32 currX = 1;
              //  Draw bottom section
                //  Draw left corner, with arrow
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + i] = sSpeechBubbleTiles[9 * 8 + i];
                //  Draw middle section
                for (; currX < 8; currX++)
                {
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[7 * 8 + i];
                }
                currY--;

              //  Draw middle middle section
                for (; currY > 3 - lines; currY--)
                {
                    //  Left edge
                    currX = 1;
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + i] = sSpeechBubbleTiles[3 * 8 + i];

                    //  Middle
                    for (; currX < 8; currX++)
                    {
                        for (u32 i = 0; i < 8; i++)
                            sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[5 * 8 + i];
                    }
                }
              //  Draw the top section
                //  Draw left corner
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + i] = sSpeechBubbleTiles[i];
                //  Draw middle section
                currX = 1;
                for (; currX < 8; currX++)
                {
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[8 + i];
                }

            //  Draw right sprite
                u32 *spriteRight = &sprite[64 * 32 / 8];
                currX = 0;
                currY = 3;
                //  Draw middle part
                for (; currX < tilesX - 9; currX++)
                {
                    for (u32 i = 0; i < 8; i++)
                        spriteRight[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[7 * 8 + i];
                }
                u32 tileOffset;
                switch (edgePixels)
                {
                case 0:
                    tileOffset = 23;
                    break;
                case 1:
                    tileOffset = 22;
                    break;
                case 2:
                    tileOffset = 21;
                    break;
                case 3:
                    tileOffset = 20;
                    break;
                case 4:
                    tileOffset = 19;
                    break;
                case 5:
                    tileOffset = 18;
                    break;
                default:
                    tileOffset = 8;
                    break;
                }

                for (u32 i = 0; i < 8; i++)
                    spriteRight[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];

                currY--;
            //  Middle
                switch (edgePixels)
                {
                case 0:
                    tileOffset = 41;
                    break;
                case 1:
                    tileOffset = 40;
                    break;
                case 2:
                    tileOffset = 39;
                    break;
                case 3:
                    tileOffset = 38;
                    break;
                case 4:
                    tileOffset = 37;
                    break;
                case 5:
                    tileOffset = 36;
                    break;
                default:
                    tileOffset = 4;
                    break;
                }
                for (; currY > 3 - lines; currY--)
                {
                    currX = 0;

                    //  Middle
                    for (; currX < tilesX - 9; currX++)
                    {
                        for (u32 i = 0; i < 8; i++)
                            spriteRight[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[5 * 8 + i];
                    }
                    //  Right edge
                    for (u32 i = 0; i < 8; i++)
                        spriteRight[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
                }
            //  Top
                //  Middle
                currX = 0;
                for (; currX < tilesX - 9; currX++)
                {
                    for (u32 i = 0; i < 8; i++)
                        spriteRight[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[8 + i];
                }
                //  Draw right corner
                switch (edgePixels)
                {
                case 0:
                    tileOffset = 17;
                    break;
                case 1:
                    tileOffset = 16;
                    break;
                case 2:
                    tileOffset = 15;
                    break;
                case 3:
                    tileOffset = 14;
                    break;
                case 4:
                    tileOffset = 13;
                    break;
                case 5:
                    tileOffset = 12;
                    break;
                default:
                    tileOffset = 2;
                    break;
                }
                for (u32 i = 0; i < 8; i++)
                    spriteRight[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
            }
            break;
        case RIGHT_START:
            //  Draw entire right sprite first
            {
                u32 currY = 3;
                s32 currX = 6;
                //  Bottom right corner
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + 7 * 8 + i] = sSpeechBubbleTiles[10 * 8 + i];
                //  Bottom middle part
                for (; currX >= 0; currX--)
                {
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[7 * 8 + i];
                }
                currY--;
                //  Middlt right edges and middle
                for (; currY > 3 - lines; currY--)
                {
                    //  Right Edge
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + 7 * 8 + i] = sSpeechBubbleTiles[4 * 8 + i];
                    //  Centre
                    for (currX = 6; currX >= 0; currX--)
                    {
                        for (u32 i = 0; i < 8; i++)
                            sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[5 * 8 + i];
                    }
                }
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + 7 * 8 + i] = sSpeechBubbleTiles[2 * 8 + i];
                for (currX = 6; currX >= 0; currX--)
                {
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[1 * 8 + i];
                }
            //  Left sprite
                u32 *spriteLeft = &sprite[64 * 32 / 8];
                currY = 3;
                currX = 7;
                //  Bottom middle
                for (; currX > 16 - tilesX; currX--)
                {
                    for (u32 i = 0; i < 8; i++)
                        spriteLeft[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[7 * 8 + i];
                }
                u32 tileOffset;
                switch (edgePixels)
                {
                case 0:
                    tileOffset = 35;
                    break;
                case 1:
                    tileOffset = 34;
                    break;
                case 2:
                    tileOffset = 33;
                    break;
                case 3:
                    tileOffset = 32;
                    break;
                case 4:
                    tileOffset = 31;
                    break;
                case 5:
                    tileOffset = 30;
                    break;
                default:
                    tileOffset = 6;
                    break;
                }
                //  Bottom left part
                for (u32 i = 0; i < 8; i++)
                    spriteLeft[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
              //  Middle rows
                currY--;
                for (; currY > 3 - lines; currY--)
                {
                    for (currX = 7; currX > 16 - tilesX; currX--)
                    {
                        for (u32 i = 0; i < 8; i++)
                            spriteLeft[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[5 * 8 + i];
                    }
                    //  Left edge
                    switch (edgePixels)
                    {
                    case 0:
                        tileOffset = 47;
                        break;
                    case 1:
                        tileOffset = 46;
                        break;
                    case 2:
                        tileOffset = 45;
                        break;
                    case 3:
                        tileOffset = 44;
                        break;
                    case 4:
                        tileOffset = 43;
                        break;
                    case 5:
                        tileOffset = 42;
                        break;
                    default:
                        tileOffset = 3;
                        break;
                    }
                    for (u32 i = 0; i < 8; i++)
                        spriteLeft[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
                }
              //  Top edge
                for (currX = 7; currX > 16 - tilesX; currX--)
                {
                    for (u32 i = 0; i < 8; i++)
                        spriteLeft[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[1 * 8 + i];
                }
              //  Top left corner
                switch (edgePixels)
                {
                case 0:
                    tileOffset = 29;
                    break;
                case 1:
                    tileOffset = 28;
                    break;
                case 2:
                    tileOffset = 27;
                    break;
                case 3:
                    tileOffset = 26;
                    break;
                case 4:
                    tileOffset = 25;
                    break;
                case 5:
                    tileOffset = 24;
                    break;
                default:
                    tileOffset = 0;
                    break;
                }
                for (u32 i = 0; i < 8; i++)
                    spriteLeft[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
            }
            break;
        }
    }
    else
    {
        u32 edgePixels = width - ((tilesX - 2) * 8 + 5);
        sprite = AllocZeroed(1024); // 1 sprite
        switch (side)
        {
        case AUTOMATIC_START:
        case LEFT_START:
            {
                u32 currY = 3;
                u32 currX = 1;
                //  Draw bottom section
                //  Draw left corner, with arrow
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + i] = sSpeechBubbleTiles[9 * 8 + i];
                //  Draw middle section
                for (; currX < tilesX - 1; currX++)
                {
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[7 * 8 + i];
                }
                //  Draw right corner, normal
                u32 tileOffset;
                switch (edgePixels)
                {
                case 0:
                    tileOffset = 23;
                    break;
                case 1:
                    tileOffset = 22;
                    break;
                case 2:
                    tileOffset = 21;
                    break;
                case 3:
                    tileOffset = 20;
                    break;
                case 4:
                    tileOffset = 19;
                    break;
                case 5:
                    tileOffset = 18;
                    break;
                default:
                    tileOffset = 8;
                    break;
                }

                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
                currY--;

                switch (edgePixels)
                {
                case 0:
                    tileOffset = 41;
                    break;
                case 1:
                    tileOffset = 40;
                    break;
                case 2:
                    tileOffset = 39;
                    break;
                case 3:
                    tileOffset = 38;
                    break;
                case 4:
                    tileOffset = 37;
                    break;
                case 5:
                    tileOffset = 36;
                    break;
                default:
                    tileOffset = 4;
                    break;
                }
                //  Draw middle section
                for (; currY > 3 - lines; currY--)
                {
                    //  Left edge
                    currX = 1;
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + i] = sSpeechBubbleTiles[3 * 8 + i];

                    //  Middle
                    for (; currX < tilesX - 1; currX++)
                    {
                        for (u32 i = 0; i < 8; i++)
                            sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[5 * 8 + i];
                    }

                    //  Right edge
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
                }

                //  Draw top section
                currY = 3 - lines;
                //  Draw left corner
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + i] = sSpeechBubbleTiles[i];
                //  Draw middle section
                currX = 1;
                for (; currX < tilesX - 1; currX++)
                {
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[8 + i];
                }
                //  Draw right corner
                switch (edgePixels)
                {
                case 0:
                    tileOffset = 17;
                    break;
                case 1:
                    tileOffset = 16;
                    break;
                case 2:
                    tileOffset = 15;
                    break;
                case 3:
                    tileOffset = 14;
                    break;
                case 4:
                    tileOffset = 13;
                    break;
                case 5:
                    tileOffset = 12;
                    break;
                default:
                    tileOffset = 2;
                    break;
                }
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
            }
            break;
        case RIGHT_START:
            {
                u32 currY = 3;
                u32 currX = 6;
                //  Bottom right corner
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + 7 * 8 + i] = sSpeechBubbleTiles[10 * 8 + i];
                //  Bottom middle part
                for (; currX > 8 - tilesX; currX--)
                {
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[7 * 8 + i];
                }
                u32 tileOffset;
                switch (edgePixels)
                {
                case 0:
                    tileOffset = 35;
                    break;
                case 1:
                    tileOffset = 34;
                    break;
                case 2:
                    tileOffset = 33;
                    break;
                case 3:
                    tileOffset = 32;
                    break;
                case 4:
                    tileOffset = 31;
                    break;
                case 5:
                    tileOffset = 30;
                    break;
                default:
                    tileOffset = 6;
                    break;
                }
                //  Bottom left part
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
                currY--;
                //  Middle section
                for (; currY > 3 - lines; currY--)
                {
                    //  Right edge
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + 7 * 8 + i] = sSpeechBubbleTiles[4 * 8 + i];
                    //  Centre
                    for (currX = 6; currX > 8 - tilesX; currX--)
                    {
                        for (u32 i = 0; i < 8; i++)
                            sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[5 * 8 + i];
                    }
                    //  Left edge
                    switch (edgePixels)
                    {
                    case 0:
                        tileOffset = 47;
                        break;
                    case 1:
                        tileOffset = 46;
                        break;
                    case 2:
                        tileOffset = 45;
                        break;
                    case 3:
                        tileOffset = 44;
                        break;
                    case 4:
                        tileOffset = 43;
                        break;
                    case 5:
                        tileOffset = 42;
                        break;
                    default:
                        tileOffset = 3;
                        break;
                    }
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
                }
                //  Top right corner
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + 7 * 8 + i] = sSpeechBubbleTiles[2 * 8 + i];
                for (currX = 6; currX > 8 - tilesX; currX--)
                {
                    for (u32 i = 0; i < 8; i++)
                        sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[1 * 8 + i];
                }
                switch (edgePixels)
                {
                case 0:
                    tileOffset = 29;
                    break;
                case 1:
                    tileOffset = 28;
                    break;
                case 2:
                    tileOffset = 27;
                    break;
                case 3:
                    tileOffset = 26;
                    break;
                case 4:
                    tileOffset = 25;
                    break;
                case 5:
                    tileOffset = 24;
                    break;
                default:
                    tileOffset = 0;
                    break;
                }
                for (u32 i = 0; i < 8; i++)
                    sprite[currY * 64 + currX * 8 + i] = sSpeechBubbleTiles[tileOffset * 8 + i];
            }
            break;
        }
    }

    return sprite;
}

static void SpriteCB_HoldPosLeft1(struct Sprite *sprite)
{
    struct Sprite *target = &gSprites[sprite->data[0]];
    struct Sprite *player = &gSprites[gObjectEvents[gPlayerAvatar.objectEventId].spriteId];
    s16 diffX = player->x - target->x;
    s16 diffY = player->y - target->y;
    sprite->x = 120 - diffX + 32;
    sprite->y = 80 - diffY - 32;
}

static void SpriteCB_HoldPosLeft2(struct Sprite *sprite)
{
    struct Sprite *target = &gSprites[sprite->data[0]];
    struct Sprite *player = &gSprites[gObjectEvents[gPlayerAvatar.objectEventId].spriteId];
    s16 diffX = player->x - target->x;
    s16 diffY = player->y - target->y;
    sprite->x = 120 - diffX + 96;
    sprite->y = 80 - diffY - 32;
}

static void SpriteCB_HoldPosRight1(struct Sprite *sprite)
{
    struct Sprite *target = &gSprites[sprite->data[0]];
    struct Sprite *player = &gSprites[gObjectEvents[gPlayerAvatar.objectEventId].spriteId];
    s16 diffX = player->x - target->x;
    s16 diffY = player->y - target->y;
    sprite->x = 120 - diffX - 32;
    sprite->y = 80 - diffY - 32;
}

static void SpriteCB_HoldPosRight2(struct Sprite *sprite)
{
    struct Sprite *target = &gSprites[sprite->data[0]];
    struct Sprite *player = &gSprites[gObjectEvents[gPlayerAvatar.objectEventId].spriteId];
    s16 diffX = player->x - target->x;
    s16 diffY = player->y - target->y;
    sprite->x = 120 - diffX - 96;
    sprite->y = 80 - diffY - 32;
}

static u32 CalcDistanceToPlayer(struct Coords16 *object)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    return abs(player->currentCoords.x - object->x) + abs(player->currentCoords.y - object->y);
};

bool32 IsSourceObjectOffscreen(u32 objectEventId)
{
    struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
    struct ObjectEvent *object = &gObjectEvents[objectEventId];
    s16 xDiff = player->currentCoords.x - object->currentCoords.x;
    s16 yDiff = player->currentCoords.y - object->currentCoords.y;

    return abs(xDiff) > 8 || abs(yDiff) > 6;
}

const struct SpritePalette sSpritePalette_Bubble =
{
    gObjectEventPaletteEmotes, OBJ_EVENT_PAL_TAG_EMOTES
};

u32 CreateSpeechBubbleNormal(u32 localId, u32 eventIndex, enum StartingSide side, const u8 *inputStr, bool32 maxOneSprite, u8 ids[2])
{
    u32 objectEventId = sActiveLiveEvents[eventIndex].objectEventId;
    u32 numSprites;
    sActiveLiveEvents[eventIndex].speechBubbleNormalData.str = Alloc(128);
    u8 *str = sActiveLiveEvents[eventIndex].speechBubbleNormalData.str;
    StringCopy(str, inputStr);
    u32 maxWidth = maxOneSprite ? 58 : 122;
    BreakStringAutomatic(str, maxWidth, 8, FONT_LIVE, HIDE_SCROLL_PROMPT);
    u32 width = GetStringWidth(FONT_LIVE, str, 0);
    u32 lines = GetStringLines(str);

    if (side == AUTOMATIC_START)
    {
        struct ObjectEvent *player = &gObjectEvents[gPlayerAvatar.objectEventId];
        struct ObjectEvent *object = &gObjectEvents[objectEventId];
        s16 xDiff = player->currentCoords.x - object->currentCoords.x;
        if (xDiff < 0)
            side = RIGHT_START;
        else
            side = LEFT_START;
    }

    u32 *sprite = BuildSpeechBubble(width, lines, side);

    if (width > 58)
        numSprites = 2;
    else
        numSprites = 1;

    struct Even_CreateSpriteStruct cs = {0};
    cs.sprite = sprite;
    cs.tileTag = LIVE_EVENT_GFX_TAG_START + 2 * localId;
    LoadSpritePalette(&sSpritePalette_Bubble);
    cs.palTag = OBJ_EVENT_PAL_TAG_EMOTES;
    cs.spriteSize = SPRITE_SIZE(64x32);
    cs.spriteShape = SPRITE_SHAPE(64x32);
    cs.posX = 120;
    cs.posY = 80;
    u8 id1 = Even_CreateSprite(&cs);
    switch (side)
    {
    case LEFT_START:
        gSprites[id1].callback = SpriteCB_HoldPosLeft1;
        break;
    case RIGHT_START:
        gSprites[id1].callback = SpriteCB_HoldPosRight1;
        break;
    default:
        errorf("Side should be left or right at this point");
    }
    gSprites[id1].data[0] = gObjectEvents[objectEventId].spriteId;
    ids[0] = id1;

    if (numSprites == 2)
    {
        cs.sprite = &sprite[64 * 32 / 8];
        cs.tileTag++;
        u8 id2 = Even_CreateSprite(&cs);
        gSprites[id2].data[0] = gObjectEvents[objectEventId].spriteId;

        switch (side)
        {
        case LEFT_START:
            ids[1] = id2;
            gSprites[id2].callback = SpriteCB_HoldPosLeft2;
            break;
        case RIGHT_START:
            ids[1] = ids[0];
            ids[0] = id2;
            gSprites[id2].callback = SpriteCB_HoldPosRight2;
            break;
        default:
            errorf("Side should be left or right at this point");
        }

        SetupSpritesForTextPrinting(ids, NULL, 2, 1);
        const u8 col[4] = {12, 1, 9, 0};
        u32 xPos = 3;
        if (side == RIGHT_START)
            xPos = 4 + (122 - width);
        u32 idToStartOn = ids[0];
        if (xPos > 63)
        {
            xPos = 1;
            idToStartOn = ids[1];
        }
        AddSpriteTextPrinterParameterized3(idToStartOn, FONT_LIVE, xPos, 19 - (lines - 1) * 8, col, LIVE_TEXT_SPEED, str);
    }
    else
    {
        SetupSpritesForTextPrinting(ids, NULL, 1, 1);
        const u8 col[4] = {12, 1, 9, 0};
        u32 xPos = 3;
        if (side == RIGHT_START)
            xPos = 4 + (58 - width);
        AddSpriteTextPrinterParameterized3(ids[0], FONT_LIVE, xPos, 19 - (lines - 1) * 8, col, LIVE_TEXT_SPEED, str);
    }
    Free(sprite);
    return numSprites;
}

void CheckAndTearDownSpeechBubble(u32 eventIndex, u32 objectEventId)
{
    sAnySpeechBubbleIsActive = TRUE;
    if (sActiveLiveEvents[eventIndex].duration == 1 || IsSourceObjectOffscreen(objectEventId))
    {
        if (LIVE_TEXT_SPEED != 0)
        {
            //  Stop potential active text printers
            if (sActiveLiveEvents[eventIndex].speechBubbleNormalData.numSprites == 2)
            {
                if (IsTextPrinterActiveOnSprite(sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids[0]))
                    DeactivateSingleTextPrinter(sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids[0], SPRITE_TEXT_PRINTER);
                else if (IsTextPrinterActiveOnSprite(sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids[1]))
                    DeactivateSingleTextPrinter(sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids[1], SPRITE_TEXT_PRINTER);
            }
            else
            {
                if (IsTextPrinterActiveOnSprite(sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids[0]))
                    DeactivateSingleTextPrinter(sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids[0], SPRITE_TEXT_PRINTER);
            }
        }
        DestroySprite(&gSprites[sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids[0]]);
        FreeSpriteTilesByTag(LIVE_EVENT_GFX_TAG_START + 2 * eventIndex);
        if (sActiveLiveEvents[eventIndex].speechBubbleNormalData.numSprites == 2)
        {
            DestroySprite(&gSprites[sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids[1]]);
            FreeSpriteTilesByTag(LIVE_EVENT_GFX_TAG_START + 2 * eventIndex + 1);
        }
        sActiveLiveEvents[eventIndex].duration = 1;
        Free(sActiveLiveEvents[eventIndex].speechBubbleNormalData.str);
    }
    sActiveLiveEvents[eventIndex].duration--;
}

void ExecuteScript(const u8 *script)
{
    ScriptContext_SetupScript(script);
}

static bool32 EventCanTriggerForObject(u32 localId)
{
    return !((sHasTriggered & ((u64)1 << localId)) > 0);
}

static inline void SetHasTriggeredForObject(u32 localId)
{
    sHasTriggered |= (u64)1 << localId;
}

static inline void RemoveHasTriggeredForObject(u32 localId)
{
    u64 mask = ~((u64)1 << localId);
    sHasTriggered &= mask;
}

static inline void SetRetriggerDelayForObject(u32 localId, u32 delay)
{
    if (delay > 0)
        sRetriggerDelays[localId] = delay;
}

static inline void AssignLiveEvent(u32 objectEventId, u32 localId, enum LiveEvent event)
{
    sActiveLiveEvents[localId].func = sLiveEvents[event].func;
    sActiveLiveEvents[localId].localId = localId;
    sActiveLiveEvents[localId].objectEventId = objectEventId;
    sActiveLiveEvents[localId].duration = sLiveEvents[event].duration;
}

static void SetupLiveEvent(u32 objectEventId, u32 localId, enum LiveEvent event)
{
    SetHasTriggeredForObject(localId);
    SetRetriggerDelayForObject(localId, sLiveEvents[event].retriggerDelay);
    AssignLiveEvent(objectEventId, localId, event);
}

void UpdateLiveEvent(u32 index)
{
    sActiveLiveEvents[index].func(sActiveLiveEvents[index].localId, index);
    if (sActiveLiveEvents[index].duration == 0)
    {
        //  Clear data
        sActiveLiveEvents[index].func = NULL;
        sActiveLiveEvents[index].localId = 0;
        sActiveLiveEvents[index].objectEventId = 0;
        sActiveLiveEvents[index].duration = 0;
    }
}

static inline bool32 IsIdNormalObjectEvent(u32 id)
{
    switch (id)
    {
    case LOCALID_NONE:
    case LOCALID_CAMERA:
    case LOCALID_BERRY_BLENDER_PLAYER_END:
    case LOCALID_FOLLOWING_POKEMON:
    case LOCALID_PLAYER:
        return FALSE;
    default:
        return TRUE;
    }
}

void ProcessLiveEvents(void)
{
    //  Try to fire new events
    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (!IsIdNormalObjectEvent(gObjectEvents[i].localId))
            continue;
        enum LiveEvent liveEvent = GetObjectEventTemplateByLocalIdAndMap(gObjectEvents[i].localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup)->liveEvent;
        if (liveEvent != LIVE_EVENT_NONE && liveEvent < LIVE_EVENT_COUNT)
        {
            if (EventCanTriggerForObject(gObjectEvents[i].localId) && CalcDistanceToPlayer(&gObjectEvents[i].currentCoords) <= sLiveEvents[liveEvent].triggerRange)
            {
                SetupLiveEvent(i, gObjectEvents[i].localId, liveEvent);
            }
        }
    }

    //  Update existing events
    for (u32 i = 0; i < 64; i++)
    {
        if (sActiveLiveEvents[i].func != NULL)
            UpdateLiveEvent(i);

        //  Process re-triggering events
        if (sRetriggerDelays[i] > 0)
        {
            if (sRetriggerDelays[i] == 1)
                RemoveHasTriggeredForObject(i);
            sRetriggerDelays[i]--;
        }
    }

    if (sAnySpeechBubbleIsActive)
    {
        RunTextPrinters();
        sAnySpeechBubbleIsActive = FALSE;
    }
}

void ResetLiveEventTriggers(void)
{
    sHasTriggered = 0;
    for (u32 i = 0; i < 64; i++)
        sRetriggerDelays[i] = 0;
}

void StopActiveLiveEvents(void)
{
    for (u32 i = 0; i < 64; i++)
    {
        if (sActiveLiveEvents[i].duration > 1)
        {
            sActiveLiveEvents[i].duration = 1;
            UpdateLiveEvent(i);
        }
    }
}

void ManuallyTriggerLiveEvent(struct ScriptContext *ctx)
{
    //  This ignores the distance requirement
    u32 localId = ScriptReadByte(ctx);
    const struct ObjectEventTemplate *obj = GetObjectEventTemplateByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);

    enum LiveEvent liveEvent = obj->liveEvent;
    assertf(liveEvent != LIVE_EVENT_NONE, "Event for object is LIVE_EVENT_NONE")
    {
        return;
    }

    for (u32 i = 0; i < OBJECT_EVENTS_COUNT; i++)
    {
        if (gObjectEvents[i].localId == 255)
            continue;
        if (gObjectEvents[i].localId == localId)
        {
            if (EventCanTriggerForObject(localId))
                SetupLiveEvent(i, localId, liveEvent);
            break;
        }
    }
}
