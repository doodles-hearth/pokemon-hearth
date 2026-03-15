#include "global.h"
#include "battle_message.h"
#include "constants/flags.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_player_avatar.h"
#include "gba/defines.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "script.h"
#include "sister_deposit.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "util.h"
#include "window.h"

u32 sWithdrawalAmount = 0;
u8 sWithdrawalWindowId = 0;

// Config
#define SISTER_DEPOSIT_SIZE 4  // Amount is 1/val

// Static Functions
static void GetSavingsString(void);
static void GetWithdrawalString(void);

// Tasks
static void Task_ShowWithdrawalMenu(u8 taskId);

// Windows
static const struct WindowTemplate sSavingsWithdrawalWindowTemplate = {
    .bg = 0, .tilemapLeft = 15, .tilemapTop = 13, .width = 13, .height = 2, .paletteNum = 15, .baseBlock = 0x30};

bool32 IsSavingMoney(void)
{
    return FlagGet(FLAG_SAVING_MONEY);
}

u32 GetSavings(void)
{
    return gSaveBlock1Ptr->sisterDeposit;
}

void SetSavings(u32 amount)
{
    gSaveBlock1Ptr->sisterDeposit = amount;
}

u32 CalcAmountToSave(u32 money)
{
    return money / SISTER_DEPOSIT_SIZE;
}

static void GetSavingsString(void)
{
    u32 savings = GetSavings();
    u32 digits = Util_CountDigits(savings);
    ConvertIntToDecimalStringN(gStringVar1, savings, STR_CONV_MODE_LEFT_ALIGN, digits);
}

static void GetWithdrawalString(void)
{
    u32 digits = Util_CountDigits(sWithdrawalAmount);
    ConvertIntToDecimalStringN(gStringVar1, sWithdrawalAmount, STR_CONV_MODE_LEFT_ALIGN, digits);
}

void CreateWithdrawalWindow(void)
{
    // print window
    sWithdrawalWindowId = AddWindow(&sSavingsWithdrawalWindowTemplate);
    DrawStdWindowFrame(sWithdrawalWindowId, FALSE);
    CopyWindowToVram(sWithdrawalWindowId, COPYWIN_FULL);
}

static bool32 HandleAmountInput(u32* amount, s32 max, s32 min)
{
    s16 original = *amount;

    if (JOY_REPEAT(DPAD_ANY) == DPAD_UP) {
        if (*amount < max)
            (*amount)++;

        if (*amount == original) {
            return FALSE;
        }
        else {
            return TRUE;
        }
    }
    else if (JOY_REPEAT(DPAD_ANY) == DPAD_DOWN) {
        if (*amount > 0)
            (*amount)--;
        if (*amount <= 0)
            *amount = 0;

        if (*amount == original) {
            return FALSE;
        }
        else {
            return TRUE;
        }
    }
    else if (JOY_REPEAT(DPAD_ANY) == DPAD_RIGHT) {
        if (*amount < max - 10)
            *amount += 10;
        else if (*amount > max - 10 && *amount < max)
            *amount = max;

        if (*amount == original) {
            return FALSE;
        }
        else {
            return TRUE;
        }
    }
    else if (JOY_REPEAT(DPAD_ANY) == DPAD_LEFT) {
        if (*amount >= 10)
            *amount -= 10;
        else if (*amount <= 10 && *amount > 0)
            if (*amount <= 0)
                *amount = 0;

        if (*amount == original) {
            return FALSE;
        }
        else {
            return TRUE;
        }
    }

    return FALSE;
}

static void PrintWithdrawalAmount(u8 windowId, s16 amount)
{
    ConvertIntToDecimalStringN(gStringVar4, amount, STR_CONV_MODE_LEADING_ZEROS, Util_CountDigits(GetSavings()));
    AddTextPrinterParameterized(windowId, FONT_NORMAL, gStringVar4,
                                GetStringCenterAlignXOffset(FONT_NORMAL, gStringVar4, 0x28), 2, 0, 0);
}

#define tState data[0]
static void Task_ShowWithdrawalMenu(u8 taskId)
{
    s16* data = gTasks[taskId].data;

    switch (tState) {
        case 0:
            if (!IsOverworldLinkActive()) {
                FreezeObjectEvents();
                PlayerFreeze();
                StopPlayerAvatar();
                LockPlayerFieldControls();
            }
            tState++;
            break;
        case 1:
            CreateWithdrawalWindow();
            tState++;
            break;
        case 2:
            sWithdrawalAmount = GetSavings();
            PrintWithdrawalAmount(sWithdrawalWindowId, sWithdrawalAmount);
            tState++;
            break;
        case 3:
            if (HandleAmountInput(&sWithdrawalAmount, GetSavings(), 0)) {
                PrintWithdrawalAmount(sWithdrawalWindowId, sWithdrawalAmount);
            }
            break;
    }
}
#undef tState

void WithdrawSavings(void)
{
    CreateTask(Task_ShowWithdrawalMenu, 2);
}
