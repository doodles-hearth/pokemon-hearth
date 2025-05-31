#include "global.h"
#include "bg.h"
#include "event_data.h"
#include "field_effect.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "overworld.h"
#include "palette.h"
#include "region_map.h"
#include "sound.h"
#include "sprite.h"
#include "strings.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define MAPCURSOR_X_MIN 1
#define MAPCURSOR_Y_MIN 2
#define MAPCURSOR_X_MAX (MAPCURSOR_X_MIN + MAP_WIDTH - 1)
#define MAPCURSOR_Y_MAX (MAPCURSOR_Y_MIN + MAP_HEIGHT - 1)
#define MAP_SPRITE_16X16 200

/*
 *  This is the type of map shown when interacting with the metatiles for
 *  a wall-mounted Region Map (on the wall of the Pokemon Centers near the PC)
 *  It does not zoom, and pressing A or B closes the map
 *
 *  For the region map in the pokenav, see pokenav_region_map.c
 *  For the region map in the pokedex, see pokdex_area_screen.c/pokedex_area_region_map.c
 *  For the fly map, and utility functions all of the maps use, see region_map.c
 */

enum {
    WIN_MAPSEC_NAME,
    WIN_TITLE,
};

enum {
    TAG_PLAYER_ICON,
    TAG_CURSOR,
    TAG_UNVISITED_ICON
};

static EWRAM_DATA struct {
    MainCallback callback;
    u32 unused;
    struct RegionMap regionMap;
    u16 state;
    u8 tileBuffer[0x1c0];
} *sFieldRegionMapHandler = NULL;

static void MCB2_InitRegionMapRegisters(void);
static void VBCB_FieldUpdateRegionMap(void);
static void MCB2_FieldUpdateRegionMap(void);
static void FieldUpdateRegionMap(void);
static void PrintRegionMapSecName();
static void GetMapSecDimensions(u16 mapSecId, u16 *x, u16 *y, u16 *width, u16 *height);
static void CreateUnvisitedTownIcons();
static void LoadUnvisitedTownIcons();

static const struct BgTemplate sFieldRegionMapBgTemplates[] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }, {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }, {
        .bg = 2,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .paletteMode = 0,
        .screenSize = 0,
        .priority = 2,
        .baseTile = 0
    }
};

static const struct WindowTemplate sFieldRegionMapWindowTemplates[] =
{
    [WIN_MAPSEC_NAME] = {
        .bg = 0,
        .tilemapLeft = 1,
        .tilemapTop = 17,
        .width = 12,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 1
    },
    [WIN_TITLE] = {
        .bg = 0,
        .tilemapLeft = 22,
        .tilemapTop = 1,
        .width = 7,
        .height = 2,
        .paletteNum = 15,
        .baseBlock = 25
    },
    DUMMY_WIN_TEMPLATE
};

void FieldInitRegionMap(MainCallback callback)
{
    SetVBlankCallback(NULL);
    sFieldRegionMapHandler = Alloc(sizeof(*sFieldRegionMapHandler));
    sFieldRegionMapHandler->state = 0;
    sFieldRegionMapHandler->callback = callback;
    SetMainCallback2(MCB2_InitRegionMapRegisters);
}

static void MCB2_InitRegionMapRegisters(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sFieldRegionMapBgTemplates, ARRAY_COUNT(sFieldRegionMapBgTemplates));
    InitWindows(sFieldRegionMapWindowTemplates);
    DeactivateAllTextPrinters();
    LoadUserWindowBorderGfx(0, 0x27, BG_PLTT_ID(13));
    ClearScheduledBgCopiesToVram();
    SetMainCallback2(MCB2_FieldUpdateRegionMap);
    SetVBlankCallback(VBCB_FieldUpdateRegionMap);
}

