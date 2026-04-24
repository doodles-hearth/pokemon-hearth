#include "global.h"
#include "assertf.h"
#include "bg.h"
#include "constants/characters.h"
#include "constants/event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/flags.h"
#include "constants/global.h"
#include "constants/pokedex.h"
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
#include "m4a.h"
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
#include "region_map.h"
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

enum HmmBgs {
    WIN_HMM_BG = 0,
    WIN_HMM_NO_SAVE = 0,
    WIN_HMM_NAME
};

enum {
    HMM_PALTAG_BUTTON = 0x1000,
    HMM_PALTAG_ACTIVE_BUTTON = 0x1001,
    HMM_PALTAG_PLAYER = 0x1002,
    HMM_PALTAG_BADGES1 = 0x1003,
    HMM_PALTAG_BADGES2 = 0x1004,
};

enum HmmTokens {
    BOTTLED_TOKEN,
    CARVED_TOKEN,
    SEWN_TOKEN,
    FORGED_TOKEN,
    CAPTURED_TOKEN,
    FOLDED_TOKEN,
    POLISHED_TOKEN,
    CHERISHED_TOKEN,
};

enum HmmTileTags {
    HMM_TILETAG_BUTTON1  = 0x2000,
    HMM_TILETAG_BUTTON2  = 0x2001,
    HMM_TILETAG_BUTTON3  = 0x2002,
    HMM_TILETAG_PLAYER   = 0x2003,
    HMM_TILETAG_BOTTLED  = 0x2004,
    HMM_TILETAG_CARVED   = 0x2005,
    HMM_TILETAG_SEWN     = 0x2006,
    HMM_TILETAG_FORGED   = 0x2007,
    HMM_TILETAG_CAPTURED = 0x2008,
    HMM_TILETAG_FOLDED   = 0x2009,
    HMM_TILETAG_POLISHED = 0x200A,
    HMM_TILETAG_FANG     = 0x200B,
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

struct HmmState {
    MainCallback savedCallback;
    enum HmmMenuType menuType;
    u8 loadState;
    u8 partyIconId[PARTY_SIZE];
    u8 playerSpriteId;
    u8 buttonSpriteId[HMM_BUTTON_SPRITE_COUNT];
    enum HmmButtonIds activeButton;
    enum HmmButtonIds prevButton;
};

struct HmmMemory {
    struct HmmState state;
    u8 sBg1TilemapBuffer[2048];
    u8 sBg2TilemapBuffer[2048];
    ALIGNED(4) u16 sTempPaletteBuffer[PLTT_BUFFER_SIZE];
};

static EWRAM_DATA struct HmmMemory* sHmmMemory = NULL;

static const struct BgTemplate sHmmBgTemplates[] = {
    {.bg = 0, .charBaseIndex = 0, .mapBaseIndex = 30, .priority = 1},
    {.bg = 1, .charBaseIndex = 3, .mapBaseIndex = 31, .priority = 2},
    {.bg = 2, .charBaseIndex = 2, .mapBaseIndex = 29, .priority = 3},
};

static const struct WindowTemplate sHmmWindowTemplates[] = {
    [WIN_HMM_BG] =
        {.bg = 0, .tilemapLeft = 4, .tilemapTop = 11, .width = 22, .height = 3, .paletteNum = 15, .baseBlock = 1},

    [WIN_HMM_NAME] =
        {.bg = 0, .tilemapLeft = 2, .tilemapTop = 9, .width = 8, .height = 2, .paletteNum = 15, .baseBlock = 1 + 66},
    DUMMY_WIN_TEMPLATE};

static const struct WindowTemplate sHmmErrorWindowTemplate[] = {
    [0] = {.bg = 0, .tilemapLeft = 4, .tilemapTop = 5, .width = 22, .height = 3, .paletteNum = 15, .baseBlock = 1},
    DUMMY_WIN_TEMPLATE};

static const u32 HmmBgTiles[] = INCBIN_U32("graphics/main_menu_hearth/main_bg/tiles.4bpp.smol");
static const u32 HmmBgTilemap[] = INCBIN_U32("graphics/main_menu_hearth/main_bg/map.bin.smolTM");
static const u16 HmmBgPalette[] = INCBIN_U16("graphics/main_menu_hearth/main_bg/inactive.gbapal");
static const u16 HmmBgActivePalette[] = INCBIN_U16("graphics/main_menu_hearth/main_bg/active.gbapal");
static const u16 HmmMsgboxPal[] = INCBIN_U16("graphics/main_menu_hearth/main_bg/msgbox.gbapal");

static const u32 HmmScrollingBgTiles[] = INCBIN_U32("graphics/main_menu_hearth/scrolling_bg/tiles.4bpp.smol");
static const u32 HmmScrollingBgTilemap[] = INCBIN_U32("graphics/main_menu_hearth/scrolling_bg/map.bin.smolTM");
static const u16 HmmScrollingBgPalette[] = INCBIN_U16("graphics/main_menu_hearth/scrolling_bg/scrolling_bg.gbapal");

static const u32 sMenuButtonGfx[] = INCBIN_U32("graphics/main_menu_hearth/buttons/button.4bpp.smol");
static const u16 sMenuButtonPal[] = INCBIN_U16("graphics/main_menu_hearth/buttons/inactive.gbapal");
static const u16 sMenuButtonActivePal[] = INCBIN_U16("graphics/main_menu_hearth/buttons/active.gbapal");

static const u32 sMenuBottledTokenGfx[] = INCBIN_U32("graphics/main_menu_hearth/badges/bottled.4bpp.smol");
static const u32 sMenuCarvedTokenGfx[] = INCBIN_U32("graphics/main_menu_hearth/badges/carved.4bpp.smol");
static const u32 sMenuSewnTokenGfx[] = INCBIN_U32("graphics/main_menu_hearth/badges/sewn.4bpp.smol");
static const u32 sMenuForgedTokenGfx[] = INCBIN_U32("graphics/main_menu_hearth/badges/forged.4bpp.smol");
static const u32 sMenuCapturedTokenGfx[] = INCBIN_U32("graphics/main_menu_hearth/badges/captured.4bpp.smol");
static const u32 sMenuFoldedTokenGfx[] = INCBIN_U32("graphics/main_menu_hearth/badges/folded.4bpp.smol");
static const u32 sMenuPolishedTokenGfx[] = INCBIN_U32("graphics/main_menu_hearth/badges/polished.4bpp.smol");
static const u32 sMenuCherishedTokenGfx[] = INCBIN_U32("graphics/main_menu_hearth/badges/cherished.4bpp.smol");
static const u16 sMenuBadgesPal1[] = INCBIN_U16("graphics/main_menu_hearth/badges/badges1.gbapal");
static const u16 sMenuBadgesPal2[] = INCBIN_U16("graphics/main_menu_hearth/badges/badges2.gbapal");

static const u32 sPlayerAoGfx[] = INCBIN_U32("graphics/main_menu_hearth/mugshots/ao.4bpp.smol");
static const u16 sPlayerAoPal[] = INCBIN_U16("graphics/main_menu_hearth/mugshots/ao.gbapal");
static const u32 sPlayerAkaGfx[] = INCBIN_U32("graphics/main_menu_hearth/mugshots/aka.4bpp.smol");
static const u16 sPlayerAkaPal[] = INCBIN_U16("graphics/main_menu_hearth/mugshots/aka.gbapal");

enum FontColor { FONT_WHITE, FONT_GRAY, FONT_PLAYER };
static const u8 HmmWindowFontColors[][3] = {
    [FONT_WHITE] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY},
    [FONT_GRAY] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_LIGHT_GRAY, TEXT_COLOR_DARK_GRAY},
    [FONT_PLAYER] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY, TEXT_DYNAMIC_COLOR_2},
};

