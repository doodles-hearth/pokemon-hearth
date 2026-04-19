#include "global.h"
#include "bg.h"
#include "constants/characters.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/global.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "data.h"
#include "decompress.h"
#include "even_sprite.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "gba/macro.h"
#include "gba/types.h"
#include "global.fieldmap.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "international_string_util.h"
#include "intro.h"
#include "kaba_speech.h"
#include "main.h"
#include "main_menu_hearth.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "pokedex.h"
#include "pokemon_icon.h"
#include "prologue_screen.h"
#include "random.h"
#include "save.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "title_screen.h"
#include "title_screen_hearth.h"
#include "util.h"
#include "window.h"

#define HMM_BUTTON_SPRITE_COUNT 3
#define MON_ICON_PAL_COUNT 6

enum WindowIds { WIN_HMM_BG, WIN_HMM_LABEL, WIN_HMM_NO_SAVE };

enum {
    HMM_PALTAG_BUTTON = 0x1000,
    HMM_PALTAG_ACTIVE_BUTTON = 0x1001,
    HMM_PALTAG_PLAYER = 0x1002,
    HMM_PALTAG_BADGES = 0x1003,
};

enum {
    HMM_TILETAG_BUTTON1 = 0x2000,
    HMM_TILETAG_BUTTON2 = 0x2001,
    HMM_TILETAG_BUTTON3 = 0x2002,
    HMM_TILETAG_PLAYER  = 0x2003,
    HMM_TILETAG_BADGE_1 = 0x2004,
    HMM_TILETAG_BADGE_2 = 0x2005,
    HMM_TILETAG_BADGE_3 = 0x2006,
    HMM_TILETAG_BADGE_4 = 0x2007,
    HMM_TILETAG_BADGE_5 = 0x2008,
    HMM_TILETAG_BADGE_6 = 0x2009,
    HMM_TILETAG_BADGE_7 = 0x20010,
    HMM_TILETAG_BADGE_8 = 0x20011,
};

enum HmmButtonIds {
    HMM_BUTTON_NEWGAME,
    HMM_BUTTON_OPTIONS,
    HMM_BUTTON_MYSTERY,
    HMM_BUTTON_INFOBOX,
    HMM_BUTTON_COUNT,
};

enum HmmDirs {
    HMM_DIR_RIGHT,
    HMM_DIR_LEFT,
    HMM_DIR_UP,
    HMM_DIR_DOWN,
};

enum HmmMenuType {
    HMM_HAS_SAVE,
    HMM_NO_SAVE,
};

struct HearthMainMenuState {
    MainCallback savedCallback;
    enum HmmMenuType menuType;
    u8 loadState;
    u8 partyIconId[PARTY_SIZE];
    u8 playerSpriteId;
    u8 buttonSpriteId[HMM_BUTTON_SPRITE_COUNT];
    enum HmmButtonIds activeButton;
    enum HmmButtonIds prevButton;
};

static EWRAM_DATA struct HearthMainMenuState* sHearthMainMenuState = NULL;
static EWRAM_DATA u8* sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8* sBg2TilemapBuffer = NULL;

static const struct BgTemplate sHearthMainMenuBgTemplates[] = {
    {.bg = 0, .charBaseIndex = 0, .mapBaseIndex = 30, .priority = 1},
    {.bg = 1, .charBaseIndex = 3, .mapBaseIndex = 31, .priority = 2},
    {.bg = 2, .charBaseIndex = 2, .mapBaseIndex = 29, .priority = 3},
};

static const struct WindowTemplate sHearthMainMenuWindowTemplates[] = {
    [WIN_HMM_BG] =
        {.bg = 0, .tilemapLeft = 4, .tilemapTop = 11, .width = 22, .height = 3, .paletteNum = 15, .baseBlock = 1},

    [WIN_HMM_LABEL] =
        {.bg = 0, .tilemapLeft = 22, .tilemapTop = 1, .width = 6, .height = 2, .paletteNum = 15, .baseBlock = 1 + 78},
    [WIN_HMM_NO_SAVE] =
        {.bg = 0, .tilemapLeft = 4, .tilemapTop = 5, .width = 22, .height = 3, .paletteNum = 15, .baseBlock = 93},
    DUMMY_WIN_TEMPLATE};

static const u32 HearthMainMenuBgTiles[] = INCBIN_U32("graphics/main_menu_hearth/main_bg/tiles.4bpp.smol");
static const u32 HearthMainMenuBgTilemap[] = INCBIN_U32("graphics/main_menu_hearth/main_bg/map.bin.smolTM");
static const u16 HearthMainMenuBgPalette[] = INCBIN_U16("graphics/main_menu_hearth/main_bg/bg.gbapal");
static const u16 HearthMainMenuBgActivePalette[] = INCBIN_U16("graphics/main_menu_hearth/main_bg/bg_active.gbapal");

