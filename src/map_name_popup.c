#include "global.h"
#include "battle_pyramid.h"
#include "bg.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "map_name_popup.h"
#include "palette.h"
#include "region_map.h"
#include "rtc.h"
#include "start_menu.h"
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "constants/battle_frontier.h"
#include "constants/layouts.h"
#include "constants/map_types.h"
#include "constants/region_map_sections.h"
#include "constants/weather.h"
#include "config/general.h"
#include "config/overworld.h"

// enums
enum MapPopUp_Themes
{
    MAPPOPUP_THEME_WOOD,
    MAPPOPUP_THEME_MARBLE,
    MAPPOPUP_THEME_STONE,
    MAPPOPUP_THEME_BRICK,
    MAPPOPUP_THEME_UNDERWATER,
    MAPPOPUP_THEME_STONE2,

    MAPPOPUP_THEME_HEARTH_WATER,
    MAPPOPUP_THEME_HEARTH_UNDERWATER,
    MAPPOPUP_THEME_HEARTH_KINTSUGI,
    MAPPOPUP_THEME_HEARTH_WOOD,
    MAPPOPUP_THEME_HEARTH_MARBLE,
    MAPPOPUP_THEME_HEARTH_SCROLL,
    MAPPOPUP_THEME_HEARTH_STONE,
    MAPPOPUP_THEME_HEARTH_STEEL,
    MAPPOPUP_THEME_HEARTH_CROBAT,
    MAPPOPUP_THEME_HEARTH_GINKO,
    MAPPOPUP_THEME_COUNT
};

enum MapPopUp_Themes_BW
{
    MAPPOPUP_THEME_BW_DEFAULT,
};

// static functions
static void Task_MapNamePopUpWindow(u8 taskId);
static void UpdateSecondaryPopUpWindow(u8 secondaryPopUpWindowId);
static void ShowMapNamePopUpWindow(void);
static void LoadMapNamePopUpWindowBg(void);

// EWRAM
EWRAM_DATA u8 gPopupTaskId = 0;

// .rodata
static const u8 sMapPopUp_Table[MAPPOPUP_THEME_COUNT][960] =
{
    [MAPPOPUP_THEME_WOOD]              = INCGFX_U8("graphics/map_popup/wood.png", ".4bpp"),
    [MAPPOPUP_THEME_MARBLE]            = INCGFX_U8("graphics/map_popup/marble.png", ".4bpp"),
    [MAPPOPUP_THEME_STONE]             = INCGFX_U8("graphics/map_popup/stone.png", ".4bpp"),
    [MAPPOPUP_THEME_BRICK]             = INCGFX_U8("graphics/map_popup/brick.png", ".4bpp"),
    [MAPPOPUP_THEME_UNDERWATER]        = INCGFX_U8("graphics/map_popup/underwater.png", ".4bpp"),
    [MAPPOPUP_THEME_STONE2]            = INCGFX_U8("graphics/map_popup/stone2.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_WATER]      = INCGFX_U8("graphics/map_popup/hearth/water.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_UNDERWATER] = INCGFX_U8("graphics/map_popup/hearth/underwater.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_KINTSUGI]   = INCGFX_U8("graphics/map_popup/hearth/kintsugi.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_WOOD]       = INCGFX_U8("graphics/map_popup/hearth/wood.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_MARBLE]     = INCGFX_U8("graphics/map_popup/hearth/marble.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_SCROLL]     = INCGFX_U8("graphics/map_popup/hearth/scroll.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_STONE]      = INCGFX_U8("graphics/map_popup/hearth/stone.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_STEEL]      = INCGFX_U8("graphics/map_popup/hearth/steel.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_CROBAT]     = INCGFX_U8("graphics/map_popup/hearth/crobat.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_GINKO]     = INCGFX_U8("graphics/map_popup/hearth/ginko.png", ".4bpp"),
};