static const u16 sDynamicTextColor[] = {
    [TEXT_DYNAMIC_COLOR_1]   = 0x000035D2,
    [TEXT_DYNAMIC_COLOR_2]   = 0x35D2,
};

#define HMM_FONT_COLOR(_x) HmmWindowFontColors[_x]

// Callbacks
static void Hmm_SetupCB(void);
static void Hmm_MainCB(void);
static void Hmm_VBlankCB(void);

// Tasks
static void Task_HmmWaitFadeIn(u8 taskId);
static void Task_HmmInput(u8 taskId);
static void Task_HmmWaitFadeAndBail(u8 taskId);
static void Task_HmmWaitFadeAndExitGracefully(u8 taskId);
static void Task_HmmScrollBg(u8 taskId);

// Helper Functions
static inline void Hmm_ResetForInit(void);
static void Hmm_Init(MainCallback callback, enum HmmButtonIds activeButton);
static void Hmm_ResetGpuRegsAndBgs(void);
static bool8 Hmm_InitBgs(void);
static bool8 Hmm_LoadGraphics(void);
static void Hmm_InitWindows(void);
static void Hmm_StartFade(u32 color);
static void Hmm_FadeAndBail(void);
static void Hmm_FreeResources(void);
static enum HmmMenuType Hmm_GetMenuType(void);
static void Hmm_DrawContinueMenuItems(void);
static bool32 Hmm_IsContinueMenu(void);

