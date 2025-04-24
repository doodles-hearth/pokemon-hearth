#ifndef GUARD_FAKE_RTC_UTIL_H
#define GUARD_FAKE_RTC_UTIL_H

#include "siirtc.h"
void FakeRtc_Reset(void);
struct SiiRtcInfo* FakeRtc_GetCurrentTime(void);
void FakeRtc_GetRawInfo(struct SiiRtcInfo *rtc);
void FakeRtc_AdvanceTimeBy(u32 days, u32 hours, u32 minutes, u32 seconds, u32 shouldImpactBerryGrowth);
void FakeRtc_ManuallySetTime(u32 day, u32 hour, u32 minute, u32 second);
void FakeRtc_TickTimeForward(void);
u32 FakeRtc_GetSecondsRatio(void);
/* hearth custom */
void FakeRtc_ForwardTimeTo(u32 hour, u32 minute, u32 second);
void FakeRtc_SetNewGameDay(void);
void PrintTimesIntoMgbaPrintf(void);
void Script_ResumeFakeRtc(void);
void Script_PauseFakeRtc(void);
void Script_ToggleFakeRtc(void);

#define DURATION_WILD_BATTLE_MINUTES 10
#define DURATION_TRAINER_BATTLE_MINUTES 30

#endif // GUARD_FAKE_RTC_UTIL_H