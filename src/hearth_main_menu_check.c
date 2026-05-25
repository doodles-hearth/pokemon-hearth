#include "global.h"
#include "assertf.h"
#include "bg.h"
#include "constants/characters.h"
#include "constants/rgb.h"
#include "gba/defines.h"
#include "gba/macro.h"
#include "gba/types.h"
#include "gpu_regs.h"
#include "kaba_speech.h"
#include "main.h"
#include "main_menu_hearth.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "rtc.h"
#include "save.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "window.h"

struct PrecheckScreenState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 printState;
};

enum WindowIds {
    WINDOW_0
};

enum TextIds {
    TEXTID_SAVE_ERASED,
    TEXTID_SAVE_CORRUPTED,
    TEXTID_BATTERY_DRY,
};

static EWRAM_DATA struct PrecheckScreenState *sPrecheckScreenState = NULL;

static const struct BgTemplate sPrecheckScreenBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }
};

static const struct WindowTemplate sPrecheckScreenWindowTemplates[] =
{
    [WINDOW_0] =
        {
            .bg = 0,
            .tilemapLeft = 0,
            .tilemapTop = 0,
            .width = 30,
            .height = 20,
            .paletteNum = 15,
            .baseBlock = 1,
        },
    DUMMY_WIN_TEMPLATE};

static const u8 sPrecheckTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

static const u8 sText_SaveFileCorrupted[] = _("The save file is corrupted. The\nprevious save file will be loaded.\p");
static const u8 sText_SaveFileErased[] = _("The save file has been erased\ndue to corruption or damage.\p");
static const u8 sText_BatteryRunDry[] = _("The internal battery has run dry. The game\ncan still be played. However, clock-based\nevents will no longer occur.\p");

static const u8 *const sPrecheckScreenTexts[] = {
    [TEXTID_SAVE_ERASED] = sText_SaveFileErased,
    [TEXTID_SAVE_CORRUPTED] = sText_SaveFileCorrupted,
    [TEXTID_BATTERY_DRY] = sText_BatteryRunDry};

// Callbacks for the prologue screen
static void PrecheckScreen_SetupCB(void);
static void PrecheckScreen_MainCB(void);
static void PrecheckScreen_VBlankCB(void);

// Precheck Screen tasks
static void Task_PrecheckScreenWaitFadeIn(u8 taskId);
static void Task_PrecheckScreenWaitFadeAndExit(u8 taskId);

// Precheck Screen helper functions
static inline void PrecheckScreen_ResetForInit(void);
static void PrecheckScreen_Init(MainCallback callback);
static void PrecheckScreen_ResetGpuRegsAndBgs(void);
static bool8 PrecheckScreen_InitBgs(void);
static void PrecheckScreen_FadeAndBail(void);
static bool8 PrecheckScreen_LoadGraphics(void);
static void PrecheckScreen_InitWindows(void);
static void PrecheckScreen_FreeResources(void);
static const u8 *PrecheckScreen_GetErrorMsg(void);

void CB2_InitPrecheckScreen(void)
{
    PrecheckScreen_Init(CB2_InitMainMenuHearth);
}

static void PrecheckScreen_Init(MainCallback callback)
{
    sPrecheckScreenState = AllocZeroed(sizeof(struct PrecheckScreenState));
    if (sPrecheckScreenState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sPrecheckScreenState->loadState = 0;
    sPrecheckScreenState->savedCallback = callback;

    SetMainCallback2(PrecheckScreen_SetupCB);
}

static inline void PrecheckScreen_ResetForInit(void)
{
    PrecheckScreen_ResetGpuRegsAndBgs();
    SetVBlankHBlankCallbacksToNull();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
}

static void PrecheckScreen_ResetGpuRegsAndBgs(void)
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

static bool32 PrintPrecheckMessage(const u8 *text, u32 x, u32 y)
{
    u32 windowId = WINDOW_0;

    switch (sPrecheckScreenState->printState)
    {
    case 0:
        FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        StringExpandPlaceholders(gStringVar4, text);
        AddTextPrinterParameterized4(windowId, FONT_NORMAL, x, y, 1, 0, sPrecheckTextColors, 1, gStringVar4);
        gTextFlags.canABSpeedUpPrint = FALSE;
        sPrecheckScreenState->printState = 1;
        break;
    case 1:
        if (!IsTextPrinterActiveOnWindow(windowId))
        {
            sPrecheckScreenState->printState = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static void Task_PrecheckScreenPrint(u8 taskId)
{
    if (PrintPrecheckMessage(PrecheckScreen_GetErrorMsg() , 0, 3))
    {
        sPrecheckScreenState->savedCallback = CB2_InitMainMenuHearth;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_PrecheckScreenWaitFadeAndExit;
    }
}

static const u8 *PrecheckScreen_GetErrorMsg(void)
{
    switch (gSaveFileStatus)
    {
    case SAVE_STATUS_CORRUPT:
        return sPrecheckScreenTexts[TEXTID_SAVE_ERASED];

    case SAVE_STATUS_ERROR:
    case SAVE_STATUS_NO_FLASH:
        return sPrecheckScreenTexts[TEXTID_SAVE_CORRUPTED];

    default:
        if (RtcGetErrorStatus() & RTC_ERR_FLAG_MASK)
            return sPrecheckScreenTexts[TEXTID_BATTERY_DRY];
        errorf("Should not reach this point");
        return COMPOUND_STRING("");
    }
}

static void PrecheckScreen_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        PrecheckScreen_ResetForInit();
        gMain.state++;
        break;
    case 1:
        if (PrecheckScreen_InitBgs())
        {
            sPrecheckScreenState->loadState = 0;
            gMain.state++;
        }
        else
        {
            PrecheckScreen_FadeAndBail();
            return;
        }
        break;
    case 2:
        if (PrecheckScreen_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 3:
        PrecheckScreen_InitWindows();
        gMain.state++;
        break;
    case 4:
        CreateTask(Task_PrecheckScreenWaitFadeIn, 0);
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        SetVBlankCallback(PrecheckScreen_VBlankCB);
        SetMainCallback2(PrecheckScreen_MainCB);
        break;
    }
}

static void PrecheckScreen_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void PrecheckScreen_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_PrecheckScreenWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_PrecheckScreenPrint;
    }
}


static void Task_PrecheckScreenWaitFadeAndExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sPrecheckScreenState->savedCallback);
        PrecheckScreen_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 PrecheckScreen_InitBgs(void)
{
    ResetAllBgsCoordinates();

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sPrecheckScreenBgTemplates, NELEMS(sPrecheckScreenBgTemplates));

    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void PrecheckScreen_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_PrecheckScreenWaitFadeAndExit, 0);
    SetVBlankCallback(PrecheckScreen_VBlankCB);
    SetMainCallback2(PrecheckScreen_MainCB);
}

static bool8 PrecheckScreen_LoadGraphics(void)
{
    switch (sPrecheckScreenState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        sPrecheckScreenState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            sPrecheckScreenState->loadState++;
        }
        break;
    case 2:
        Menu_LoadStdPalAt(BG_PLTT_ID(15));
        sPrecheckScreenState->loadState++;
    default:
        sPrecheckScreenState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void PrecheckScreen_InitWindows(void)
{
    InitWindows(sPrecheckScreenWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WINDOW_0, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_0);
    CopyWindowToVram(WINDOW_0, 3);
}

static void PrecheckScreen_FreeResources(void)
{
    if (sPrecheckScreenState != NULL)
    {
        Free(sPrecheckScreenState);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}