static const u8 sMapPopUp_OutlineTable[MAPPOPUP_THEME_COUNT][960] =
{
    [MAPPOPUP_THEME_WOOD]              = INCGFX_U8("graphics/map_popup/wood_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_MARBLE]            = INCGFX_U8("graphics/map_popup/marble_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_STONE]             = INCGFX_U8("graphics/map_popup/stone_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_BRICK]             = INCGFX_U8("graphics/map_popup/brick_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_UNDERWATER]        = INCGFX_U8("graphics/map_popup/underwater_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_STONE2]            = INCGFX_U8("graphics/map_popup/stone2_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_WATER]      = INCGFX_U8("graphics/map_popup/hearth/water_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_UNDERWATER] = INCGFX_U8("graphics/map_popup/hearth/underwater_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_KINTSUGI]   = INCGFX_U8("graphics/map_popup/hearth/kintsugi_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_WOOD]       = INCGFX_U8("graphics/map_popup/hearth/wood_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_MARBLE]     = INCGFX_U8("graphics/map_popup/hearth/marble_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_SCROLL]     = INCGFX_U8("graphics/map_popup/hearth/scroll_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_STONE]      = INCGFX_U8("graphics/map_popup/hearth/stone_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_STEEL]      = INCGFX_U8("graphics/map_popup/hearth/steel_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_CROBAT]     = INCGFX_U8("graphics/map_popup/hearth/crobat_outline.png", ".4bpp"),
    [MAPPOPUP_THEME_HEARTH_GINKO]     = INCGFX_U8("graphics/map_popup/hearth/ginko_outline.png", ".4bpp"),
};

