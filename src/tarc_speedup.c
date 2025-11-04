#include "global.h"
#include "gba/types.h"
#include "main.h"
#include "tarc_speedup.h"
#include "event_data.h"
#include "palette.h"

EWRAM_DATA u32 sSkipCounter = 0;
EWRAM_DATA bool32 sDoSpeedup = FALSE;
EWRAM_DATA u32 sNumSkips = 0;
EWRAM_DATA bool32 sPause = FALSE;

void StartSpeedup(void)
{
    DebugPrintf("Speed=%d", gSaveBlock2Ptr->optionsBattleSpeed);
    if (gSaveBlock2Ptr->optionsBattleSpeed != BATTLE_SPEED_NORMAL && !sDoSpeedup)
    {
        sDoSpeedup = TRUE;
        switch(gSaveBlock2Ptr->optionsBattleSpeed)
        {
            case BATTLE_SPEED_MID:
                sNumSkips = 2;
                break;
            case BATTLE_SPEED_FAST:
            default:
                sNumSkips = 6;
                break;
        }
    }
}

void StopSpeedup(void)
{
    sDoSpeedup = FALSE;
    sNumSkips = 0;
}

void CheckSpeedupControls(void)
{
    if (sDoSpeedup)
    {
        if (JOY_NEW(L_BUTTON))
        {
            if (sNumSkips > 1)
                sNumSkips--;
        }
        else if (JOY_NEW(R_BUTTON))
        {
            if (sNumSkips < MAX_SPEEDUP)
                sNumSkips++;
        }
        else if (JOY_NEW(B_BUTTON))
        {
            if (sPause)
            {
                sPause = FALSE;
            }
            else
            {
                sPause = TRUE;
            }
        }
    }
}

bool32 SpeedupShouldSkip(void)
{
    if (!sDoSpeedup)
        return FALSE;

    if (sSkipCounter + 1 >= sNumSkips)
    {
        sSkipCounter = 0;
        return FALSE;
    }
    else
    {
        UpdatePaletteFade();
        sSkipCounter++;
        return TRUE;
    }
}

bool32 SpeedupIsPaused(void)
{
    return sPause;
}