static const u32 HearthMainMenuScrollingBgTiles[] = INCBIN_U32("graphics/main_menu_hearth/scrolling_bg.4bpp.smol");
static const u32 HearthMainMenuScrollingBgTilemap[] = INCBIN_U32("graphics/main_menu_hearth/scrolling_bg.bin.smolTM");
static const u16 HearthMainMenuScrollingBgPalette[] = INCBIN_U16("graphics/main_menu_hearth/scrolling_bg.gbapal");

static const u32 sMenuButtonGfx[] = INCBIN_U32("graphics/main_menu_hearth/button.4bpp.smol");
static const u16 sMenuButtonPal[] = INCBIN_U16("graphics/main_menu_hearth/button.gbapal");
static const u16 sMenuButtonActivePal[] = INCBIN_U16("graphics/main_menu_hearth/active_button.gbapal");


static const u32 sMenuBadgeGfx[] = INCBIN_U32("graphics/main_menu_hearth/badges.4bpp.smol");
static const u16 sMenuBadgesPal[] = INCBIN_U16("graphics/main_menu_hearth/badges.gbapal");

static const u32 sPlayerAoGfx[] = INCBIN_U32("graphics/main_menu_hearth/ao.4bpp.smol");
static const u16 sPlayerAoPal[] = INCBIN_U16("graphics/main_menu_hearth/ao.gbapal");
static const u32 sPlayerAkaGfx[] = INCBIN_U32("graphics/main_menu_hearth/aka.4bpp.smol");
static const u16 sPlayerAkaPal[] = INCBIN_U16("graphics/main_menu_hearth/aka.gbapal");


enum FontColor { FONT_WHITE, FONT_GRAY, FONT_RED };
static const u8 HearthMainMenuWindowFontColors[][3] = {
    [FONT_WHITE] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY},
    [FONT_GRAY] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_DARK_GRAY},
    [FONT_RED] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_GRAY},
};

// Callbacks
static void HearthMainMenu_SetupCB(void);
static void HearthMainMenu_MainCB(void);
static void HearthMainMenu_VBlankCB(void);
static void CB2_OpenPrologueScreen(void);

// Tasks
static void Task_HearthMainMenuWaitFadeIn(u8 taskId);
static void Task_HearthMainMenuInput(u8 taskId);
static void Task_HearthMainMenuWaitFadeAndBail(u8 taskId);
static void Task_HearthMainMenuWaitFadeAndExitGracefully(u8 taskId);
static void Task_HearthMainMenuScrollBg(u8 taskId);

// Helper Functions
static void HearthMainMenu_Init(MainCallback callback, enum HmmButtonIds activeButton);
static void HearthMainMenu_ResetGpuRegsAndBgs(void);
static bool8 HearthMainMenu_InitBgs(void);
static bool8 HearthMainMenu_LoadGraphics(void);
static void HearthMainMenu_InitWindows(void);
static void HearthMainMenu_StartFade(u32 color);
static void HearthMainMenu_FadeAndBail(void);
static void HearthMainMenu_FreeResources(void);
static enum HmmMenuType HearthMainMenu_GetMenuType(void);

static void HearthMainMenu_PrintUiWindowText(void);
static void HearthMainMenu_FormatSavegameTime(void);
static void HearthMainMenu_PrintUiLabelText(void);
static const u8* GetInfoboxFontColor(void);
static u32 GetWinWidth(enum WindowIds id);

static void HearthMainMenu_CreatePlayerIcon(s16 x, s16 y);
static void HearthMainMenu_DarkenPlayerIcon(void);
static void HearthMainMenu_RestorePlayerIcon(void);
static void HearthMainMenu_DrawPartyIcons(void);
static void HearthMainMenu_DarkenPartyIcons(void);

static u32 HearthMainMenu_CreateMenuButton(s16 x, s16 y, u32 tileTag, u32 palTag);
static void HearthMainMenu_CreateAllMenuButtons();
static void HearthMainMenu_PrintButtonLabels(void);

static u32 HearthMainMenu_CreateMenuBadge(s16 x, s16 y, u8 number);
static void HearthMainMenu_CreateAllBadges(s16 x, s16 y);
static void HearthMainMenu_DarkenBadges(void);
static void HearthMainMenu_RestoreBadges(void);
static u32 GetBadgeCount(void);