static const u16 sMapPopUp_PaletteTable[MAPPOPUP_THEME_COUNT][16] =
{
    [MAPPOPUP_THEME_WOOD]              = INCGFX_U16("graphics/map_popup/wood.png", ".gbapal"),
    [MAPPOPUP_THEME_MARBLE]            = INCGFX_U16("graphics/map_popup/marble_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_STONE]             = INCGFX_U16("graphics/map_popup/stone_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_BRICK]             = INCGFX_U16("graphics/map_popup/brick_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_UNDERWATER]        = INCGFX_U16("graphics/map_popup/underwater_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_STONE2]            = INCGFX_U16("graphics/map_popup/stone2_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_WATER]      = INCGFX_U16("graphics/map_popup/hearth/water_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_UNDERWATER] = INCGFX_U16("graphics/map_popup/hearth/underwater_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_KINTSUGI]   = INCGFX_U16("graphics/map_popup/hearth/kintsugi_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_WOOD]       = INCGFX_U16("graphics/map_popup/hearth/wood_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_MARBLE]     = INCGFX_U16("graphics/map_popup/hearth/marble_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_SCROLL]     = INCGFX_U16("graphics/map_popup/hearth/scroll_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_STONE]      = INCGFX_U16("graphics/map_popup/hearth/stone_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_STEEL]      = INCGFX_U16("graphics/map_popup/hearth/steel_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_CROBAT]     = INCGFX_U16("graphics/map_popup/hearth/crobat_outline.png", ".gbapal"),
    [MAPPOPUP_THEME_HEARTH_GINKO]     = INCGFX_U16("graphics/map_popup/hearth/ginko_outline.png", ".gbapal"),
};

static const u16 sMapPopUp_Palette_Underwater[16] = INCGFX_U16("graphics/map_popup/hearth/underwater.png", ".gbapal");

// -1 in the size excludes MAPSEC_NONE.
static const u8 sMapSectionToThemeId[MAPSEC_COUNT - 1] =
{
    [MAPSEC_PUDDLE_PATH] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_SABERSIDE_QUARRY] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_FISHERMANS_CHANNEL_WINDYCAPE] = MAPPOPUP_THEME_HEARTH_UNDERWATER,
    [MAPSEC_FISHERMANS_CHANNEL_MAGURO] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_FISHERMANS_CHANNEL_BOTTOM] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_FISHERMANS_CHANNEL_SACRED] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_FISHERMANS_SHRINE] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_TRANQUIL_ROUTE] = MAPPOPUP_THEME_HEARTH_WOOD,
    [MAPSEC_BEACHBOUND_ROUTE] = MAPPOPUP_THEME_HEARTH_WOOD,
    [MAPSEC_WHITESLATE_ROUTE] = MAPPOPUP_THEME_HEARTH_MARBLE,
    [MAPSEC_SCENIC_ROUTE] = MAPPOPUP_THEME_HEARTH_WOOD,
    [MAPSEC_HARVEST_SHRINE] = MAPPOPUP_THEME_HEARTH_WOOD,
    [MAPSEC_WINDSWEPT_ROUTE] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_SEATURF_ROUTE] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_LONGTIDE_CHANNEL] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_LONG_TIDE_CHANNEL_SOULKEEP] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_DRAGONS_PASS] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_BURNFOOT_PASS_BOTTOM] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_STEEPSTONE_PASS_BOTTOM] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_BURNFOOT_PASS] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_MT_KAZAN_EXTERIOR] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_STEEPSTONE_PASS] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_SHOGUNATE] = MAPPOPUP_THEME_HEARTH_KINTSUGI,
    [MAPSEC_SILVER_TUNNEL] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_SEASTROLL_CHANNEL] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_ORCHARD_PATH] = MAPPOPUP_THEME_HEARTH_WOOD,
    [MAPSEC_SCENIC_ROUTE_SABERSIDE] = MAPPOPUP_THEME_HEARTH_WOOD,
    [MAPSEC_UUME_FOREST] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_COREEF_ISLE] = MAPPOPUP_THEME_HEARTH_UNDERWATER,
    [MAPSEC_OPEN_SEA_CORAL] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_OPEN_SEA_HAVEN] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_OPEN_SEA_LEAGUE] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_OPEN_SEA_ICY] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_SABERSIDE_CHANNEL] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_CROBAT_HIDEOUT] = MAPPOPUP_THEME_HEARTH_CROBAT,
    [MAPSEC_SUNRISE_CAVE] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_GINKO_WOODS] = MAPPOPUP_THEME_HEARTH_GINKO,
    [MAPSEC_SECRET_BASE] = MAPPOPUP_THEME_HEARTH_WOOD,
    [MAPSEC_DYNAMIC] = MAPPOPUP_THEME_HEARTH_SCROLL,
    [MAPSEC_SUNRISE_VILLAGE] = MAPPOPUP_THEME_HEARTH_GINKO,
    [MAPSEC_CHII_TOWN] = MAPPOPUP_THEME_HEARTH_GINKO,
    [MAPSEC_SAKU_TOWN] = MAPPOPUP_THEME_HEARTH_SCROLL,
    [MAPSEC_KURA_TOWN] = MAPPOPUP_THEME_HEARTH_SCROLL,
    [MAPSEC_MAGURO_HARBOR] = MAPPOPUP_THEME_HEARTH_WATER,
    [MAPSEC_SILVERIDGE] = MAPPOPUP_THEME_HEARTH_STONE,
    [MAPSEC_WINDYCAPE] = MAPPOPUP_THEME_HEARTH_UNDERWATER,
    [MAPSEC_YIFU_CITY] = MAPPOPUP_THEME_HEARTH_MARBLE,
    [MAPSEC_SOULKEEP] = MAPPOPUP_THEME_HEARTH_SCROLL,
    [MAPSEC_HAVENISLE] = MAPPOPUP_THEME_HEARTH_WOOD,
    [MAPSEC_MIDDLEISLE] = MAPPOPUP_THEME_HEARTH_UNDERWATER,
    [MAPSEC_TOPISLE] = MAPPOPUP_THEME_HEARTH_UNDERWATER,
    [MAPSEC_DRYUGON] = MAPPOPUP_THEME_HEARTH_KINTSUGI,
    [MAPSEC_SABERSIDE_TOWN] = MAPPOPUP_THEME_HEARTH_STEEL,
    [MAPSEC_HANABI_CITY] = MAPPOPUP_THEME_HEARTH_SCROLL,
    [MAPSEC_LEAGUE] = MAPPOPUP_THEME_HEARTH_KINTSUGI,
    [MAPSEC_INSIDE_BRONZONG] = MAPPOPUP_THEME_HEARTH_STONE,
};