static void Hmm_PrintInfoboxText(void);
static void Hmm_PrintContinueInfo(const u8 *color);
static void Hmm_PrintNoSaveInfo(const u8 *color);
static void Hmm_FormatSavegameTime(void);
static void Hmm_PrintPlayerName(void);
static const u8* Hmm_GetInfoboxFontColor(void);
static const u8* Hmm_GetPlayerNameFontColor(void);
static u32 Hmm_GetWindowWidth(u8 windowId);
static void Hmm_PrintText(u8 windowId, u8 font, u8 x, u8 y, const u8 *color, const u8 *str);
static inline void Hmm_PrintTextNormal(u8 windowId, u8 x, u8 y, const u8 *color, const u8 *str);
static inline void Hmm_PrintTextSmall(u8 windowId, u8 x, u8 y, const u8 *color, const u8 *str);

static void Hmm_CreatePlayerMugshot(s16 x, s16 y);
static void Hmm_DarkenPlayerMugshot(void);
static void Hmm_RestorePlayerMugshot(void);
static void Hmm_DrawPartyIcons(void);
static void Hmm_DarkenPartyIcons(void);

static u32 Hmm_CreateMenuButton(s16 x, s16 y, u32 tileTag, u32 palTag);
static void Hmm_CreateAllMenuButtons();
static void Hmm_PrintButtonLabels(void);
static bool32 Hmm_IsSpriteButton(enum HmmButtonIds buttonId);

static u32 Hmm_CreateMenuBadge(s16 x, s16 y, enum HmmTokens token);
static void Hmm_CreateAllBadges(s16 x, s16 y);
static void Hmm_DarkenBadges(void);
static void Hmm_RestoreBadges(void);
static u32 Hmm_GetTokenCount(void);
static u16 Hmm_GetBadgePalTag(enum HmmTokens token);
static const u16* Hmm_GetBadgePal(enum HmmTokens token);
static const u32* Hmm_GetBadgeGfx(enum HmmTokens token);

static void Hmm_SetInfoboxActive(bool32 active);
static void Hmm_SetButtonPalette(u8 buttonId, const u16* pal, u32 palTag);
static void Hmm_ActivateButton(enum HmmButtonIds buttonId);
static void Hmm_DeactivateButton(enum HmmButtonIds buttonId);
static void Hmm_SetActiveButton(enum HmmButtonIds buttonId);
static void Hmm_MoveSelection(enum HmmDirs);

static void Hmm_HandleButtonPressA(void);
static void Hmm_HandleButtonPressB(void);
static void Hmm_ExitOnSelect(MainCallback callback);

void CB2_InitMainMenuHearth(void)
{
    Hmm_Init(CB2_InitHearthTitleScreen, HMM_BUTTON_INFOBOX);
}

static void CB2_InitMainMenuHearthFromOptionsMenu(void)
{
    Hmm_Init(CB2_InitHearthTitleScreen, HMM_BUTTON_OPTIONS);
}

static void Hmm_Init(MainCallback callback, enum HmmButtonIds activeButton)
{
    sHmmMemory = AllocZeroed(sizeof(struct HmmMemory));
    if (sHmmMemory == NULL) {
        SetMainCallback2(callback);
        return;
    }

    sHmmMemory->state.loadState = 0;
    sHmmMemory->state.savedCallback = callback;
    sHmmMemory->state.activeButton = activeButton;
    sHmmMemory->state.menuType = Hmm_GetMenuType();

    SetMainCallback2(Hmm_SetupCB);
}

static bool32 Hmm_IsContinueMenu(void)
{
    return sHmmMemory->state.menuType == HMM_HAS_SAVE;
}

static void Hmm_ResetGpuRegsAndBgs(void)
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

static inline void Hmm_ResetForInit(void)
{
    Hmm_ResetGpuRegsAndBgs();
    SetVBlankHBlankCallbacksToNull();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
}

static void Hmm_SetupCB(void)
{
    switch (gMain.state) {
        case 0:
            Hmm_ResetForInit();
            gMain.state++;
            break;
        case 1:
            if (Hmm_InitBgs()) {
                sHmmMemory->state.loadState = 0;
                gMain.state++;
            }
            else {
                Hmm_FadeAndBail();
                return;
            }
            break;
        case 2:
            if (Hmm_LoadGraphics() == TRUE) {
                gMain.state++;
            }
            break;
        case 3:
            Hmm_InitWindows();
            gMain.state++;
            break;
        case 4:
            Hmm_DrawContinueMenuItems();
            gMain.state++;
            break;
        case 5:
            Hmm_CreateAllMenuButtons();
            gMain.state++;
            break;
        case 6:
            Hmm_PrintButtonLabels();
            if (!Hmm_IsContinueMenu() && sHmmMemory->state.activeButton == HMM_BUTTON_INFOBOX) {
                sHmmMemory->state.activeButton = HMM_BUTTON_NEWGAME;
            }
            Hmm_SetActiveButton(sHmmMemory->state.activeButton);
            gMain.state++;
            break;
        case 7:
                CpuFastCopy(gPlttBufferUnfaded, sHmmMemory->sTempPaletteBuffer, sizeof(gPlttBufferUnfaded));
                CpuFastCopy(gPlttBufferFaded, gPlttBufferUnfaded, sizeof(gPlttBufferFaded));
            BeginNormalPaletteFade(PALETTES_ALL, 1, 16, 0, RGB_BLACK);
            CreateTask(Task_HmmWaitFadeIn, 0);
            gMain.state++;
            break;
        case 8:
            CreateTask(Task_HmmScrollBg, 0);
            SetVBlankCallback(Hmm_VBlankCB);
            SetMainCallback2(Hmm_MainCB);
            break;
    }
}