static void VBCB_FieldUpdateRegionMap(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void MCB2_FieldUpdateRegionMap(void)
{
    FieldUpdateRegionMap();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    DoScheduledBgTilemapCopiesToVram();
}

static const u16 sUnvisitedTownIcons_Pal[] = INCBIN_U16("graphics/region_map_hearth/town_icons.gbapal");
static const u32 sUnvisitedTownIcons_Gfx[] = INCBIN_U32("graphics/region_map_hearth/town_icons.4bpp.lz");

static const struct SpritePalette sUnvisitedTownIconsSpritePalette =
{
    .data = sUnvisitedTownIcons_Pal,
    .tag = TAG_UNVISITED_ICON
};

static const struct OamData sUnvisitedTownIcon_OamData =
{
    .shape = SPRITE_SHAPE(8x8),
    .size = SPRITE_SIZE(8x8),
    .priority = 2
};

static const union AnimCmd sUnvisitedTownIcon_Anim_8x8[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_END
};

static const union AnimCmd sUnvisitedTownIcon_Anim_16x8[] =
{
    ANIMCMD_FRAME(1, 5),
    ANIMCMD_END
};

static const union AnimCmd sUnvisitedTownIcon_Anim_8x16[] =
{
    ANIMCMD_FRAME(3, 5),
    ANIMCMD_END
};

static const union AnimCmd sUnvisitedTownIcon_Anim_16x16[] =
{
    ANIMCMD_FRAME(6, 5),
    ANIMCMD_END
};

static const union AnimCmd *const sUnvisitedTownIcon_Anims[] =
{
    [SPRITE_SHAPE(8x8)]       = sUnvisitedTownIcon_Anim_8x8,
    [SPRITE_SHAPE(16x8)]      = sUnvisitedTownIcon_Anim_16x8,
    [SPRITE_SHAPE(8x16)]      = sUnvisitedTownIcon_Anim_8x16,
	[MAP_SPRITE_16X16]        = sUnvisitedTownIcon_Anim_16x16,
};

static const struct SpriteTemplate sUnvisitedTownIconSpriteTemplate =
{
    .tileTag = TAG_UNVISITED_ICON,
    .paletteTag = TAG_UNVISITED_ICON,
    .oam = &sUnvisitedTownIcon_OamData,
    .anims = sUnvisitedTownIcon_Anims,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy
};

static void LoadUnvisitedTownIcons(void)
{
    struct SpriteSheet sheet;

    LZ77UnCompWram(sUnvisitedTownIcons_Gfx, sFieldRegionMapHandler->tileBuffer);
    sheet.data = sFieldRegionMapHandler->tileBuffer;
    sheet.size = sizeof(sFieldRegionMapHandler->tileBuffer);
    sheet.tag = TAG_UNVISITED_ICON;
    LoadSpriteSheet(&sheet);
    LoadSpritePalette(&sUnvisitedTownIconsSpritePalette);
    CreateUnvisitedTownIcons();
}

#define sIconMapSec   data[0]
#define sFlickerTimer data[1]

static void GetMapSecDimensions(u16 mapSecId, u16 *x, u16 *y, u16 *width, u16 *height)
{
    *x = gRegionMapEntries[mapSecId].x;
    *y = gRegionMapEntries[mapSecId].y;
    *width = gRegionMapEntries[mapSecId].width;
    *height = gRegionMapEntries[mapSecId].height;
}

static void CreateUnvisitedTownIcons(void)
{
    u16 mapSecId;
    u16 x;
    u16 y;
    u16 width;
    u16 height;
    u16 shape;
    u8 spriteId;

    for (mapSecId = MAPSEC_TOWNS_START; mapSecId < MAPSEC_NONE; mapSecId++)
    {
        if (GetMapsecType(mapSecId) == MAPSECTYPE_CITY_CANTFLY)
        {
            GetMapSecDimensions(mapSecId, &x, &y, &width, &height);
            x = (x + MAPCURSOR_X_MIN) * 8 + 4;
            y = (y + MAPCURSOR_Y_MIN) * 8 + 4;

            DebugPrintf("mapsec %d (%d,%d)", mapSecId, width, height);

            if (width == 2 && height == 2)
                shape = MAP_SPRITE_16X16;
            else if (width == 2)
                shape = SPRITE_SHAPE(16x8);
            else if (height == 2)
                shape = SPRITE_SHAPE(8x16);
            else
                shape = SPRITE_SHAPE(8x8);

            spriteId = CreateSprite(&sUnvisitedTownIconSpriteTemplate, x, y, 10);
            if (spriteId != MAX_SPRITES)
            {
                gSprites[spriteId].oam.shape = shape;

                if (shape == MAP_SPRITE_16X16)
                {
                    gSprites[spriteId].oam.size = SPRITE_SIZE(16x16);
                }

                StartSpriteAnim(&gSprites[spriteId], shape);
                gSprites[spriteId].sIconMapSec = mapSecId;
            }
        }
    }
}

static void FieldUpdateRegionMap(void)
{
    switch (sFieldRegionMapHandler->state)
    {
        case 0:
            InitRegionMap(&sFieldRegionMapHandler->regionMap, FALSE);
            CreateRegionMapPlayerIcon(TAG_PLAYER_ICON, TAG_PLAYER_ICON);
            CreateRegionMapCursor(TAG_CURSOR, TAG_CURSOR);
            sFieldRegionMapHandler->state++;
            break;
        case 1:
            ScheduleBgCopyTilemapToVram(0);
            DrawStdFrameWithCustomTileAndPalette(WIN_MAPSEC_NAME, FALSE, 0x27, 0xd);
            PrintRegionMapSecName();
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            sFieldRegionMapHandler->state++;
            break;
        case 2:
            SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            ShowBg(0);
            ShowBg(2);
            sFieldRegionMapHandler->state++;
            break;
        case 3:
            LoadUnvisitedTownIcons();
            sFieldRegionMapHandler->state++;
            break;
        case 4:
            if (!gPaletteFade.active)
            {
                sFieldRegionMapHandler->state++;
            }
            break;
        case 5:
            switch (DoRegionMapInputCallback())
            {
                case MAP_INPUT_MOVE_END:
                    PrintRegionMapSecName();
                    break;
                case MAP_INPUT_A_BUTTON:
                case MAP_INPUT_B_BUTTON:
                    sFieldRegionMapHandler->state++;
                    break;
                case MAP_INPUT_R_BUTTON:
                    if (sFieldRegionMapHandler->regionMap.mapSecType == MAPSECTYPE_CITY_CANFLY 
                        && FlagGet(OW_FLAG_POKE_RIDER) && Overworld_MapTypeAllowsTeleportAndFly(gMapHeader.mapType) == TRUE)
                    {
                        PlaySE(SE_SELECT);
                        SetFlyDestination(&sFieldRegionMapHandler->regionMap);
                        gSkipShowMonAnim = TRUE;
                        ReturnToFieldFromFlyMapSelect();
                    }
            }
            break;
        case 6:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            sFieldRegionMapHandler->state++;
            break;
        case 7:
            if (!gPaletteFade.active)
            {
                FreeRegionMapIconResources();
                SetMainCallback2(sFieldRegionMapHandler->callback);
                TRY_FREE_AND_SET_NULL(sFieldRegionMapHandler);
                FreeAllWindowBuffers();
            }
            break;
    }
}

static void PrintRegionMapSecName(void)
{
    if (sFieldRegionMapHandler->regionMap.mapSecType != MAPSECTYPE_NONE)
    {
        FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(1));
        AddTextPrinterParameterized(WIN_MAPSEC_NAME, FONT_NORMAL, sFieldRegionMapHandler->regionMap.mapSecName, 0, 1, 0, NULL);
        ScheduleBgCopyTilemapToVram(WIN_MAPSEC_NAME);
    }
    else
    {
        FillWindowPixelBuffer(WIN_MAPSEC_NAME, PIXEL_FILL(1));
        CopyWindowToVram(WIN_MAPSEC_NAME, COPYWIN_FULL);
    }
}