#if OW_POPUP_GENERATION == GEN_5
// Gen5 assets
static const u8 sMapPopUpTilesPrimary_BW[] = INCGFX_U8("graphics/map_popup/bw/bw_primary.png", ".4bpp");
static const u8 sMapPopUpTilesSecondary_BW[] = INCGFX_U8("graphics/map_popup/bw/bw_secondary.png", ".4bpp");
static const u16 sMapPopUpTilesPalette_BW_Black[16] = INCGFX_U16("graphics/map_popup/bw/black.pal", ".gbapal");
static const u16 sMapPopUpTilesPalette_BW_White[16] = INCGFX_U16("graphics/map_popup/bw/white.pal", ".gbapal");
#else
static const u8 sMapPopUpTilesPrimary_BW[] = {0};
static const u8 sMapPopUpTilesSecondary_BW[] = {0};
static const u16 sMapPopUpTilesPalette_BW_Black[] = {0};
static const u16 sMapPopUpTilesPalette_BW_White[] = {0};
#endif

static const u8 sRegionMapSectionId_To_PopUpThemeIdMapping_BW[] =
{
    [MAPSEC_PUDDLE_PATH] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SABERSIDE_QUARRY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FISHERMANS_CHANNEL_WINDYCAPE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FISHERMANS_CHANNEL_MAGURO] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FISHERMANS_CHANNEL_BOTTOM] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FISHERMANS_CHANNEL_SACRED] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_FISHERMANS_SHRINE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_TRANQUIL_ROUTE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_BEACHBOUND_ROUTE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_WHITESLATE_ROUTE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SCENIC_ROUTE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_HARVEST_SHRINE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_WINDSWEPT_ROUTE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SEATURF_ROUTE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_LONGTIDE_CHANNEL] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_LONG_TIDE_CHANNEL_SOULKEEP] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_DRAGONS_PASS] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_BURNFOOT_PASS_BOTTOM] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_STEEPSTONE_PASS_BOTTOM] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_BURNFOOT_PASS] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MT_KAZAN_EXTERIOR] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_STEEPSTONE_PASS] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SHOGUNATE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SILVER_TUNNEL] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SEASTROLL_CHANNEL] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_ORCHARD_PATH] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SCENIC_ROUTE_SABERSIDE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_UUME_FOREST] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_COREEF_ISLE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_OPEN_SEA_CORAL] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_OPEN_SEA_HAVEN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_OPEN_SEA_LEAGUE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_OPEN_SEA_ICY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SABERSIDE_CHANNEL] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_CROBAT_HIDEOUT] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SUNRISE_CAVE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_GINKO_WOODS] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SECRET_BASE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_DYNAMIC] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SUNRISE_VILLAGE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_CHII_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SAKU_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_KURA_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MAGURO_HARBOR] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SILVERIDGE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_WINDYCAPE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_YIFU_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SOULKEEP] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_HAVENISLE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_MIDDLEISLE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_TOPISLE] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_DRYUGON] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_SABERSIDE_TOWN] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_HANABI_CITY] = MAPPOPUP_THEME_BW_DEFAULT,
    [MAPSEC_LEAGUE] = MAPPOPUP_THEME_BW_DEFAULT,
};

static const u8 sText_PyramidFloor1[] = _("PYRAMID FLOOR 1");
static const u8 sText_PyramidFloor2[] = _("PYRAMID FLOOR 2");
static const u8 sText_PyramidFloor3[] = _("PYRAMID FLOOR 3");
static const u8 sText_PyramidFloor4[] = _("PYRAMID FLOOR 4");
static const u8 sText_PyramidFloor5[] = _("PYRAMID FLOOR 5");
static const u8 sText_PyramidFloor6[] = _("PYRAMID FLOOR 6");
static const u8 sText_PyramidFloor7[] = _("PYRAMID FLOOR 7");
static const u8 sText_Pyramid[] = _("PYRAMID");

static const u8 *const sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    sText_PyramidFloor1,
    sText_PyramidFloor2,
    sText_PyramidFloor3,
    sText_PyramidFloor4,
    sText_PyramidFloor5,
    sText_PyramidFloor6,
    sText_PyramidFloor7,
    sText_Pyramid,
};