static enum HmmMenuType Hmm_GetMenuType(void)
{
    switch (gSaveFileStatus) {
        case SAVE_STATUS_OK:
        case SAVE_STATUS_ERROR:
            return HMM_HAS_SAVE;
        default:
            return HMM_NO_SAVE;
    }
}

static void Task_HmmScrollBg(u8 taskId)
{
    s16* tAccumulator = &gTasks[taskId].data[0];

    *tAccumulator += 104;

    s16 pixels = *tAccumulator >> 8;
    *tAccumulator &= 0xFF;

    if (pixels != 0) {
        ChangeBgX(2, pixels << 8, BG_COORD_ADD);
        ChangeBgY(2, pixels << 8, BG_COORD_ADD);
    }
}

static void Hmm_DrawContinueMenuItems(void)
{
    if (!Hmm_IsContinueMenu())
        return;
    Hmm_CreatePlayerMugshot(16, 9);
    FreeMonIconPalettes();
    LoadMonIconPalettes();
    Hmm_DrawPartyIcons();
    Hmm_CreateAllBadges(91, 21);
}

static void Hmm_CreateAllMenuButtons()
{
    const s16 startX = 8 + 32;
    const s16 startY = 120 + 16;

    for (u32 i = 0; i < HMM_BUTTON_SPRITE_COUNT; i++) {
        s16 x;
        x = startX + (i * 64 + i*16);
        sHmmMemory->state.buttonSpriteId[i] =
            Hmm_CreateMenuButton(x, startY, HMM_TILETAG_BUTTON1 + i, HMM_PALTAG_BUTTON);
    }
}

static void Hmm_CreatePlayerMugshot(s16 x, s16 y)
{
    const u32* playerSprite = gSaveBlock2Ptr->playerGender == FEMALE ? sPlayerAoGfx : sPlayerAkaGfx;
    const u16* playerPal = gSaveBlock2Ptr->playerGender == FEMALE ? sPlayerAoPal : sPlayerAkaPal;
    x+=32;
    y+=32;
    Even_CreateSpriteParametrized(playerSprite, HMM_TILETAG_PLAYER, playerPal, HMM_PALTAG_PLAYER, SPRITE_SIZE(64x64), SPRITE_SHAPE(64x64), x, y, 0, SpriteCallbackDummy, TRUE);
}

static void Hmm_DarkenPlayerMugshot(void)
{
    u16 index = IndexOfSpritePaletteTag(HMM_PALTAG_PLAYER);
    BlendPalette(OBJ_PLTT_ID(index), 16, 8, RGB_BLACK);
}

static void Hmm_RestorePlayerMugshot(void)
{
    FreeSpritePaletteByTag(HMM_PALTAG_PLAYER);
    LoadSpritePaletteWithTag(sPlayerAoPal, HMM_PALTAG_PLAYER);
}

static u32 Hmm_CreateMenuBadge(s16 x, s16 y, enum HmmTokens token)
{
    u8 tileTag = HMM_TILETAG_BOTTLED + token;
    u32 spriteId =  Even_CreateSpriteParametrized(Hmm_GetBadgeGfx(token), tileTag, Hmm_GetBadgePal(token), Hmm_GetBadgePalTag(token), SPRITE_SIZE(16x16),
                                         SPRITE_SHAPE(16x16), x, y, 0, SpriteCallbackDummy, TRUE);
    return spriteId;
}

static const u32* Hmm_GetBadgeGfx(enum HmmTokens token)
{
    switch (token) {
        case BOTTLED_TOKEN:   return sMenuBottledTokenGfx;
        case CARVED_TOKEN:    return sMenuCarvedTokenGfx;
        case SEWN_TOKEN:      return sMenuSewnTokenGfx;
        case FORGED_TOKEN:    return sMenuForgedTokenGfx;
        case CAPTURED_TOKEN:  return sMenuCapturedTokenGfx;
        case FOLDED_TOKEN:    return sMenuFoldedTokenGfx;
        case POLISHED_TOKEN:  return sMenuPolishedTokenGfx;
        case CHERISHED_TOKEN: return sMenuCherishedTokenGfx;
        default:              return sMenuBottledTokenGfx;
    }
}

