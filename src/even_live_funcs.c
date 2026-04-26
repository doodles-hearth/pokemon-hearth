#include "global.h"
#include "script.h"
#include "even_live_event.h"
#include "even_live_funcs.h"
#include "constants/even_live_event.h"
#include "event_scripts.h"
#include "event_object_movement.h"
#include "random.h"

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

void HelloFunc(u32 localId, u32 eventIndex)
{
    u32 objectEventId = sActiveLiveEvents[eventIndex].objectEventId;

    if (sActiveLiveEvents[eventIndex].duration == sLiveEvents[LIVE_EVENT_HELLO].duration)
    {
        u32 numSprites = CreateSpeechBubbleNormal(localId, eventIndex, AUTOMATIC_START, COMPOUND_STRING("Hello"), FALSE, sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids);
        sActiveLiveEvents[eventIndex].speechBubbleNormalData.numSprites = numSprites;
    }

    CheckAndTearDownSpeechBubble(eventIndex, objectEventId);
}

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

void LiveSigh(u32 localId, u32 eventIndex)
{
    u32 objectEventId = sActiveLiveEvents[eventIndex].objectEventId;

    if (sActiveLiveEvents[eventIndex].duration == sLiveEvents[LIVE_EVENT_SIGH].duration)
    {
        u32 numSprites = CreateSpeechBubbleNormal(
            localId,
            eventIndex,
            AUTOMATIC_START,
            COMPOUND_STRING("Sigh…"),
            FALSE,
            sActiveLiveEvents[eventIndex].speechBubbleNormalData.ids
        );
        sActiveLiveEvents[eventIndex].speechBubbleNormalData.numSprites = numSprites;
    }

    CheckAndTearDownSpeechBubble(eventIndex, objectEventId);
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
