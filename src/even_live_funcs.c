#include "global.h"
#include "script.h"
#include "even_live_event.h"
#include "even_live_funcs.h"
#include "constants/even_live_event.h"
#include "event_scripts.h"
#include "event_object_movement.h"
#include "random.h"

// BASE FUNCTIONS

// Speech bubble
void LiveBaseBubble(u32 localId, u32 eventIndex, enum LiveEvent event, const u8 * inputStr)
{
    u32 objectEventId = sActiveLiveEvents[eventIndex].objectEventId;

    if (sActiveLiveEvents[eventIndex].duration == sLiveEvents[event].duration)
    {
        u32 numSprites = CreateSpeechBubbleNormal(
            localId,
            eventIndex,
            AUTOMATIC_START,
            inputStr,
            FALSE,
            sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids
        );
        sActiveLiveEvents[eventIndex].speechBubbleNormalData.numSprites = numSprites;
    }

    CheckAndTearDownSpeechBubble(eventIndex, objectEventId);
}

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

void LiveHaltFunc(u32 localId, u32 eventIndex)
{
    u32 objectEventId = sActiveLiveEvents[eventIndex].objectEventId;

    if (sActiveLiveEvents[eventIndex].duration == sLiveEvents[LIVE_EVENT_HALT].duration)
    {
        u32 numSprites = CreateSpeechBubbleNormal(localId, eventIndex, AUTOMATIC_START, COMPOUND_STRING("Halt"), FALSE, sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids);
        sActiveLiveEvents[eventIndex].speechBubbleNormalData.numSprites = numSprites;
    }

    CheckAndTearDownSpeechBubble(eventIndex, objectEventId);
}

void LiveSigh(u32 localId, u32 eventIndex)
{
    LiveBaseBubble(localId, eventIndex, LIVE_EVENT_SIGH, COMPOUND_STRING("Sigh…"));
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
    LiveBaseBubble(localId, eventIndex, LIVE_EVENT_CHATOT, (rand == 0) ? COMPOUND_STRING("HI CHATOT!") : COMPOUND_STRING("SQWAK!"));
}

void LiveCrobatShop(u32 localId, u32 eventIndex)
{
    LiveBaseBubble(localId, eventIndex, LIVE_EVENT_CHATOT, COMPOUND_STRING("Cheap, legal wares!"));
}