static const u16* Hmm_GetBadgePal(enum HmmTokens token)
{
    switch (token) {
        case CARVED_TOKEN:
        case SEWN_TOKEN:
            return sMenuBadgesPal2;
        default:
            return sMenuBadgesPal1;
    }
}
static u16 Hmm_GetBadgePalTag(enum HmmTokens token)
{
    switch (token) {
        case CARVED_TOKEN:
        case SEWN_TOKEN:
            return HMM_PALTAG_BADGES2;
        default:
            return HMM_PALTAG_BADGES1;
    }
}

static void Hmm_CreateAllBadges(s16 x, s16 y)
{
    u32 badgeCount = Hmm_GetTokenCount();
    for (u32 i = 0; i < badgeCount; i++) {
        x+= !!i*2;
        Hmm_CreateMenuBadge(x + i * 16, y, i);
    }
}

static void Hmm_DarkenBadges(void)
{
    u16 index1 = IndexOfSpritePaletteTag(HMM_PALTAG_BADGES1);
    u16 index2 = IndexOfSpritePaletteTag(HMM_PALTAG_BADGES2);
    BlendPalette(OBJ_PLTT_ID(index1), 16, 8, RGB_BLACK);
    BlendPalette(OBJ_PLTT_ID(index2), 16, 8, RGB_BLACK);
}


static void Hmm_RestoreBadges(void)
{
    FreeSpritePaletteByTag(HMM_PALTAG_BADGES1);
    FreeSpritePaletteByTag(HMM_PALTAG_BADGES2);
    LoadSpritePaletteWithTag(sMenuBadgesPal1, HMM_PALTAG_BADGES1);
    LoadSpritePaletteWithTag(sMenuBadgesPal2, HMM_PALTAG_BADGES2);
}

static u32 Hmm_GetTokenCount(void)
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

static u32 Hmm_CreateMenuButton(s16 x, s16 y, u32 tileTag, u32 palTag)
{
    return Even_CreateSpriteParametrized(sMenuButtonGfx, tileTag, sMenuButtonPal, palTag, SPRITE_SIZE(64x32),
                                         SPRITE_SHAPE(64x32), x, y, 0, SpriteCallbackDummy, TRUE);
}

static void Hmm_SetButtonPalette(u8 buttonId, const u16* pal, u32 palTag)
{
    struct SpritePalette sp;
    sp.data = pal;
    sp.tag = palTag;
    LoadSpritePalette(&sp);
    u8 palIndex = IndexOfSpritePaletteTag(palTag);
    gSprites[buttonId].oam.paletteNum = palIndex;
}

static void Hmm_ActivateButton(enum HmmButtonIds buttonId)
{
    if (!Hmm_IsSpriteButton(buttonId))
        return;

    u8 spriteId = sHmmMemory->state.buttonSpriteId[buttonId];
    Hmm_SetButtonPalette(spriteId, sMenuButtonActivePal, HMM_PALTAG_ACTIVE_BUTTON);
}

static void Hmm_DeactivateButton(enum HmmButtonIds buttonId)
{
    if (!Hmm_IsSpriteButton(buttonId))
        return;

    u8 spriteId = sHmmMemory->state.buttonSpriteId[buttonId];
    Hmm_SetButtonPalette(spriteId, sMenuButtonPal, HMM_PALTAG_BUTTON);
}

static void Hmm_SetActiveButton(enum HmmButtonIds buttonId)
{
    if (buttonId < 0)
        buttonId = HMM_BUTTON_COUNT - 1;
    else if (buttonId >= HMM_BUTTON_COUNT)
        buttonId = 0;

    sHmmMemory->state.prevButton = sHmmMemory->state.activeButton;
    sHmmMemory->state.activeButton = buttonId;

    Hmm_DeactivateButton(sHmmMemory->state.prevButton);

    if (buttonId == HMM_BUTTON_INFOBOX) {
        Hmm_SetInfoboxActive(TRUE);
    }
    else {
        Hmm_SetInfoboxActive(FALSE);
        Hmm_ActivateButton(buttonId);
    }
    Hmm_PrintButtonLabels();
}

static bool32 Hmm_IsSpriteButton(enum HmmButtonIds buttonId)
{
    return buttonId != HMM_BUTTON_INFOBOX && buttonId < HMM_BUTTON_COUNT;
}


static const union TextColor sButtonTextColorActive = {.background = 0, .foreground = 9, .shadow = 10, .accent = 0};
static const union TextColor sButtonTextColor = {.background = 0, .foreground = 9, .shadow = 10, .accent = 0};

static const u8* const sButtonTexts[3] = {
    [HMM_BUTTON_NEWGAME] = COMPOUND_STRING("New Game"),   [HMM_BUTTON_OPTIONS] = COMPOUND_STRING("Options"),
    [HMM_BUTTON_MYSTERY] = COMPOUND_STRING("Mystery Gift"), };

