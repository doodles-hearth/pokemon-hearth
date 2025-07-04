#include "global.h"
#include "main.h"
#include "script.h"

extern const u8 ShinyVial_EventScript_EffectWoreOff[];

void ShinyVialTimeUpdate(s32 minutes)
{
    if (gSaveBlock1Ptr->remainingShinyVialMinutes > 0)
    {
        gSaveBlock1Ptr->remainingShinyVialMinutes -= min(minutes, gSaveBlock1Ptr->remainingShinyVialMinutes);
    }
}

// This is fired at ever step to avoid the "effect wore off" message displaying at
// inopportune moments because fully time-based
bool8 UpdateShinyVialCounter(void)
{
    if (gSaveBlock1Ptr->remainingShinyVialMinutes == 0 && gSaveBlock1Ptr->isShinyVialActive)
    {
        gSaveBlock1Ptr->isShinyVialActive = FALSE;
        ScriptContext_SetupScript(ShinyVial_EventScript_EffectWoreOff);
        return TRUE;
    }

    return FALSE;
}