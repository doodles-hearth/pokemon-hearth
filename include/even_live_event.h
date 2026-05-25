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
    u32 internalIndex;
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

struct MultiSpeechBubble
{
    const u8 *str;
    u16 removeAt;
    u16 displayAt;
};


void ProcessLiveEvents(void);
void ResetLiveEventTriggers(void);
void StopActiveLiveEvents(void);
void ManuallyTriggerLiveEvent(struct ScriptContext *ctx);

void CheckAndTearDownSpeechBubble(u32 eventIndex, u32 objectEventId);
u32 CreateSpeechBubbleNormal(u32 localId, u32 eventIndex, enum StartingSide side, const u8 *inputStr, bool32 maxOneSprite);
bool32 IsSourceObjectOffscreen(u32 objectEventId);
void ExecuteScript(const u8 *script);

void TearDownSpeechBubble(u32 eventIndex, u32 objectEventId);

#define SpeechBubbleEvent(_START, _STRING, _MAX_SPRITE) _SpeechBubbleEvent(localId, eventIndex, _START, _STRING, _MAX_SPRITE)
void _SpeechBubbleEvent(u32 localId, u32 eventIndex, enum StartingSide side, const u8 *inputStr, bool32 maxOneSprite);

#define MultiSpeechBubbleEvent(_START, _STRINGS, _MAX_SPRITE) _MultiSpeechBubbleEvent(localId, eventIndex, _START, _STRINGS, _MAX_SPRITE, NELEMS(_STRINGS))
void _MultiSpeechBubbleEvent(u32 localId, u32 eventIndex, enum StartingSide side, const struct MultiSpeechBubble *inputStrs, bool32 maxOneSprite, u32 numStrings);

extern struct ActiveLiveEvent sActiveLiveEvents[64];
extern const struct LiveEventData sLiveEvents[];

#endif