static bool8 UNUSED StartMenu_ShowMapNamePopup(void)
{
    HideStartMenu();
    ShowMapNamePopup();
    return TRUE;
}

// States and data defines for Task_MapNamePopUpWindow
enum {
    STATE_SLIDE_IN,
    STATE_WAIT,
    STATE_SLIDE_OUT,
    STATE_UNUSED,
    STATE_ERASE,
    STATE_END,
    STATE_PRINT, // For some reason the first state is numerically last.
};

#define POPUP_OFFSCREEN_Y  ((OW_POPUP_GENERATION == GEN_5) ? 24 : 40)
#define POPUP_SLIDE_SPEED  2

#define tState         data[0]
#define tOnscreenTimer data[1]
#define tYOffset       data[2]
#define tIncomingPopUp data[3]
#define tPrintTimer    data[4]

void ShowMapNamePopup(void)
{
    if (FlagGet(FLAG_HIDE_MAP_NAME_POPUP) != TRUE)
    {
        if (!FuncIsActiveTask(Task_MapNamePopUpWindow))
        {
            // New pop up window
            if (OW_POPUP_GENERATION == GEN_5)
            {
                gPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 100);

                if (OW_POPUP_BW_ALPHA_BLEND && !IsWeatherAlphaBlend())
                    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_TGT2_ALL | BLDCNT_EFFECT_BLEND);
            }
            else
            {
                gPopupTaskId = CreateTask(Task_MapNamePopUpWindow, 90);
                SetGpuReg(REG_OFFSET_BG0VOFS, POPUP_OFFSCREEN_Y);
            }

            gTasks[gPopupTaskId].tState = STATE_PRINT;
            gTasks[gPopupTaskId].tYOffset = POPUP_OFFSCREEN_Y;
        }
        else
        {
            // There's already a pop up window running.
            // Hurry the old pop up offscreen so the new one can appear.
            if (gTasks[gPopupTaskId].tState != STATE_SLIDE_OUT)
                gTasks[gPopupTaskId].tState = STATE_SLIDE_OUT;
            gTasks[gPopupTaskId].tIncomingPopUp = TRUE;
        }
    }
}

static void Task_MapNamePopUpWindow(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->tState)
    {
    case STATE_PRINT:
        // Wait, then create and print the pop up window
        if (++task->tPrintTimer > 30)
        {
            task->tState = STATE_SLIDE_IN;
            task->tPrintTimer = 0;
            ShowMapNamePopUpWindow();
            if (OW_POPUP_GENERATION == GEN_5)
            {
                EnableInterrupts(INTR_FLAG_HBLANK);
                SetHBlankCallback(HBlankCB_DoublePopupWindow);
            }
        }
        break;
    case STATE_SLIDE_IN:
        // Slide the window onscreen.
        task->tYOffset -= POPUP_SLIDE_SPEED;
        if (task->tYOffset <= 0 )
        {
            task->tYOffset = 0;
            task->tState = STATE_WAIT;
            gTasks[gPopupTaskId].tOnscreenTimer = 0;
        }
        break;
    case STATE_WAIT:
        // Wait while the window is fully onscreen.
        if (++task->tOnscreenTimer > 120)
        {
            task->tOnscreenTimer = 0;
            task->tState = STATE_SLIDE_OUT;
        }
        break;
    case STATE_SLIDE_OUT:
        // Slide the window offscreen.
        task->tYOffset += POPUP_SLIDE_SPEED;
        if (task->tYOffset >= POPUP_OFFSCREEN_Y)
        {
            task->tYOffset = POPUP_OFFSCREEN_Y;
            if (task->tIncomingPopUp)
            {
                // A new pop up window is incoming,
                // return to the first state to show it.
                task->tState = STATE_PRINT;
                task->tPrintTimer = 0;
                task->tIncomingPopUp = FALSE;
            }
            else
            {
                task->tState = STATE_ERASE;
                return;
            }
        }
        break;
    case STATE_ERASE:
        ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
        if (OW_POPUP_GENERATION == GEN_5)
            ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
        task->tState = STATE_END;
        break;
    case STATE_END:
        HideMapNamePopUpWindow();
        return;
    }
    if (OW_POPUP_GENERATION != GEN_5)
        SetGpuReg(REG_OFFSET_BG0VOFS, task->tYOffset);
}