static void HearthMainMenu_SetInfoboxActive(bool32 active);
static void SetButtonPalette(u8 buttonId, const u16* pal, u32 palTag);
static void ActivateButton(enum HmmButtonIds buttonId);
static void DeactivateButton(enum HmmButtonIds buttonId);
static void SetActiveButton(enum HmmButtonIds buttonId);
static void MoveSelection(enum HmmDirs);

static void HearthMainMenu_HandleButtonPressA(void);
static void HearthMainMenu_HandleButtonPressB(void);
static void HearthMainMenu_ExitOnSelect(MainCallback callback);

void CB2_InitMainMenuHearth(void) { HearthMainMenu_Init(CB2_InitHearthTitleScreen, HMM_BUTTON_INFOBOX); }
static void CB2_InitMainMenuHearthFromOptionsMenu(void) { HearthMainMenu_Init(CB2_InitHearthTitleScreen, HMM_BUTTON_OPTIONS); }

void Task_OpenHearthMainMenu(u8 taskId)
{
    if (!gPaletteFade.active) {
        HearthMainMenu_Init(CB2_InitHearthTitleScreen, HMM_BUTTON_INFOBOX);
        DestroyTask(taskId);
    }
}

static void HearthMainMenu_Init(MainCallback callback, enum HmmButtonIds activeButton)
{
    sHearthMainMenuState = AllocZeroed(sizeof(struct HearthMainMenuState));
    if (sHearthMainMenuState == NULL) {
        SetMainCallback2(callback);
        return;
    }

    sHearthMainMenuState->loadState = 0;
    sHearthMainMenuState->savedCallback = callback;
    sHearthMainMenuState->activeButton = activeButton;

    SetMainCallback2(HearthMainMenu_SetupCB);
}

static void HearthMainMenu_ResetGpuRegsAndBgs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3CNT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, 0);
    SetGpuReg(REG_OFFSET_BG0CNT, 0);
    ChangeBgX(0, 0, BG_COORD_SET);
    ChangeBgY(0, 0, BG_COORD_SET);
    ChangeBgX(1, 0, BG_COORD_SET);
    ChangeBgY(1, 0, BG_COORD_SET);
    ChangeBgX(2, 0, BG_COORD_SET);
    ChangeBgY(2, 0, BG_COORD_SET);
    ChangeBgX(3, 0, BG_COORD_SET);
    ChangeBgY(3, 0, BG_COORD_SET);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    CpuFill16(0, (void*)VRAM, VRAM_SIZE);
    CpuFill32(0, (void*)OAM, OAM_SIZE);
}

static void HearthMainMenu_SetupCB(void)
{
    switch (gMain.state) {
        case 0:
            HearthMainMenu_ResetGpuRegsAndBgs();
            SetVBlankHBlankCallbacksToNull();
            ClearScheduledBgCopiesToVram();
            gMain.state++;
            break;
        case 1:
            ScanlineEffect_Stop();
            FreeAllSpritePalettes();
            ResetPaletteFade();
            ResetSpriteData();
            ResetTasks();
            gMain.state++;
            break;
        case 2:
            if (HearthMainMenu_InitBgs()) {
                sHearthMainMenuState->loadState = 0;
                gMain.state++;
            }
            else {
                HearthMainMenu_FadeAndBail();
                return;
            }
            break;
        case 3:
            if (HearthMainMenu_LoadGraphics() == TRUE) {
                gMain.state++;
            }
            break;
        case 4:
            HearthMainMenu_InitWindows();
            gMain.state++;
            break;
        case 5:
            if (HearthMainMenu_GetMenuType() == HMM_HAS_SAVE) {
                HearthMainMenu_CreatePlayerIcon(16, 12);
            }
            gMain.state++;
            break;
        case 6:
            if (HearthMainMenu_GetMenuType() == HMM_HAS_SAVE) {
                FreeMonIconPalettes();
                LoadMonIconPalettes();
                HearthMainMenu_DrawPartyIcons();
            }
            CreateTask(Task_HearthMainMenuWaitFadeIn, 0);
            gMain.state++;
            break;
        case 7:
            HearthMainMenu_CreateAllMenuButtons();
            if (HearthMainMenu_GetMenuType() == HMM_HAS_SAVE)
                HearthMainMenu_CreateAllBadges(96,20);
            gMain.state++;
            break;
        case 8:
            HearthMainMenu_PrintButtonLabels();
            if (HearthMainMenu_GetMenuType() == HMM_NO_SAVE && sHearthMainMenuState->activeButton == HMM_BUTTON_INFOBOX) {
                sHearthMainMenuState->activeButton = HMM_BUTTON_NEWGAME;
            }
            if (sHearthMainMenuState->activeButton == HMM_BUTTON_INFOBOX) {
                HearthMainMenu_SetInfoboxActive(TRUE);
            }
            else
            {
                HearthMainMenu_SetInfoboxActive(FALSE);
                SetActiveButton(sHearthMainMenuState->activeButton);
            }
            BeginNormalPaletteFade(PALETTES_ALL, 1, 16, 0, RGB_BLACK);
            gMain.state++;
            break;
        case 9:
            CreateTask(Task_HearthMainMenuScrollBg, 0);
            SetVBlankCallback(HearthMainMenu_VBlankCB);
            SetMainCallback2(HearthMainMenu_MainCB);
            break;
    }
}