static void Hmm_PrintButtonLabels(void)
{
    for (u32 i = 0; i < 3; i++) {

        u8 fontId = FONT_SMALL_NARROW;

        if (GetStringWidth(FONT_SMALL_NARROW, sButtonTexts[i], 0) > 50) {
            fontId = FONT_SMALL_NARROWER; 
        }
        u8 spriteId = sHmmMemory->state.buttonSpriteId[i];
        u32 left = GetStringCenterAlignXOffset(fontId, sButtonTexts[i], 64);
        const union TextColor* color = (sHmmMemory->state.activeButton == i) ? &sButtonTextColorActive : &sButtonTextColor;
        AddSpriteTextPrinterParameterized6(spriteId, fontId, left, 8, 0, 0, *color, 0, sButtonTexts[i]);
    }
}

static void Hmm_MoveSelection(enum HmmDirs direction)
{
    enum HmmButtonIds cur = sHmmMemory->state.activeButton;

    switch (direction) {
        case HMM_DIR_UP:
            if (cur != HMM_BUTTON_INFOBOX && Hmm_IsContinueMenu())
                Hmm_SetActiveButton(HMM_BUTTON_INFOBOX);
            break;

        case HMM_DIR_DOWN:
            if (cur == HMM_BUTTON_INFOBOX) {
                    Hmm_SetActiveButton(HMM_BUTTON_NEWGAME);
            }
            break;

        case HMM_DIR_LEFT:
            if (cur == HMM_BUTTON_INFOBOX)
                break;
            if (cur == HMM_BUTTON_NEWGAME)
                Hmm_SetActiveButton(HMM_BUTTON_MYSTERY);
            else
                Hmm_SetActiveButton(cur - 1);
            break;

        case HMM_DIR_RIGHT:
            if (cur == HMM_BUTTON_INFOBOX)
                break;
            if (cur == HMM_BUTTON_MYSTERY)
                Hmm_SetActiveButton(HMM_BUTTON_NEWGAME);
            else
                Hmm_SetActiveButton(cur + 1);
            break;
    }
}

static void Hmm_DrawPartyIcons(void)
{
    const u16 startX = 100;
    const u16 startY = 44;

    for (u32 i = 0; i < PARTY_SIZE; i++) {
        u16 speciesId = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (speciesId == SPECIES_NONE) {
            sHmmMemory->state.partyIconId[i] = SPRITE_NONE;
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

        sHmmMemory->state.partyIconId[i] = CreateMonIcon(speciesId, SpriteCB_MonIcon, x, y, 4, personality);

        gSprites[sHmmMemory->state.partyIconId[i]].oam.priority = 0;
    }
}

static void Hmm_DarkenPartyIcons(void)
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

static void Hmm_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Hmm_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_HmmWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active) {
        CpuFastCopy(sHmmMemory->sTempPaletteBuffer, gPlttBufferUnfaded, sizeof(gPlttBufferUnfaded));
        /* m4aSongNumStart(MUS_UNDERWATER); */
        PlayBGM(MUS_UNDERWATER);
        gTasks[taskId].func = Task_HmmInput;
    }
}

static void Hmm_StartFade(u32 color)
{
    CpuFastCopy(gPlttBufferFaded, gPlttBufferUnfaded, sizeof(gPlttBufferFaded));
    FadeOutBGM(4);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, color);
}

static void Task_HmmInput(u8 taskId)
{
    if (JOY_NEW(B_BUTTON)) {
        Hmm_HandleButtonPressB();
    }
    if (JOY_NEW(A_BUTTON)) {
        Hmm_HandleButtonPressA();
    }
    if (JOY_NEW(DPAD_UP)) {
        PlaySE(SE_SELECT);
        Hmm_MoveSelection(HMM_DIR_UP);
    }
    if (JOY_NEW(DPAD_DOWN)) {
        PlaySE(SE_SELECT);
        Hmm_MoveSelection(HMM_DIR_DOWN);
    }
    if (JOY_NEW(DPAD_LEFT)) {
        PlaySE(SE_SELECT);
        Hmm_MoveSelection(HMM_DIR_LEFT);
    }
    if (JOY_NEW(DPAD_RIGHT)) {
        PlaySE(SE_SELECT);
        Hmm_MoveSelection(HMM_DIR_RIGHT);
    }
}

static void Hmm_HandleButtonPressA(void)
{
    switch (sHmmMemory->state.activeButton) {
        case HMM_BUTTON_INFOBOX:
            Hmm_ExitOnSelect(CB2_ContinueSavedGame);
            break;

        case HMM_BUTTON_NEWGAME:
            Hmm_ExitOnSelect(CB2_InitPrologueScreen);
            break;

        case HMM_BUTTON_OPTIONS:
            gMain.savedCallback = CB2_InitMainMenuHearthFromOptionsMenu;
            Hmm_ExitOnSelect(CB2_InitOptionMenu);
            break;

        default:
            PlaySE(SE_FAILURE);
            break;
    }
}

