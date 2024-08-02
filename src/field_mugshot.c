#include "global.h"
#include "decompress.h"
#include "sprite.h"
#include "script.h"
#include "event_data.h"
#include "field_weather.h"
#include "constants/field_mugshots.h"
#include "data/field_mugshots.h"

static EWRAM_DATA u8 sFieldMugshotSpriteId = 0;

#define TAG_MUGSHOT 0x9000

// don't remove the `+ 32`
// otherwise your sprite will not be placed in the place you desire
#define MUGSHOT_X 168 + 32
#define MUGSHOT_Y 51  + 32

static const struct OamData sFieldMugshot_Oam = {
    .size = SPRITE_SIZE(64x64),
    .shape = SPRITE_SHAPE(64x64),
    .priority = 0,
};

static const struct SpriteTemplate sFieldMugshot_SpriteTemplate = {
    .tileTag = TAG_MUGSHOT,
    .paletteTag = TAG_MUGSHOT,
    .oam = &sFieldMugshot_Oam,
    .callback = SpriteCallbackDummy,
    .anims = gDummySpriteAnimTable,
    .affineAnims = gDummySpriteAffineAnimTable,
};

void RemoveFieldMugshot(void)
{
    if (IndexOfSpritePaletteTag(TAG_MUGSHOT) != 0xFF)
    {
        ResetPreservedPalettesInWeather();
        DestroySprite(&gSprites[sFieldMugshotSpriteId]);
        FreeSpritePaletteByTag(TAG_MUGSHOT);
        FreeSpriteTilesByTag(TAG_MUGSHOT);
        sFieldMugshotSpriteId = SPRITE_NONE;
    }
}

void CreateFieldMugshot(void)
{
    u16 id = VarGet(VAR_TEMP_E);
    u16 emote = VarGet(VAR_TEMP_F);
    struct CompressedSpriteSheet sheet = { .size=0x1000, .tag=TAG_MUGSHOT };
    struct SpritePalette pal = { .tag = sheet.tag };

    RemoveFieldMugshot();
    if (id >= NELEMS(sFieldMugshots))
    {
        return;
    }

    sheet.data = (sFieldMugshots[id][emote].gfx != NULL ? sFieldMugshots[id][emote].gfx : sFieldMugshotGfx_TestNormal);
    pal.data = (sFieldMugshots[id][emote].pal != NULL ? sFieldMugshots[id][emote].pal : sFieldMugshotPal_TestNormal);

    LoadCompressedSpriteSheet(&sheet);
    LoadSpritePalette(&pal);

    sFieldMugshotSpriteId = CreateSprite(&sFieldMugshot_SpriteTemplate, MUGSHOT_X, MUGSHOT_Y, 0);
    if (sFieldMugshotSpriteId == SPRITE_NONE)
    {
        return;
    }
    PreservePaletteInWeather(gSprites[sFieldMugshotSpriteId].oam.paletteNum + 0x10);
}