static enum HmmMenuType HearthMainMenu_GetMenuType(void)
{
    switch (gSaveFileStatus) {
        case SAVE_STATUS_OK:
            return HMM_HAS_SAVE;
        default:
            return HMM_NO_SAVE;
    }
}

static void Task_HearthMainMenuScrollBg(u8 taskId)
{
    s16* tAccumulator = &gTasks[taskId].data[0];

    *tAccumulator += 8*9;

    s16 pixels = *tAccumulator >> 8;
    *tAccumulator &= 0xFF;

    if (pixels != 0)
        ChangeBgX(2, pixels << 8, 1);
}

static void HearthMainMenu_CreateAllMenuButtons()
{
    const s16 startX = 8 + 32;
    const s16 startY = 120 + 16;

    for (u32 i = 0; i < HMM_BUTTON_SPRITE_COUNT; i++) {
        s16 x;
        x = startX + (i * 64 + i*16);
        sHearthMainMenuState->buttonSpriteId[i] =
            HearthMainMenu_CreateMenuButton(x, startY, HMM_TILETAG_BUTTON1 + i, HMM_PALTAG_BUTTON);
    }
}

static void HearthMainMenu_CreatePlayerIcon(s16 x, s16 y)
{
    struct Even_CreateSpriteStruct cs;
    cs.spriteCompressed = TRUE;
    cs.sprite = gSaveBlock2Ptr->playerGender == FEMALE ? sPlayerAoGfx : sPlayerAkaGfx;
    cs.palette = sPlayerAoPal;
    cs.tileTag = HMM_TILETAG_PLAYER;
    cs.palTag = HMM_PALTAG_PLAYER;
    cs.posX = 32 + x;
    cs.posY = 32 + y;
    cs.subpriority = 0;
    cs.spriteShape = SPRITE_SHAPE(64x64);
    cs.spriteSize = SPRITE_SIZE(64x64);
    cs.callback = SpriteCallbackDummy;
    Even_CreateSprite(&cs);
}

static void HearthMainMenu_DarkenPlayerIcon(void)
{
    u16 index = IndexOfSpritePaletteTag(HMM_PALTAG_PLAYER);
    BlendPalette(OBJ_PLTT_ID(index), 16, 8, RGB_BLACK);
}

static void HearthMainMenu_RestorePlayerIcon(void)
{
    FreeSpritePaletteByTag(HMM_PALTAG_PLAYER);
    LoadSpritePaletteWithTag(sPlayerAoPal, HMM_PALTAG_PLAYER);
}

static u32 HearthMainMenu_CreateMenuBadge(s16 x, s16 y, u8 number)
{
    struct Even_CreateSpritesheetStruct cs = {0};
    cs.spriteIndex = number;
    cs.spriteCompressed = TRUE;
    cs.sprite = sMenuBadgeGfx;
    cs.palette = sMenuBadgesPal;
    cs.tileTag = HMM_TILETAG_BADGE_1 + number;
    cs.palTag = HMM_PALTAG_BADGES;
    cs.spriteSize = SPRITE_SIZE(16x16);
    cs.spriteShape = SPRITE_SHAPE(16x16);
    cs.posX = x;
    cs.posY = y;
    cs.subpriority = 0;
    return Even_CreateSpriteWithTileIndex(&cs);
}

static void HearthMainMenu_CreateAllBadges(s16 x, s16 y)
{
    u32 badgeCount = GetBadgeCount();
    for (u32 i = 0; i < badgeCount; i++) {
        HearthMainMenu_CreateMenuBadge(x + i * 16, y, i);
    }
}

static void HearthMainMenu_DarkenBadges(void)
{
    u16 index = IndexOfSpritePaletteTag(HMM_PALTAG_BADGES);
    BlendPalette(OBJ_PLTT_ID(index), 16, 8, RGB_BLACK);
}