void HideMapNamePopUpWindow(void)
{
    if (FuncIsActiveTask(Task_MapNamePopUpWindow))
    {
    #ifdef UBFIX
        if (GetMapNamePopUpWindowId() != WINDOW_NONE)
    #endif // UBFIX
        {
            ClearStdWindowAndFrame(GetMapNamePopUpWindowId(), TRUE);
            RemoveMapNamePopUpWindow();
        }

        if (OW_POPUP_GENERATION == GEN_5)
        {
            if (GetSecondaryPopUpWindowId() != WINDOW_NONE)
            {
                ClearStdWindowAndFrame(GetSecondaryPopUpWindowId(), TRUE);
                RemoveSecondaryPopUpWindow();
            }

            DisableInterrupts(INTR_FLAG_HBLANK);
            SetHBlankCallback(NULL);

            if (OW_POPUP_BW_ALPHA_BLEND && !IsWeatherAlphaBlend())
            {
                SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_BG_ALL | WININ_WIN0_OBJ | WININ_WIN1_BG_ALL | WININ_WIN1_OBJ);
                SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT2_BG1 | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_OBJ | BLDCNT_EFFECT_BLEND);
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 10));
            }
        }

        SetGpuReg_ForcedBlank(REG_OFFSET_BG0VOFS, 0);
        DestroyTask(gPopupTaskId);
    }
}

static void UpdateSecondaryPopUpWindow(u8 secondaryPopUpWindowId)
{
    u8 mapDisplayHeader[24];
    u8 *withoutPrefixPtr = &(mapDisplayHeader[0]);

    if (OW_POPUP_BW_TIME_MODE != OW_POPUP_BW_TIME_NONE)
    {
        RtcCalcLocalTime();
        FormatDecimalTimeWithoutSeconds(withoutPrefixPtr, gLocalTime.hours, gLocalTime.minutes, OW_POPUP_BW_TIME_MODE == OW_POPUP_BW_TIME_24_HR);
        AddTextPrinterParameterized(secondaryPopUpWindowId, FONT_SMALL, mapDisplayHeader, GetStringRightAlignXOffset(FONT_SMALL, mapDisplayHeader, DISPLAY_WIDTH) - 5, 8, TEXT_SKIP_DRAW, NULL);
    }
    CopyWindowToVram(secondaryPopUpWindowId, COPYWIN_FULL);
}

static void MapNamePopupAppendFloorNum(u8 *map_name, s8 floorNum)
{
    if (floorNum == 0)
        return;
    u8 *dest = map_name;
    while (*dest != EOS)
        dest++;
    *dest++ = CHAR_SPACE;
    if (floorNum == FLOOR_ROOFTOP)
    {
        StringCopy(dest, gText_Rooftop);
        return;
    }
    if (floorNum < 0)
    {
        *dest++ = CHAR_B;
        floorNum *= -1;
    }
    dest = ConvertIntToDecimalStringN(dest, floorNum, STR_CONV_MODE_LEFT_ALIGN, 2);
    *dest++ = CHAR_F;
    *dest = EOS;
}

static bool32 IsCeladonDeptStore(const struct MapHeader *mapHeader)
{
    if (mapHeader->regionMapSectionId != MAPSEC_CELADON_CITY)
        return FALSE;
    if (mapHeader->mapLayoutId != LAYOUT_CELADON_CITY_DEPARTMENT_STORE_1F
     && mapHeader->mapLayoutId != LAYOUT_CELADON_CITY_DEPARTMENT_STORE_2F
     && mapHeader->mapLayoutId != LAYOUT_CELADON_CITY_DEPARTMENT_STORE_3F
     && mapHeader->mapLayoutId != LAYOUT_CELADON_CITY_DEPARTMENT_STORE_4F
     && mapHeader->mapLayoutId != LAYOUT_CELADON_CITY_DEPARTMENT_STORE_5F
     && mapHeader->mapLayoutId != LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ROOF
     && mapHeader->mapLayoutId != LAYOUT_CELADON_CITY_DEPARTMENT_STORE_ELEVATOR)
    {
        return FALSE;
    }
    return TRUE;
}

