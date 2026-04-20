#include "gba/types.h"
#include "gba/defines.h"
#include "global.h"
#include "kaba_speech.h"
#include "main.h"
#include "bg.h"
#include "main_menu_hearth.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/characters.h"
#include "palette.h"
#include "task.h"
#include "overworld.h"
#include "malloc.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "menu.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "data.h"
#include "pokedex.h"
#include "gpu_regs.h"
#include "prologue_screen.h"

struct PrologueScreenState
{
    MainCallback savedCallback;
    u8 loadState;
    u8 printState;
};

enum WindowIds
{
    WINDOW_0
};

static EWRAM_DATA struct PrologueScreenState *sPrologueScreenState = NULL;

static const struct BgTemplate sPrologueScreenBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }
};

static const struct WindowTemplate sPrologueScreenWindowTemplates[] =
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

static const u8 sPrologueTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

const u8 sText_Prologue[] = _(
    "This is a demo for {COLOR LIGHT_RED}{SHADOW RED}Pokémon Hearth{COLOR WHITE}{SHADOW DARK_GRAY}!{PAUSE 16}\n"
    "This game is FREE.{PAUSE 16}\nIf you paid for it, you got scammed.{PAUSE 48}\n\n"
    "TO AVOID PLAYING AN OUTDATED GAME,{PAUSE 16}\n"
    "MAKE SURE YOU GOT THE HACK FROM\n"
    "THE {COLOR LIGHT_RED}{SHADOW RED}HACKDEX{COLOR WHITE}{SHADOW DARK_GRAY} (hackdex.app)!!!{PAUSE 48}\n"
    "Fake website impersonators are a thing!\p"
    "We hope you have as much fun\n"
    "playing this game as we did making it!{PAUSE 16}\n\n"
    "   - Doodle's Hearth Team\p"
);

// Callbacks for the prologue screen
static void PrologueScreen_SetupCB(void);
static void PrologueScreen_MainCB(void);
static void PrologueScreen_VBlankCB(void);
static void CB2_StartKabaSpeech(void);

// Prologue Screen tasks
static void Task_PrologueScreenWaitFadeIn(u8 taskId);
static void Task_PrologueScreenWaitFadeAndExit(u8 taskId);

// Prologue Screen helper functions
static inline void PrologueScreen_ResetForInit(void);
static void PrologueScreen_Init(MainCallback callback);
static void PrologueScreen_ResetGpuRegsAndBgs(void);
static bool8 PrologueScreen_InitBgs(void);
static void PrologueScreen_FadeAndBail(void);
static bool8 PrologueScreen_LoadGraphics(void);
static void PrologueScreen_InitWindows(void);
static void PrologueScreen_FreeResources(void);

void CB2_InitPrologueScreen(void)
{
    PrologueScreen_Init(CB2_InitMainMenuHearth);
}

static void PrologueScreen_Init(MainCallback callback)
{
    sPrologueScreenState = AllocZeroed(sizeof(struct PrologueScreenState));
    if (sPrologueScreenState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sPrologueScreenState->loadState = 0;
    sPrologueScreenState->savedCallback = callback;

    SetMainCallback2(PrologueScreen_SetupCB);
}

static inline void PrologueScreen_ResetForInit(void)
{
    PrologueScreen_ResetGpuRegsAndBgs();
    SetVBlankHBlankCallbacksToNull();
    ClearScheduledBgCopiesToVram();
    ScanlineEffect_Stop();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetSpriteData();
    ResetTasks();
}

static void PrologueScreen_ResetGpuRegsAndBgs(void)
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

static bool32 PrintPrologueMessage(const u8 *text, u32 x, u32 y)
{
    u32 windowId = WINDOW_0;

    switch (sPrologueScreenState->printState)
    {
    case 0:
        FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
        StringExpandPlaceholders(gStringVar4, text);
        AddTextPrinterParameterized4(windowId, FONT_NORMAL, x, y, 1, 0, sPrologueTextColors, 1, gStringVar4);
        gTextFlags.canABSpeedUpPrint = FALSE;
        sPrologueScreenState->printState = 1;
        break;
    case 1:
        if (!IsTextPrinterActiveOnWindow(windowId))
        {
            sPrologueScreenState->printState = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

static void Task_PrologueScreenPrint(u8 taskId)
{
    if (PrintPrologueMessage(sText_Prologue, 0, 3))
    {
        sPrologueScreenState->savedCallback = CB2_StartKabaSpeech;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_PrologueScreenWaitFadeAndExit;
    }
}

static void PrologueScreen_SetupCB(void)
{
    switch (gMain.state)
    {
    case 0:
        PrologueScreen_ResetForInit();
        gMain.state++;
        break;
    case 1:
        if (PrologueScreen_InitBgs())
        {
            sPrologueScreenState->loadState = 0;
            gMain.state++;
        }
        else
        {
            PrologueScreen_FadeAndBail();
            return;
        }
        break;
    case 2:
        if (PrologueScreen_LoadGraphics() == TRUE)
        {
            gMain.state++;
        }
        break;
    case 3:
        PrologueScreen_InitWindows();
        gMain.state++;
        break;
    case 4:
        CreateTask(Task_PrologueScreenWaitFadeIn, 0);
        gMain.state++;
        break;
    case 5:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        SetVBlankCallback(PrologueScreen_VBlankCB);
        SetMainCallback2(PrologueScreen_MainCB);
        break;
    }
}

static void PrologueScreen_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    RunTextPrinters();
    UpdatePaletteFade();
}

static void PrologueScreen_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void Task_PrologueScreenWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_PrologueScreenPrint;
    }
}

static void CB2_StartKabaSpeech(void)
{
    SetMainCallback2(CB2_KabaSpeech);
    CreateTask(Task_KabaSpeech_Begin, 0);
}

static void Task_PrologueScreenWaitFadeAndExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sPrologueScreenState->savedCallback);
        PrologueScreen_FreeResources();
        DestroyTask(taskId);
    }
}
#define TILEMAP_BUFFER_SIZE (1024 * 2)
static bool8 PrologueScreen_InitBgs(void)
{
    ResetAllBgsCoordinates();

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sPrologueScreenBgTemplates, NELEMS(sPrologueScreenBgTemplates));

    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}
#undef TILEMAP_BUFFER_SIZE

static void PrologueScreen_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_PrologueScreenWaitFadeAndExit, 0);
    SetVBlankCallback(PrologueScreen_VBlankCB);
    SetMainCallback2(PrologueScreen_MainCB);
}

static bool8 PrologueScreen_LoadGraphics(void)
{
    switch (sPrologueScreenState->loadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        sPrologueScreenState->loadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            sPrologueScreenState->loadState++;
        }
        break;
    case 2:
        Menu_LoadStdPalAt(BG_PLTT_ID(15));
        sPrologueScreenState->loadState++;
    default:
        sPrologueScreenState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void PrologueScreen_InitWindows(void)
{
    InitWindows(sPrologueScreenWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);
    FillWindowPixelBuffer(WINDOW_0, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    PutWindowTilemap(WINDOW_0);
    CopyWindowToVram(WINDOW_0, 3);
}

static void PrologueScreen_FreeResources(void)
{
    if (sPrologueScreenState != NULL)
    {
        Free(sPrologueScreenState);
    }
    FreeAllWindowBuffers();
    ResetSpriteData();
}