static void HearthMainMenu_RestoreBadges(void)
{
    FreeSpritePaletteByTag(HMM_PALTAG_BADGES);
    LoadSpritePaletteWithTag(sMenuBadgesPal, HMM_PALTAG_BADGES);
}

static u32 GetBadgeCount(void)
{
    u32 badgeCount = 0;
    u32 i = 0;
    u32 badgeFlag = FLAG_BADGE01_GET;
    for (i = 0, badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++, i++) {
        if (FlagGet(badgeFlag))
            badgeCount++;
    }
    return badgeCount;
}

static u32 HearthMainMenu_CreateMenuButton(s16 x, s16 y, u32 tileTag, u32 palTag)
{
    struct Even_CreateSpriteStruct createStruct = {0};
    createStruct.sprite = sMenuButtonGfx;
    createStruct.palette = sMenuButtonPal;
    createStruct.tileTag = tileTag;
    createStruct.palTag = HMM_PALTAG_BUTTON;
    createStruct.spriteSize = SPRITE_SIZE(64x32);
    createStruct.spriteShape = SPRITE_SHAPE(64x32);
    createStruct.posX = x;
    createStruct.posY = y;
    createStruct.subpriority = 0;
    return Even_CreateCompressedSprite(&createStruct);
}

static void SetButtonPalette(u8 buttonId, const u16* pal, u32 palTag)
{
    struct SpritePalette sp;
    sp.data = pal;
    sp.tag = palTag;
    LoadSpritePalette(&sp);
    u8 palIndex = IndexOfSpritePaletteTag(palTag);
    gSprites[buttonId].oam.paletteNum = palIndex;
}

static void ActivateButton(enum HmmButtonIds buttonId)
{
    u8 spriteId = sHearthMainMenuState->buttonSpriteId[buttonId];
    SetButtonPalette(spriteId, sMenuButtonActivePal, HMM_PALTAG_ACTIVE_BUTTON);
}

static void DeactivateButton(enum HmmButtonIds buttonId)
{
    u8 spriteId = sHearthMainMenuState->buttonSpriteId[buttonId];
    SetButtonPalette(spriteId, sMenuButtonPal, HMM_PALTAG_BUTTON);
}

static void SetActiveButton(enum HmmButtonIds buttonId)
{
    if (buttonId < 0)
        buttonId = HMM_BUTTON_COUNT - 1;
    else if (buttonId >= HMM_BUTTON_COUNT)
        buttonId = 0;

    sHearthMainMenuState->prevButton = sHearthMainMenuState->activeButton;
    sHearthMainMenuState->activeButton = buttonId;

    if (sHearthMainMenuState->prevButton == HMM_BUTTON_INFOBOX) {
        HearthMainMenu_SetInfoboxActive(FALSE);
    }
    else if (sHearthMainMenuState->prevButton < HMM_BUTTON_COUNT) {
        DeactivateButton(sHearthMainMenuState->prevButton);
    }

    if (buttonId == HMM_BUTTON_INFOBOX) {
        HearthMainMenu_SetInfoboxActive(TRUE);
    }
    else {
        ActivateButton(buttonId);
    }
    HearthMainMenu_PrintButtonLabels();
}


static const union TextColor sButtonTextColorActive = {.background = 0, .foreground = 8, .shadow = 9, .accent = 0};
static const union TextColor sButtonTextColor = {.background = 0, .foreground = 8, .shadow = 9, .accent = 0};

static const u8* const sButtonTexts[3] = {
    [HMM_BUTTON_NEWGAME] = COMPOUND_STRING("New Game"),   [HMM_BUTTON_OPTIONS] = COMPOUND_STRING("Options"),
    [HMM_BUTTON_MYSTERY] = COMPOUND_STRING("Mystery Gift"), };

static void HearthMainMenu_PrintButtonLabels(void)
{
    for (u32 i = 0; i < 3; i++) {

        u8 fontId = FONT_SMALL_NARROW;

        if (GetStringWidth(FONT_SMALL_NARROW, sButtonTexts[i], 0) > 50) {
            fontId = FONT_SMALL_NARROWER; 
        }
        u8 spriteId = sHearthMainMenuState->buttonSpriteId[i];
        u32 left = GetStringCenterAlignXOffset(fontId, sButtonTexts[i], 64);
        const union TextColor* color = (sHearthMainMenuState->activeButton == i) ? &sButtonTextColorActive : &sButtonTextColor;
        AddSpriteTextPrinterParameterized6(spriteId, fontId, left, 8, 0, 0, *color, 0, sButtonTexts[i]);
    }
}