u8 *GetPopUpMapName(u8 *dest, const struct MapHeader *mapHeader)
{
    if (IsCeladonDeptStore(mapHeader))
        StringCopy(dest, COMPOUND_STRING("CELADON DEPT."));
    else
        GetMapName(dest, mapHeader->regionMapSectionId, 0);
    if (mapHeader->floorNumber == 0)
        return dest;
    MapNamePopupAppendFloorNum(dest, mapHeader->floorNumber);
    return dest;
}

static void ShowMapNamePopUpWindow(void)
{
    u8 mapDisplayHeader[MAP_POPUP_STRING_BUFFER_LENGTH];
    u8 *withoutPrefixPtr;
    u8 x;
    const u8 *mapDisplayHeaderSource;
    u8 mapNamePopUpWindowId, secondaryPopUpWindowId;

    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        if (gMapHeader.mapLayoutId == LAYOUT_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP)
        {
            withoutPrefixPtr = &(mapDisplayHeader[MAP_POPUP_PREFIX_BUFFER_LENGTH]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[FRONTIER_STAGES_PER_CHALLENGE];
        }
        else
        {
            withoutPrefixPtr = &(mapDisplayHeader[MAP_POPUP_PREFIX_BUFFER_LENGTH]);
            mapDisplayHeaderSource = sBattlePyramid_MapHeaderStrings[gSaveBlock2Ptr->frontier.curChallengeBattleNum];
        }
        StringCopy(withoutPrefixPtr, mapDisplayHeaderSource);
    }
    else
    {
        withoutPrefixPtr = &(mapDisplayHeader[MAP_POPUP_PREFIX_BUFFER_LENGTH]);
        GetPopUpMapName(withoutPrefixPtr, &gMapHeader);
    }

    if (OW_POPUP_GENERATION == GEN_5)
    {
        if (OW_POPUP_BW_ALPHA_BLEND && !IsWeatherAlphaBlend())
            SetGpuRegBits(REG_OFFSET_WININ, WININ_WIN0_CLR);

        mapNamePopUpWindowId = AddMapNamePopUpWindow();
        secondaryPopUpWindowId = AddSecondaryPopUpWindow();
    }
    else
    {
        AddMapNamePopUpWindow();
    }

    LoadMapNamePopUpWindowBg();

    mapDisplayHeader[0] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[1] = EXT_CTRL_CODE_BACKGROUND;
    mapDisplayHeader[2] = TEXT_COLOR_TRANSPARENT;
    mapDisplayHeader[3] = EXT_CTRL_CODE_BEGIN;
    mapDisplayHeader[4] = EXT_CTRL_CODE_ACCENT;
    mapDisplayHeader[5] = TEXT_COLOR_TRANSPARENT;

    if (OW_POPUP_GENERATION == GEN_5)
    {
        AddTextPrinterParameterized(mapNamePopUpWindowId, FONT_SHORT, mapDisplayHeader, 8, 2, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(mapNamePopUpWindowId, COPYWIN_FULL);
        UpdateSecondaryPopUpWindow(secondaryPopUpWindowId);
    }
    else
    {
        u32 fontId = GetFontIdToFit(withoutPrefixPtr, FONT_NORMAL, -1, 80);
        x = GetStringCenterAlignXOffset(fontId, withoutPrefixPtr, 80);
        AddTextPrinterParameterized(GetMapNamePopUpWindowId(), fontId, mapDisplayHeader, x, 3, TEXT_SKIP_DRAW, NULL);
        CopyWindowToVram(GetMapNamePopUpWindowId(), COPYWIN_FULL);
    }
}

#define TILE_TOP_EDGE_START 0x21D
#define TILE_TOP_EDGE_END   0x228
#define TILE_LEFT_EDGE_TOP  0x229
#define TILE_RIGHT_EDGE_TOP 0x22A
#define TILE_LEFT_EDGE_MID  0x22B
#define TILE_RIGHT_EDGE_MID 0x22C
#define TILE_LEFT_EDGE_BOT  0x22D
#define TILE_RIGHT_EDGE_BOT 0x22E
#define TILE_BOT_EDGE_START 0x22F
#define TILE_BOT_EDGE_END   0x23A

static void DrawMapNamePopUpFrame(u8 bg, u8 x, u8 y, u8 deltaX, u8 deltaY, u8 unused)
{
    s32 i;

    // Draw top edge
    for (i = 0; i < 1 + TILE_TOP_EDGE_END - TILE_TOP_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_TOP_EDGE_START + i, i - 1 + x, y - 1, 1, 1, 14);

    // Draw sides
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_TOP,       x - 1,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_TOP, deltaX + x,     y, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_MID,       x - 1, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_MID, deltaX + x, y + 1, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_LEFT_EDGE_BOT,       x - 1, y + 2, 1, 1, 14);
    FillBgTilemapBufferRect(bg, TILE_RIGHT_EDGE_BOT, deltaX + x, y + 2, 1, 1, 14);

    // Draw bottom edge
    for (i = 0; i < 1 + TILE_BOT_EDGE_END - TILE_BOT_EDGE_START; i++)
        FillBgTilemapBufferRect(bg, TILE_BOT_EDGE_START + i, i - 1 + x, y + deltaY, 1, 1, 14);
}

