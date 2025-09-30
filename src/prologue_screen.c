#include "gba/types.h"
#include "gba/defines.h"
#include "global.h"
#include "main.h"
#include "bg.h"
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
#include "strings.h"
#include "field_screen_effect.h"
#include "kaba_speech.h"

static void Task_Prologue_Cleanup(u8 taskId);
static bool32 PrintPrologueMessage(u8 taskId, const u8 *text, u32 x, u32 y);

enum FontColor
{
    FONT_WHITE,
    FONT_RED
};

static const u8 sPrologueScreenWindowFontColors[][3] =
{
    [FONT_WHITE] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY},
    [FONT_RED] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_GRAY},
};

enum
{
    PROLOGUE_ENTER_PREPARE,
    PROLOGUE_ENTER_MSG_SCREEN,
    PROLOGUE_PRINT_MSG,
    PROLOGUE_LEAVE_MSG_SCREEN,
    PROLOGUE_HEAL_SCRIPT,
};

#define tState data[0]
#define tWindowId data[1]
#define tPrintState data[2]

static const struct WindowTemplate sWindowTemplate_PrologueText =
{
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 20,
    .paletteNum = 15,
    .baseBlock = 1,
};

static const u8 sPrologueTextColors[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE, TEXT_COLOR_DARK_GRAY};

const u8 sText_Prologue[] = _(
    "This game is FREE.\nYou should not have paid for it.{PAUSE 48}\n\n"
    "To avoid playing an outdated version\n"
    "of the game,{PAUSE 16} make sure you got the hack\n"
    "from the {COLOR LIGHT_RED}{SHADOW RED}Hearth patcher page{COLOR WHITE}{SHADOW DARK_GRAY},{PAUSE 16}\n"
    "the {COLOR LIGHT_RED}{SHADOW RED}Pokémon Hearth Discord{COLOR WHITE}{SHADOW DARK_GRAY},{PAUSE 16}\n"
    "or {COLOR LIGHT_RED}{SHADOW RED}PokéCommunity{COLOR WHITE}{SHADOW DARK_GRAY}!\p"
    "We hope you have as much fun\n"
    "playing this game as we did making it!\n\n"
    "   - Doodle's Hearth Team\p"
);

static bool32 PrintPrologueMessage(u8 taskId, const u8 *text, u32 x, u32 y)
{
    u32 windowId = gTasks[taskId].tWindowId;

    switch (gTasks[taskId].tPrintState)
    {
    case 0:
        FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
        StringExpandPlaceholders(gStringVar4, text);
        AddTextPrinterParameterized4(windowId, FONT_NORMAL, x, y, 1, 0, sPrologueTextColors, 1, gStringVar4);
        gTextFlags.canABSpeedUpPrint = FALSE;
        gTasks[taskId].tPrintState = 1;
        break;
    case 1:
        RunTextPrinters();
        if (!IsTextPrinterActive(windowId))
        {
            gTasks[taskId].tPrintState = 0;
            return TRUE;
        }
        break;
    }
    return FALSE;
}

void Task_OpenPrologueScreen(u8 taskId)
{
    u32 windowId;

    switch (gTasks[taskId].tState)
    {
    case PROLOGUE_ENTER_PREPARE:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);

        gTasks[taskId].tState = PROLOGUE_ENTER_MSG_SCREEN;
        break;
    case PROLOGUE_ENTER_MSG_SCREEN:
        windowId = AddWindow(&sWindowTemplate_PrologueText);
        gTasks[taskId].tWindowId = windowId;
        Menu_LoadStdPalAt(BG_PLTT_ID(15));
        FillWindowPixelBuffer(windowId, PIXEL_FILL(0));
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);

        gTasks[taskId].tState = PROLOGUE_PRINT_MSG;
        break;
    case PROLOGUE_PRINT_MSG:
    {
        const u8 *msg = sText_Prologue;

        if (PrintPrologueMessage(taskId, msg, 2, 8))
        {
            gTasks[taskId].tState = PROLOGUE_LEAVE_MSG_SCREEN;
        }
        break;
    }
    case PROLOGUE_LEAVE_MSG_SCREEN:
        windowId = gTasks[taskId].tWindowId;
        ClearWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_MAP);
        RemoveWindow(windowId);
        FadeInFromBlack();
        gTasks[taskId].func = Task_Prologue_Cleanup;
        break;
    }
}

static void Task_Prologue_Cleanup(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        FreeAllWindowBuffers();
        DestroyTask(taskId);
        CreateTask(Task_KabaSpeech_Begin, taskId);
    }
}