static void MoveSelection(enum HmmDirs direction)
{
    enum HmmButtonIds cur = sHearthMainMenuState->activeButton;

    switch (direction) {
        case HMM_DIR_UP:
            if (cur != HMM_BUTTON_INFOBOX && HearthMainMenu_GetMenuType() == HMM_HAS_SAVE)
                SetActiveButton(HMM_BUTTON_INFOBOX);
            break;

        case HMM_DIR_DOWN:
            if (cur == HMM_BUTTON_INFOBOX) {
                if (sHearthMainMenuState->prevButton != HMM_BUTTON_INFOBOX)
                    SetActiveButton(sHearthMainMenuState->prevButton);
                else
                    SetActiveButton(HMM_BUTTON_NEWGAME);
            }
            break;

        case HMM_DIR_LEFT:
            if (cur == HMM_BUTTON_INFOBOX)
                break;
            if (cur == HMM_BUTTON_NEWGAME)
                SetActiveButton(HMM_BUTTON_MYSTERY);
            else
                SetActiveButton(cur - 1);
            break;

        case HMM_DIR_RIGHT:
            if (cur == HMM_BUTTON_INFOBOX)
                break;
            if (cur == HMM_BUTTON_MYSTERY)
                SetActiveButton(HMM_BUTTON_NEWGAME);
            else
                SetActiveButton(cur + 1);
            break;
    }
}

static void HearthMainMenu_DrawPartyIcons(void)
{
    const u16 startX = 100;
    const u16 startY = 44;

    for (u32 i = 0; i < PARTY_SIZE; i++) {
        u16 speciesId = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (speciesId == SPECIES_NONE) {
            sHearthMainMenuState->partyIconId[i] = SPRITE_NONE;
            continue;
        }

        u32 personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);

        u32 row = i / 3;
        u32 col = i % 3;

        u16 x = startX + col * 32 + 16;
        u16 y = startY + row * 32;

        if (row == 1) {
            x += 16;
            y -= 8;
        }

        sHearthMainMenuState->partyIconId[i] = CreateMonIcon(speciesId, SpriteCB_MonIcon, x, y, 4, personality);

        gSprites[sHearthMainMenuState->partyIconId[i]].oam.priority = 0;
    }
}

static void HearthMainMenu_DarkenPartyIcons(void)
{
    u16 palTag;
    u16 index;
    for (u32 i = 0; i < MON_ICON_PAL_COUNT; i++)
    {
        palTag = gMonIconPaletteTable[i].tag;
        index = IndexOfSpritePaletteTag(palTag);
        BlendPalette(OBJ_PLTT_ID(index), 16, 8, RGB_BLACK);
    }
}

static void HearthMainMenu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void HearthMainMenu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_HearthMainMenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active) {
        gTasks[taskId].func = Task_HearthMainMenuInput;
    }
}

static void HearthMainMenu_StartFade(u32 color)
{
    CpuFastCopy(gPlttBufferFaded, gPlttBufferUnfaded, sizeof(gPlttBufferFaded));
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, color);
}

static void Task_HearthMainMenuInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON)) {
        HearthMainMenu_HandleButtonPressB();
    }
    if (JOY_NEW(A_BUTTON)) {
        HearthMainMenu_HandleButtonPressA();
    }
    if (JOY_NEW(DPAD_UP)) {
        PlaySE(SE_SELECT);
        MoveSelection(HMM_DIR_UP);
    }
    if (JOY_NEW(DPAD_DOWN)) {
        PlaySE(SE_SELECT);
        MoveSelection(HMM_DIR_DOWN);
    }
    if (JOY_NEW(DPAD_LEFT)) {
        PlaySE(SE_SELECT);
        MoveSelection(HMM_DIR_LEFT);
    }
    if (JOY_NEW(DPAD_RIGHT)) {
        PlaySE(SE_SELECT);
        MoveSelection(HMM_DIR_RIGHT);
    }
}

static void HearthMainMenu_HandleButtonPressA(void)
{
    switch (sHearthMainMenuState->activeButton) {
        case HMM_BUTTON_INFOBOX:
            HearthMainMenu_ExitOnSelect(CB2_ContinueSavedGame);
            break;

        case HMM_BUTTON_NEWGAME:
            HearthMainMenu_ExitOnSelect(CB2_OpenPrologueScreen);
            break;

        case HMM_BUTTON_OPTIONS:
            gMain.savedCallback = CB2_InitMainMenuHearthFromOptionsMenu;
            HearthMainMenu_ExitOnSelect(CB2_InitOptionMenu);
            break;

        default:
            PlaySE(SE_FAILURE);
            break;
    }
}

