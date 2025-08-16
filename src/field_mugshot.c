#include "global.h"
#include "decompress.h"
#include "sprite.h"
#include "script.h"
#include "event_data.h"
#include "field_weather.h"
#include "field_message_box.h"
#include "field_mugshot.h"
#include "constants/field_mugshots.h"
#include "data/field_mugshots.h"

static EWRAM_DATA u8 sFieldMugshotSpriteIds[2] = {};
static EWRAM_DATA u8 sIsFieldMugshotActive = 0;
static EWRAM_DATA u8 sFieldMugshotSlot = 0;

#define TAG_MUGSHOT 0x9000
#define TAG_MUGSHOT2 0x9001

// don't remove the `+ 32`
// otherwise your sprite will not be placed in the place you desire
#define MUGSHOT_X 168 + 32
#define MUGSHOT_Y 51  + 32

static void SpriteCB_FieldMugshot(struct Sprite *s);

static const struct OamData sFieldMugshot_Oam = {
    .size = SPRITE_SIZE(64x64),
    .shape = SPRITE_SHAPE(64x64),
    .priority = 0,
};

static const struct SpriteTemplate sFieldMugshot_SpriteTemplate = {
    .tileTag = TAG_MUGSHOT,
    .paletteTag = TAG_MUGSHOT,
    .oam = &sFieldMugshot_Oam,
    .callback = SpriteCB_FieldMugshot,
    .anims = gDummySpriteAnimTable,
    .affineAnims = gDummySpriteAffineAnimTable,
};

static void SpriteCB_FieldMugshot(struct Sprite *s)
{
    if (s->data[0] == TRUE)
    {
        s->invisible = FALSE;
    }
    else
    {
        s->invisible = TRUE;
    }
}

void RemoveFieldMugshot(void)
{
    ResetPreservedPalettesInWeather();
    if (sFieldMugshotSpriteIds[0] != 0xFF)
    {
        FreeSpriteTilesByTag(TAG_MUGSHOT);
        FreeSpritePaletteByTag(TAG_MUGSHOT);
        DestroySprite(&gSprites[sFieldMugshotSpriteIds[0]]);
        sFieldMugshotSpriteIds[0] = SPRITE_NONE;
    }
    if (sFieldMugshotSpriteIds[1] != 0xFF)
    {
        FreeSpriteTilesByTag(TAG_MUGSHOT2);
        FreeSpritePaletteByTag(TAG_MUGSHOT2);
        DestroySprite(&gSprites[sFieldMugshotSpriteIds[1]]);
        sFieldMugshotSpriteIds[1] = SPRITE_NONE;
    }
    sIsFieldMugshotActive = FALSE;
}

void CreateFieldMugshot(struct ScriptContext *ctx)
{
    u16 id = VarGet(ScriptReadHalfword(ctx));
    u16 emote = VarGet(ScriptReadHalfword(ctx));

    _CreateFieldMugshot(id, emote);
}

void _RemoveFieldMugshot(u8 slot)
{
    ResetPreservedPalettesInWeather();
    if (sFieldMugshotSpriteIds[slot ^ 1] != SPRITE_NONE)
    {
        gSprites[sFieldMugshotSpriteIds[slot ^ 1]].data[0] = FALSE; // same as setting visibility
    }

    if (sFieldMugshotSpriteIds[slot] != SPRITE_NONE)
    {
        gSprites[sFieldMugshotSpriteIds[slot]].data[0] = TRUE; // same as setting visibility
        FreeSpriteTilesByTag(slot + TAG_MUGSHOT);
        FreeSpritePaletteByTag(slot + TAG_MUGSHOT);
        DestroySprite(&gSprites[sFieldMugshotSpriteIds[slot]]);
        sFieldMugshotSpriteIds[slot] = SPRITE_NONE;
    }
}

void _CreateFieldMugshot(u32 id, u32 emote)
{
    u32 slot = sFieldMugshotSlot;
    struct SpriteTemplate temp = sFieldMugshot_SpriteTemplate;
    struct CompressedSpriteSheet sheet = { .size=0x1000, .tag=slot+TAG_MUGSHOT };
    struct SpritePalette pal = { .tag = sheet.tag };

    DebugPrintf("id: %u, emote: %u, sFieldMugshotSlot: %u, NULL: %d", id, emote, slot, sFieldMugshots[id][emote].gfx == NULL);
    if (sIsFieldMugshotActive)
    {
        _RemoveFieldMugshot(slot);
    }

    if (id >= NELEMS(sFieldMugshots))
    {
        return;
    }

    temp.tileTag = sheet.tag;
    temp.paletteTag = sheet.tag;
    sheet.data = (sFieldMugshots[id][emote].gfx != NULL ? sFieldMugshots[id][emote].gfx : sFieldMugshotGfx_TestNormal);
    pal.data = (sFieldMugshots[id][emote].pal != NULL ? sFieldMugshots[id][emote].pal : sFieldMugshotPal_TestNormal);

    LoadSpritePalette(&pal);
    LoadCompressedSpriteSheet(&sheet);

    sFieldMugshotSpriteIds[slot] = CreateSprite(&temp, MUGSHOT_X, MUGSHOT_Y, 0);
    if (sFieldMugshotSpriteIds[slot] == SPRITE_NONE)
    {
        return;
    }
    PreservePaletteInWeather(gSprites[sFieldMugshotSpriteIds[slot]].oam.paletteNum + 0x10);
    gSprites[sFieldMugshotSpriteIds[slot]].data[0] = FALSE;
    sIsFieldMugshotActive = TRUE;
    sFieldMugshotSlot ^= 1;
}

u8 GetFieldMugshotSpriteId(void)
{
    return sFieldMugshotSpriteIds[sFieldMugshotSlot ^ 1];
}

u8 IsFieldMugshotActive(void)
{
    return sIsFieldMugshotActive;
}

void SetFieldMugshotSpriteId(u32 value)
{
    sFieldMugshotSpriteIds[0] = value;
    sFieldMugshotSpriteIds[1] = value;
}