static void LoadMapNamePopUpWindowBg(void)
{
    u8 popUpThemeId;
    u8 popupWindowId = GetMapNamePopUpWindowId();
    mapsec_u16_t regionMapSectionId = gMapHeader.regionMapSectionId;
    u8 secondaryPopUpWindowId;

    if (OW_POPUP_GENERATION == GEN_5)
        secondaryPopUpWindowId = GetSecondaryPopUpWindowId();

    if (OW_POPUP_GENERATION == GEN_5)
    {
        popUpThemeId = sRegionMapSectionId_To_PopUpThemeIdMapping_BW[regionMapSectionId];
        switch (popUpThemeId)
        {
        // add additional gen 5-style pop-up themes as cases here
        default: // MAPPOPUP_THEME_BW_DEFAULT
            if (OW_POPUP_BW_COLOR == OW_POPUP_BW_COLOR_WHITE)
                LoadPalette(sMapPopUpTilesPalette_BW_White, BG_PLTT_ID(14), sizeof(sMapPopUpTilesPalette_BW_White));
            else
                LoadPalette(sMapPopUpTilesPalette_BW_Black, BG_PLTT_ID(14), sizeof(sMapPopUpTilesPalette_BW_Black));

            CopyToWindowPixelBuffer(popupWindowId, sMapPopUpTilesPrimary_BW, sizeof(sMapPopUpTilesPrimary_BW), 0);
            CopyToWindowPixelBuffer(secondaryPopUpWindowId, sMapPopUpTilesSecondary_BW, sizeof(sMapPopUpTilesSecondary_BW), 0);
            break;
        }

        PutWindowTilemap(popupWindowId);
        PutWindowTilemap(secondaryPopUpWindowId);
    }
    else
    {
        popUpThemeId = sMapSectionToThemeId[regionMapSectionId];
        LoadBgTiles(GetWindowAttribute(popupWindowId, WINDOW_BG), sMapPopUp_OutlineTable[popUpThemeId], 0x400, 0x21D);
        CallWindowFunction(popupWindowId, DrawMapNamePopUpFrame);
        PutWindowTilemap(popupWindowId);
        if (gMapHeader.weather == WEATHER_UNDERWATER_BUBBLES)
            LoadPalette(&sMapPopUp_Palette_Underwater, BG_PLTT_ID(14), sizeof(sMapPopUp_Palette_Underwater));
        else
            LoadPalette(sMapPopUp_PaletteTable[popUpThemeId], BG_PLTT_ID(14), sizeof(sMapPopUp_PaletteTable[0]));
        BlitBitmapToWindow(popupWindowId, sMapPopUp_Table[popUpThemeId], 0, 0, 80, 24);
    }
}
