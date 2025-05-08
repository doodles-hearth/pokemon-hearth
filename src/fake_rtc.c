#include "global.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "datetime.h"
#include "rtc.h"
#include "fake_rtc.h"
#include "event_data.h"
#include "script.h"

extern bool32 InBattle(void);

static void FakeRtc_CalcTimeDifference(struct Time *result, struct SiiRtcInfo *t1, struct Time *t2);

void FakeRtc_Reset(void)
{
#if OW_USE_FAKE_RTC
    memset(&gSaveBlock3Ptr->fakeRTC, 0, sizeof(gSaveBlock3Ptr->fakeRTC));
    gSaveBlock3Ptr->fakeRTC.year = 0; // offset by gGen3Epoch.year
    gSaveBlock3Ptr->fakeRTC.month = gGen3Epoch.month;
    gSaveBlock3Ptr->fakeRTC.day = gGen3Epoch.day;
    gSaveBlock3Ptr->fakeRTC.dayOfWeek = gGen3Epoch.dayOfWeek;
#endif
}

struct SiiRtcInfo *FakeRtc_GetCurrentTime(void)
{
#if OW_USE_FAKE_RTC
    return &gSaveBlock3Ptr->fakeRTC;
#else
    return NULL;
#endif
}

void FakeRtc_GetRawInfo(struct SiiRtcInfo *rtc)
{
    struct SiiRtcInfo *fakeRtc = FakeRtc_GetCurrentTime();
    if (fakeRtc != NULL)
        memcpy(rtc, fakeRtc, sizeof(struct SiiRtcInfo));
}

void FakeRtc_TickTimeForward(void)
{
    if (!OW_USE_FAKE_RTC)
        return;

    if (FlagGet(FLAG_PAUSE_FAKERTC) || InBattle())
        return;

    FakeRtc_AdvanceTimeBy(0, 0, 0, FakeRtc_GetSecondsRatio(), TRUE);
}

void FakeRtc_AdvanceTimeBy(u32 days, u32 hours, u32 minutes, u32 seconds, bool32 shouldImpactBerryGrowth)
{
    struct DateTime dateTime;
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();

    ConvertRtcToDateTime(&dateTime, rtc);
    DateTime_AddSeconds(&dateTime, seconds);
    DateTime_AddMinutes(&dateTime, minutes);
    DateTime_AddHours(&dateTime, hours);
    DateTime_AddDays(&dateTime, days);
    ConvertDateTimeToRtc(rtc, &dateTime);

    // Resetting lastBerryTreeUpdate to the new current time effectively freezes berry growth
    // Berry trees are therefore no longer cheesable through timeskips
    if (!shouldImpactBerryGrowth) {
        struct Time currentTime;
        currentTime.days = rtc->day;
        currentTime.hours = rtc->hour;
        currentTime.minutes = rtc->minute;
        currentTime.seconds = rtc->second;
        gSaveBlock2Ptr->lastBerryTreeUpdate = currentTime;
    }
}

void FakeRtc_ManuallySetTime(u32 day, u32 hour, u32 minute, u32 second)
{
    FakeRtc_Reset();
    FakeRtc_AdvanceTimeBy(day, hour, minute, second, FALSE);
}

// void AdvanceScript(void)
// {
//     FakeRtc_AdvanceTimeBy(300, 0, 0, 0);
// }

u32 FakeRtc_GetSecondsRatio(void)
{
    return (OW_ALTERED_TIME_RATIO == GEN_8_PLA)   ? 60 :
           (OW_ALTERED_TIME_RATIO == GEN_9)       ? 20 :
           (OW_ALTERED_TIME_RATIO == TIME_DEBUG)  ?  1 :
                                                     1;
}

STATIC_ASSERT((OW_FLAG_PAUSE_TIME == 0 || OW_USE_FAKE_RTC == TRUE), FakeRtcMustBeTrueToPauseTime);

void FakeRtc_ForwardTimeTo(u32 hour, u32 minute, u32 second)
{
    Script_PauseFakeRtc();
    struct Time diff, target;
    struct SiiRtcInfo *fakeRtc = FakeRtc_GetCurrentTime();

    target.hours = hour;
    target.minutes = minute;
    target.seconds = second;

    FakeRtc_CalcTimeDifference(&diff, fakeRtc, &target);

    FakeRtc_AdvanceTimeBy(0, diff.hours, diff.minutes, diff.seconds, FALSE);

    Script_ResumeFakeRtc();
}

void FakeRtc_SetNewGameDay(void)
{
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    u32 daysToAdd;
    daysToAdd = ((rtc->dayOfWeek) + 7) % 7;
    FakeRtc_AdvanceTimeBy(daysToAdd, 0, 0, 0, FALSE);
}

static void FakeRtc_CalcTimeDifference(struct Time *result, struct SiiRtcInfo *t1, struct Time *t2)
{
    result->seconds = t2->seconds - t1->second;
    result->minutes = t2->minutes - t1->minute;
    result->hours = t2->hours - t1->hour;
    result->days = t2->days - t1->day;

    if (result->seconds < 0)
    {
        result->seconds += SECONDS_PER_MINUTE;
        --result->minutes;
    }

    if (result->minutes < 0)
    {
        result->minutes += MINUTES_PER_HOUR;
        --result->hours;
    }

    if (result->hours < 0)
    {
        result->hours += HOURS_PER_DAY;
        --result->days;
    }
}

void Script_PauseFakeRtc(void)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    FlagSet(FLAG_PAUSE_FAKERTC);
}

void Script_ResumeFakeRtc(void)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    FlagClear(FLAG_PAUSE_FAKERTC);
}

void Script_ToggleFakeRtc(void)
{
    Script_RequestEffects(SCREFF_V1 | SCREFF_SAVE);

    FlagToggle(FLAG_PAUSE_FAKERTC);
}

#ifndef NDEBUG
void PrintTimesIntoMgbaPrintf(void)
{
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    MgbaPrintf(MGBA_LOG_WARN, "gLocalTime Set");
    MgbaPrintf(MGBA_LOG_WARN, " ");
    MgbaPrintf(MGBA_LOG_WARN, "days: %u", gLocalTime.days);
    MgbaPrintf(MGBA_LOG_WARN, "hours: %u", gLocalTime.hours);
    MgbaPrintf(MGBA_LOG_WARN, "minutes: %u", gLocalTime.minutes);

    MgbaPrintf(MGBA_LOG_WARN, "Fake RTC Set");
    MgbaPrintf(MGBA_LOG_WARN, " ");
    MgbaPrintf(MGBA_LOG_WARN, "days: %u", rtc->day);
    MgbaPrintf(MGBA_LOG_WARN, "hours: %u", rtc->hour);
    MgbaPrintf(MGBA_LOG_WARN, "minutes: %u", rtc->minute);
}
#endif