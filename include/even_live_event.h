#ifndef GUARD_EVEN_LIVE_EVENT
#define GUARD_EVEN_LIVE_EVENT

#include "gba/types.h"
#include "global.h"
#include "script.h"

struct LiveEventData
{
    void (*func)(u32 localId, u32 eventIndex);
    u32 retriggerDelay; //  0 means no retrigger
    u16 duration;
    u8 triggerRange;
};

struct SpeechBubbleNormalData
{
    u8 ids[2];
    u16 numSprites;
    u8 *str;
};

struct ActiveLiveEvent
{
    void (*func)(u32 localId, u32 eventIndex);
    u8 localId;
    u8 objectEventId;
    u16 duration;
    union {
        struct SpeechBubbleNormalData speechBubbleNormalData;
    };
};

enum StartingSide
{
    LEFT_START,
    RIGHT_START,
    AUTOMATIC_START,
};

void ProcessLiveEvents(void);
void ResetLiveEventTriggers(void);
void StopActiveLiveEvents(void);
void ManuallyTriggerLiveEvent(struct ScriptContext *ctx);

void CheckAndTearDownSpeechBubble(u32 eventIndex, u32 objectEventId);
u32 CreateSpeechBubbleNormal(u32 localId, u32 eventIndex, enum StartingSide side, const u8 *inputStr, bool32 maxOneSprite, u8 ids[2]);
bool32 IsSourceObjectOffscreen(u32 objectEventId);
void ExecuteScript(const u8 *script);

extern struct ActiveLiveEvent sActiveLiveEvents[64];
extern const struct LiveEventData sLiveEvents[];

#endif
