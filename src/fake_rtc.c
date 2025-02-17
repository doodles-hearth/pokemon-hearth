#include "global.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "rtc.h"
#include "fake_rtc.h"
#include "event_data.h"
#include "script.h"

static void FakeRtc_CalcTimeDifference(struct Time *result, struct SiiRtcInfo *t1, struct Time *t2);

void FakeRtc_Reset(void)
{
#if OW_USE_FAKE_RTC
    memset(&gSaveBlock3Ptr->fakeRTC, 0, sizeof(gSaveBlock3Ptr->fakeRTC));
    gSaveBlock3Ptr->fakeRTC.month = MONTH_JAN;
    gSaveBlock3Ptr->fakeRTC.day = 1;
    gSaveBlock3Ptr->fakeRTC.dayOfWeek = WEEKDAY_SAT;
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

    if (FlagGet(FLAG_PAUSE_FAKERTC) || gSaveBlock2Ptr->pauseTimeForBattle)
        return;

    FakeRtc_AdvanceTimeBy(0, 0, 0, FakeRtc_GetSecondsRatio());
}

static void FakeRtc_AdvanceSeconds(struct SiiRtcInfo *rtc, u32 *days, u32 *hours, u32 *minutes, u32 *seconds)
{
    *seconds += rtc->second;
    *minutes += rtc->minute;
    *hours += rtc->hour;

    while (*seconds >= SECONDS_PER_MINUTE)
    {
        (*minutes)++;
        *seconds -= SECONDS_PER_MINUTE;
    }
    while (*minutes >= MINUTES_PER_HOUR)
    {
        (*hours)++;
        *minutes -= MINUTES_PER_HOUR;
    }
    while (*hours >= HOURS_PER_DAY)
    {
        (*days)++;
        *hours -= HOURS_PER_DAY;
    }
    
    rtc->second = *seconds;
    rtc->minute = *minutes;
    rtc->hour = *hours;
}

static void FakeRtc_SetDayOfWeek(struct SiiRtcInfo *rtc, u32 daysToAdd)
{
    rtc->dayOfWeek = (rtc->dayOfWeek + daysToAdd) % WEEKDAY_COUNT;
}

static void FakeRtc_AdvanceDays(struct SiiRtcInfo *rtc, u32 *days)
{
    Script_PauseFakeRtc();
    u32 remainingDaysInMonth = (sNumDaysInMonths[rtc->month - 1] + (rtc->month == MONTH_FEB && IsLeapYear(rtc->year)) - rtc->day);
    if (*days > remainingDaysInMonth)
    {
        rtc->day = 1;
        rtc->month++;
        if (rtc->month > MONTH_DEC)
        {
            rtc->month = MONTH_JAN;
            rtc->year++;
        }
        *days -= (remainingDaysInMonth + 1);
        FakeRtc_SetDayOfWeek(rtc, remainingDaysInMonth + 1);
    }
    else
    {
        rtc->day += *days;
        FakeRtc_SetDayOfWeek(rtc, *days);
        *days = 0;
    }
    Script_ResumeFakeRtc();
}

void FakeRtc_AdvanceTimeBy(u32 days, u32 hours, u32 minutes, u32 seconds)
{
    Script_PauseFakeRtc();
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    FakeRtc_AdvanceSeconds(rtc, &days, &hours, &minutes, &seconds);

    while (days > 0)
        FakeRtc_AdvanceDays(rtc, &days);
    Script_ResumeFakeRtc();
}

void FakeRtc_ForwardTimeTo(u32 hour, u32 minute, u32 second)
{
    Script_PauseFakeRtc();
    struct Time diff, target;
    struct SiiRtcInfo *fakeRtc = FakeRtc_GetCurrentTime();

    target.hours = hour;
    target.minutes = minute;
    target.seconds = second;

    FakeRtc_CalcTimeDifference(&diff, fakeRtc, &target);

    FakeRtc_AdvanceTimeBy(0, diff.hours, diff.minutes, diff.seconds);

    Script_ResumeFakeRtc();
}

void FakeRtc_SetNewGameDay(void)
{
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    u32 daysToAdd;
    daysToAdd = ((rtc->dayOfWeek) + 7) % 7;
    FakeRtc_AdvanceTimeBy(daysToAdd, 0, 0, 0);
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

void FakeRtc_ForceSetTime(u32 day, u32 hour, u32 minute, u32 second)
{
    FakeRtc_Reset();
    FakeRtc_AdvanceTimeBy(day, hour, minute, second);
}

u32 FakeRtc_GetSecondsRatio(void)
{
    return (OW_ALTERED_TIME_RATIO == GEN_8_PLA) ? 60 :
           (OW_ALTERED_TIME_RATIO == GEN_9)     ? 20 :
                                                  1;
}

STATIC_ASSERT((FLAG_PAUSE_FAKERTC == 0 || OW_USE_FAKE_RTC == TRUE), FakeRtcMustBeTrueToPauseTime);

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