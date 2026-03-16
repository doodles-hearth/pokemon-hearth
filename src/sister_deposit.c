#include "global.h"
#include "battle_message.h"
#include "constants/flags.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_message_box.h"
#include "field_player_avatar.h"
#include "gba/defines.h"
#include "gba/io_reg.h"
#include "international_string_util.h"
#include "main.h"
#include "menu.h"
#include "money.h"
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

// Tasks
static void Task_ShowWithdrawalMenu(u8 taskId);
static void Task_HandleWithdrawalInput(u8 taskId);

// Windows
static const struct WindowTemplate sSavingsWithdrawalWindowTemplate = {
    .bg = 0, .tilemapLeft = 15, .tilemapTop = 2, .width = 13, .height = 2, .paletteNum = 15, .baseBlock = 0x30};

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

u32 GetWithdrawalAmount(void)
{
    return sWithdrawalAmount;
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
            gTasks[taskId].func = Task_HandleWithdrawalInput;
            break;
    }
}
#undef tState

static void Task_HandleWithdrawalInput(u8 taskId)
{
    if (HandleAmountInput(&sWithdrawalAmount, GetSavings(), 0)) {
        PrintWithdrawalAmount(sWithdrawalWindowId, sWithdrawalAmount);
    }
    else if (JOY_NEW(A_BUTTON | B_BUTTON)) {
        if (JOY_NEW(B_BUTTON))
            sWithdrawalAmount = 0;
        gSpecialVar_Result = sWithdrawalAmount;
        ClearStdWindowAndFrame(sWithdrawalWindowId, TRUE);
        UnfreezeObjectEvents();
        ScriptContext_Enable();
        UnlockPlayerFieldControls();
        DestroyTask(taskId);
    }
}

void WithdrawSavings(void)
{
    CreateTask(Task_ShowWithdrawalMenu, 2);
}

void UpdateSavingsAfterWithdrawal(void)
{
    SetSavings(GetSavings() - sWithdrawalAmount);
    AddMoney(&gSaveBlock1Ptr->money, sWithdrawalAmount);
}
