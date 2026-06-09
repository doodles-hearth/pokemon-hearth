#include "global.h"
#include "script.h"
#include "even_live_event.h"
#include "even_live_funcs.h"
#include "constants/even_live_event.h"
#include "event_scripts.h"
#include "event_object_movement.h"
#include "random.h"

// BASE FUNCTIONS

// Execute a script
void LiveBaseGoAwayScript(u32 localId, u32 eventIndex, enum LiveEvent event, const u8 eventScript[])
{
    u32 objectEventId = sActiveLiveEvents[eventIndex].objectEventId;
    if (sActiveLiveEvents[eventIndex].duration == sLiveEvents[event].duration)
        ExecuteScript(eventScript);
    if (sActiveLiveEvents[eventIndex].duration == 1 || IsSourceObjectOffscreen(objectEventId))
    {
        RemoveObjectEventByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    }
    sActiveLiveEvents[eventIndex].duration--;
}

// END OF BASE FUNCTIONS

void LiveWoobatFlee(u32 localId, u32 eventIndex)
{
    u32 objectEventId = sActiveLiveEvents[eventIndex].objectEventId;
    if (sActiveLiveEvents[eventIndex].duration == sLiveEvents[LIVE_EVENT_WOOBAT_FLEE].duration)
        ExecuteScript(WC_WoobatFlee);
    if (sActiveLiveEvents[eventIndex].duration == 1 || IsSourceObjectOffscreen(objectEventId))
    {
        RemoveObjectEventByLocalIdAndMap(localId, gSaveBlock1Ptr->location.mapNum, gSaveBlock1Ptr->location.mapGroup);
    }
    sActiveLiveEvents[eventIndex].duration--;
}

const struct MultiSpeechBubble sSunManRant[] =
{
    {
        .str = COMPOUND_STRING("The sun!"),
        .displayAt = 200,
        .removeAt = 100,
    },
    {
        .str = COMPOUND_STRING("It moves!"),
        .displayAt = 100,
        .removeAt = 0,
    }
};

void SunManRant(u32 localId, u32 eventIndex)
{
    MultiSpeechBubbleEvent(AUTOMATIC_START, sSunManRant, FALSE);
}

void LiveSigh(u32 localId, u32 eventIndex)
{
    SpeechBubbleEvent(AUTOMATIC_START, COMPOUND_STRING("Sigh…"), FALSE);
}

void LiveDeerling1Flee(u32 localId, u32 eventIndex)
{
    LiveBaseGoAwayScript(localId, eventIndex, LIVE_EVENT_DEERLING1_FLEE, Live_EventScript_Deerling1Flee);
}

void LiveDeerling2Flee(u32 localId, u32 eventIndex)
{
    LiveBaseGoAwayScript(localId, eventIndex, LIVE_EVENT_DEERLING2_FLEE, Live_EventScript_Deerling2Flee);
}

void LiveChatot(u32 localId, u32 eventIndex)
{
    u32 rand = Random() % 3;
    SpeechBubbleEvent(AUTOMATIC_START, (rand == 0) ? COMPOUND_STRING("HI CHATOT!") : COMPOUND_STRING("SQWAK!"), FALSE);
}

void LiveCrobatShop(u32 localId, u32 eventIndex)
{
    SpeechBubbleEvent(AUTOMATIC_START, COMPOUND_STRING("Cheap, legal wares!"), FALSE);
}