static void HearthMainMenu_HandleButtonPressB(void)
{
    u8 taskId = FindTaskIdByFunc(Task_HearthMainMenuInput);
    PlaySE(SE_PC_OFF);
    HearthMainMenu_StartFade(RGB_BLACK);
    gTasks[taskId].func = Task_HearthMainMenuWaitFadeAndExitGracefully;
}

static void HearthMainMenu_ExitOnSelect(MainCallback callback)
{
    u8 taskId = FindTaskIdByFunc(Task_HearthMainMenuInput);
    PlaySE(SE_PC_ON);
    HearthMainMenu_StartFade(RGB_BLACK);
    sHearthMainMenuState->savedCallback = callback;
    gTasks[taskId].func = Task_HearthMainMenuWaitFadeAndExitGracefully;
}

static void CB2_OpenPrologueScreen(void)
{
    CreateTask(Task_OpenPrologueScreen, 0);
    SetMainCallback2(CB2_KabaSpeech);
}

static void HearthMainMenu_SetInfoboxActive(bool32 active)
{
    if (active) {
        LoadPalette(HearthMainMenuBgActivePalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        gSprites[sHearthMainMenuState->playerSpriteId].animPaused = FALSE;
        FreeMonIconPalettes();
        LoadMonIconPalettes();
        HearthMainMenu_RestorePlayerIcon();
        HearthMainMenu_RestoreBadges();
        for (u32 i = 0; i < PARTY_SIZE; i++) {
            u8 id = sHearthMainMenuState->partyIconId[i];
            struct Sprite* sprite = &gSprites[id];
            if (sprite->inUse) {
                sprite->callback = SpriteCB_MonIcon;
            }
        }
    }
    else {
        LoadPalette(HearthMainMenuBgPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        gSprites[sHearthMainMenuState->playerSpriteId].animPaused = TRUE;
        HearthMainMenu_DarkenPartyIcons();
        HearthMainMenu_DarkenPlayerIcon();
        HearthMainMenu_DarkenBadges();
        for (u32 i = 0; i < PARTY_SIZE; i++) {
            u8 id = sHearthMainMenuState->partyIconId[i];
            struct Sprite* sprite = &gSprites[id];
            if (sprite->inUse) {
                sprite->callback = SpriteCallbackDummy;
            }
        }
    }
    HearthMainMenu_PrintUiWindowText();
}

static void Task_HearthMainMenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active) {
        SetMainCallback2(sHearthMainMenuState->savedCallback);
        HearthMainMenu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_HearthMainMenuWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active) {
        HearthMainMenu_FreeResources();
        SetMainCallback2(sHearthMainMenuState->savedCallback);
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 HearthMainMenu_InitBgs(void)
{
    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    sBg2TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL || sBg2TilemapBuffer == NULL) {
        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sHearthMainMenuBgTemplates, NELEMS(sHearthMainMenuBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    SetBgTilemapBuffer(2, sBg2TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void HearthMainMenu_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_HearthMainMenuWaitFadeAndBail, 0);
    SetVBlankCallback(HearthMainMenu_VBlankCB);
    SetMainCallback2(HearthMainMenu_MainCB);
}

static bool8 HearthMainMenu_LoadGraphics(void)
{
    switch (sHearthMainMenuState->loadState) {
        case 0:
            ResetTempTileDataBuffers();
            DecompressAndCopyTileDataToVram(1, HearthMainMenuBgTiles, 0, 0, 0);
            DecompressAndCopyTileDataToVram(2, HearthMainMenuScrollingBgTiles, 0, 0, 0);
            sHearthMainMenuState->loadState++;
            break;
        case 1:
            if (FreeTempTileDataBuffersIfPossible() != TRUE) {
                DecompressDataWithHeaderWram(HearthMainMenuBgTilemap, sBg1TilemapBuffer);
                sHearthMainMenuState->loadState++;
            }
            break;
        case 2:
            if (FreeTempTileDataBuffersIfPossible() != TRUE) {
                DecompressDataWithHeaderWram(HearthMainMenuScrollingBgTilemap, sBg2TilemapBuffer);
                sHearthMainMenuState->loadState++;
            }
            break;
        case 3:
            LoadPalette(HearthMainMenuBgPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            LoadPalette(HearthMainMenuScrollingBgPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
            LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
            sHearthMainMenuState->loadState++;
        default:
            sHearthMainMenuState->loadState = 0;
            return TRUE;
    }
    return FALSE;
}

static void HearthMainMenu_InitWindows(void)
{
    InitWindows(sHearthMainMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WIN_HMM_BG, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WIN_HMM_BG);
    CopyWindowToVram(WIN_HMM_BG, 3);
    FillWindowPixelBuffer(WIN_HMM_LABEL, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WIN_HMM_LABEL);
    CopyWindowToVram(WIN_HMM_LABEL, 3);
    FillWindowPixelBuffer(WIN_HMM_NO_SAVE, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WIN_HMM_NO_SAVE);
    CopyWindowToVram(WIN_HMM_NO_SAVE, 3);
}

static const u8 sText_PlayerName[] = _("{PLAYER}");
static const u8 sText_Tokens[] = _("Tokens  {STR_VAR_2}");
static const u8 sText_NoSaveData[] = _("No Save Data Found");
static void HearthMainMenu_PrintUiWindowText(void)
{
    s16 left = 0;
    s16 top = 0;
    FillWindowPixelBuffer(WIN_HMM_BG, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    const u8* color = GetInfoboxFontColor();

    if (HearthMainMenu_GetMenuType() == HMM_HAS_SAVE) {
        HearthMainMenu_FormatSavegameTime();
        AddTextPrinterParameterized4(WIN_HMM_BG, FONT_SMALL, left, top, 0, 0, color, TEXT_SKIP_DRAW, gStringVar1);

        StringExpandPlaceholders(gStringVar1, sText_PlayerName);
        u8 strXName = GetStringCenterAlignXOffset(FONT_SMALL, gStringVar1, GetWinWidth(WIN_HMM_BG) * 8);
        AddTextPrinterParameterized4(WIN_HMM_BG, FONT_SMALL, strXName, top, 0, 0, color, TEXT_SKIP_DRAW, gStringVar1);
        u8 strRightAlignTokens = GetStringRightAlignXOffset(FONT_SMALL, sText_Tokens, GetWinWidth(WIN_HMM_BG) * 8);
        ConvertUIntToDecimalStringN(gStringVar2, GetBadgeCount(), STR_CONV_MODE_LEFT_ALIGN, 1);
        StringExpandPlaceholders(gStringVar1, sText_Tokens);
        AddTextPrinterParameterized4(WIN_HMM_BG, FONT_SMALL, strRightAlignTokens, top, 0, 0, color, TEXT_SKIP_DRAW,
                                     gStringVar1);
        CopyWindowToVram(WIN_HMM_BG, COPYWIN_GFX);
    }
    else {
        u8 strXNoSave = GetStringCenterAlignXOffset(FONT_NORMAL, sText_NoSaveData, GetWinWidth(WIN_HMM_NO_SAVE) * 8);
        AddTextPrinterParameterized4(WIN_HMM_NO_SAVE, FONT_NORMAL, strXNoSave, 0, 0, 0, color, TEXT_SKIP_DRAW, sText_NoSaveData);
        CopyWindowToVram(WIN_HMM_NO_SAVE, COPYWIN_GFX);
    }

}

static void HearthMainMenu_FormatSavegameTime(void)
{
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Time  {STR_VAR_2}:{STR_VAR_3}"));
}

static void HearthMainMenu_PrintUiLabelText(void)
{
    s16 left = 0;
    s16 top = 2;
    FillWindowPixelBuffer(WIN_HMM_LABEL, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(WIN_HMM_LABEL, FONT_SMALL, left, top, 0, 0,
                                 GetInfoboxFontColor(), TEXT_SKIP_DRAW, COMPOUND_STRING("Continue"));
    CopyWindowToVram(WIN_HMM_LABEL, COPYWIN_GFX);

}

static const u8* GetInfoboxFontColor(void)
{
    if (sHearthMainMenuState->activeButton == HMM_BUTTON_INFOBOX) {
        return HearthMainMenuWindowFontColors[FONT_WHITE];
    }
    else {
        return HearthMainMenuWindowFontColors[FONT_GRAY];
    }
}

static u32 GetWinWidth(enum WindowIds id)
{
    return sHearthMainMenuWindowTemplates[id].width;
}

static void HearthMainMenu_FreeResources(void)
{
    if (sHearthMainMenuState != NULL) {
        Free(sHearthMainMenuState);
    }
    if (sBg1TilemapBuffer != NULL) {
        Free(sBg1TilemapBuffer);
    }
    if (sBg2TilemapBuffer != NULL) {
        Free(sBg2TilemapBuffer);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
    ResetTasks();
}