static void Hmm_HandleButtonPressB(void)
{
    u8 taskId = FindTaskIdByFunc(Task_HmmInput);
    PlaySE(SE_PC_OFF);
    Hmm_StartFade(RGB_BLACK);
    gTasks[taskId].func = Task_HmmWaitFadeAndExitGracefully;
}

static void Hmm_ExitOnSelect(MainCallback callback)
{
    u8 taskId = FindTaskIdByFunc(Task_HmmInput);
    PlaySE(SE_SELECT);
    Hmm_StartFade(RGB_BLACK);
    sHmmMemory->state.savedCallback = callback;
    gTasks[taskId].func = Task_HmmWaitFadeAndExitGracefully;
}

static void Hmm_SetInfoboxActive(bool32 active)
{
    if (active) {
        LoadPalette(HmmBgActivePalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        gSprites[sHmmMemory->state.playerSpriteId].animPaused = FALSE;
        FreeMonIconPalettes();
        LoadMonIconPalettes();
        Hmm_RestorePlayerMugshot();
        Hmm_RestoreBadges();
        for (u32 i = 0; i < PARTY_SIZE; i++) {
            u8 id = sHmmMemory->state.partyIconId[i];
            struct Sprite* sprite = &gSprites[id];
            if (sprite->inUse) {
                sprite->callback = SpriteCB_MonIcon;
            }
        }
    }
    else {
        LoadPalette(HmmBgPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        gSprites[sHmmMemory->state.playerSpriteId].animPaused = TRUE;
        Hmm_DarkenPartyIcons();
        Hmm_DarkenPlayerMugshot();
        Hmm_DarkenBadges();
        for (u32 i = 0; i < PARTY_SIZE; i++) {
            u8 id = sHmmMemory->state.partyIconId[i];
            struct Sprite* sprite = &gSprites[id];
            if (sprite->inUse) {
                sprite->callback = SpriteCallbackDummy;
            }
        }
    }
    Hmm_PrintInfoboxText();
}

static void Task_HmmWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active) {
        SetMainCallback2(sHmmMemory->state.savedCallback);
        Hmm_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_HmmWaitFadeAndExitGracefully(u8 taskId)
{
    if (!gPaletteFade.active) {
        SetMainCallback2(sHmmMemory->state.savedCallback);
        Hmm_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 Hmm_InitBgs(void)
{
    ResetAllBgsCoordinates();

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sHmmBgTemplates, NELEMS(sHmmBgTemplates));

    SetBgTilemapBuffer(1, sHmmMemory->sBg1TilemapBuffer);
    SetBgTilemapBuffer(2, sHmmMemory->sBg2TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void Hmm_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_HmmWaitFadeAndBail, 0);
    SetVBlankCallback(Hmm_VBlankCB);
    SetMainCallback2(Hmm_MainCB);
}

static bool8 Hmm_LoadGraphics(void)
{
    switch (sHmmMemory->state.loadState) {
        case 0:
            ResetTempTileDataBuffers();
            DecompressAndCopyTileDataToVram(1, HmmBgTiles, 0, 0, 0);
            DecompressAndCopyTileDataToVram(2, HmmScrollingBgTiles, 0, 0, 0);
            sHmmMemory->state.loadState++;
            break;
        case 1:
            if (FreeTempTileDataBuffersIfPossible() != TRUE) {
                DecompressDataWithHeaderWram(HmmBgTilemap, sHmmMemory->sBg1TilemapBuffer);
                sHmmMemory->state.loadState++;
            }
            break;
        case 2:
            if (FreeTempTileDataBuffersIfPossible() != TRUE) {
                DecompressDataWithHeaderWram(HmmScrollingBgTilemap, sHmmMemory->sBg2TilemapBuffer);
                sHmmMemory->state.loadState++;
            }
            break;
        case 3:
            LoadPalette(HmmBgPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
            LoadPalette(HmmScrollingBgPalette, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
            LoadPalette(HmmMsgboxPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
            sHmmMemory->state.loadState++;
        default:
            sHmmMemory->state.loadState = 0;
            return TRUE;
    }
    return FALSE;
}

static void Hmm_InitWindows(void)
{
    if (!Hmm_IsContinueMenu()) {
        InitWindows(sHmmErrorWindowTemplate);
        return;
    }

    InitWindows(sHmmWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    for (u32 i = 0; i <= NELEMS(sHmmWindowTemplates); i++) {
        FillWindowPixelBuffer(i, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        PutWindowTilemap(i);
        CopyWindowToVram(i, 3);
    }
}

static void Hmm_PrintText(u8 windowId, u8 font, u8 x, u8 y, const u8* color, const u8* str)
{
    AddTextPrinterParameterized4(windowId, font, x, y, 0, 0, color, TEXT_SKIP_DRAW, str);
}

static inline void Hmm_PrintTextSmall(u8 windowId, u8 x, u8 y, const u8* color, const u8* str)
{
    Hmm_PrintText(windowId, FONT_SMALL, x, y, color, str);
}

static inline void Hmm_PrintTextNormal(u8 windowId, u8 x, u8 y, const u8* color, const u8* str)
{
    Hmm_PrintText(windowId, FONT_NORMAL, x, y, color, str);
}

static const u8 sText_DexCount[] = _("Dex  {STR_VAR_2}");
static const u8 sText_NoSaveData[] = _("No Save Data Found");
static void Hmm_PrintContinueInfo(const u8 *color)
{
    u8 windowId = WIN_HMM_BG;
    u16 widthPx = Hmm_GetWindowWidth(windowId) * 8;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    Hmm_FormatSavegameTime();
    Hmm_PrintTextSmall(windowId, 0, 0, color, gStringVar1);

    GetMapName(gStringVar1, GetCurrentRegionMapSectionId(), 0);
    u8 fontId = GetFontIdToFit(gStringVar1, FONT_SMALL, 0, widthPx/3);
    u8 xName = GetStringCenterAlignXOffset(fontId, gStringVar1, widthPx);
    Hmm_PrintText(windowId, fontId, xName, 0, color, gStringVar1);

    ConvertUIntToDecimalStringN(gStringVar2, GetRegionalPokedexCount(FLAG_GET_CAUGHT), STR_CONV_MODE_LEFT_ALIGN, 1);
    StringExpandPlaceholders(gStringVar1, sText_DexCount);
    u8 xTokens = GetStringRightAlignXOffset(FONT_SMALL, gStringVar1, widthPx);
    Hmm_PrintTextSmall(windowId, xTokens, 0, color, gStringVar1);

    Hmm_PrintPlayerName();

    CopyWindowToVram(windowId, COPYWIN_GFX);
}

static void Hmm_PrintNoSaveInfo(const u8 *color)
{
    u8 windowId = WIN_HMM_NO_SAVE;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(windowId);

    u16 widthPx = GetWindowAttribute(windowId, WINDOW_WIDTH) * 8;
    u8 x = GetStringCenterAlignXOffset(FONT_NORMAL, sText_NoSaveData, widthPx);

    Hmm_PrintTextNormal(windowId, x, 0, color, sText_NoSaveData);

    CopyWindowToVram(windowId, COPYWIN_FULL);
}

static void Hmm_PrintInfoboxText(void)
{
    const u8 *color = Hmm_GetInfoboxFontColor();
    if (Hmm_IsContinueMenu())
        Hmm_PrintContinueInfo(color);
    else
        Hmm_PrintNoSaveInfo(color);
}

static void Hmm_FormatSavegameTime(void)
{
    ConvertIntToDecimalStringN(gStringVar2, gSaveBlock2Ptr->playTimeHours, STR_CONV_MODE_LEFT_ALIGN, 3);
    ConvertIntToDecimalStringN(gStringVar3, gSaveBlock2Ptr->playTimeMinutes, STR_CONV_MODE_LEADING_ZEROS, 2);
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("Time  {STR_VAR_2}:{STR_VAR_3}"));
}

static void Hmm_PrintPlayerName(void)
{
    StringExpandPlaceholders(gStringVar1, COMPOUND_STRING("{PLAYER}"));
    FillWindowPixelBuffer(WIN_HMM_NAME, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    u8 xName = GetStringCenterAlignXOffset(FONT_SMALL, gStringVar1, Hmm_GetWindowWidth(WIN_HMM_NAME)*8);
    Hmm_PrintTextSmall(WIN_HMM_NAME, xName, 0, Hmm_GetPlayerNameFontColor(), gStringVar1);
    CopyWindowToVram(WIN_HMM_NAME, COPYWIN_GFX);

}

static const u8* Hmm_GetInfoboxFontColor(void)
{
    if (sHmmMemory->state.activeButton == HMM_BUTTON_INFOBOX) {
        return HMM_FONT_COLOR(FONT_WHITE);
    }
    else {
        return HMM_FONT_COLOR(FONT_GRAY);
    }
}

static const u8* Hmm_GetPlayerNameFontColor(void)
{
    if (sHmmMemory->state.activeButton == HMM_BUTTON_INFOBOX) {
        return HMM_FONT_COLOR(FONT_PLAYER);
    }
    else {
        return HMM_FONT_COLOR(FONT_GRAY);
    }
}
static u32 Hmm_GetWindowWidth(u8 windowId)
{
    return GetWindowAttribute(windowId, WINDOW_WIDTH);
}

static void Hmm_FreeResources(void)
{
    TRY_FREE_AND_SET_NULL(sHmmMemory);
    FreeAllWindowBuffers();
    FreeAllSpritePalettes();
    ResetSpriteData();
    ResetTasks();
}
