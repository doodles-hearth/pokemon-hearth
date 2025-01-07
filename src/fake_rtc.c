#include "global.h"
#include "string_util.h"
#include "strings.h"
#include "text.h"
#include "rtc.h"
#include "fake_rtc.h"
#include "event_data.h"
#include "script.h"

void Script_ResumeFakeRtc(void);
void Script_PauseFakeRtc(void);
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

    if (FlagGet(OW_FLAG_PAUSE_TIME))
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
rtc->dayOfWeek rtc->dayOfWeek + daysToAdd) % WEEKDAY_COUNT;
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

STATIC_ASSERT((OW_FLAG_PAUSE_TIME == 0 || OW_USE_FAKE_RTC == TRUE), FakeRtcMustBeTrueToPauseTime);

void Script_PauseFakeRtc(void)
{
    FlagSet(OW_FLAG_PAUSE_TIME);
}

void Script_ResumeFakeRtc(void)
{
    FlagClear(OW_FLAG_PAUSE_TIME);
}

void Script_ToggleFakeRtc(void)
{
    FlagToggle(OW_FLAG_PAUSE_TIME);
}

u32 FakeRtc_GetWeekday(void)
{
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    switch (rtc->dayOfWeek)
    {
    case WEEKDAY_SUN:
        return WEEKDAY_SUN;
    case WEEKDAY_MON:
        return WEEKDAY_MON;
    case WEEKDAY_TUE:
        return WEEKDAY_TUE;
    case WEEKDAY_WED:
        return WEEKDAY_WED;
    case WEEKDAY_THU:
        return WEEKDAY_THU;
    case WEEKDAY_FRI:
        return WEEKDAY_FRI;
    case WEEKDAY_SAT:
        return WEEKDAY_SAT;
    } 
}

bool8 ScrCmd_addtime(struct ScriptContext *ctx)
{
    u32 days = ScriptReadWord(ctx);
    u32 hours = ScriptReadWord(ctx);
    u32 minutes = ScriptReadWord(ctx);

    FakeRtc_AdvanceTimeBy(days, hours, minutes, 0);

    return FALSE;
}

bool8 ScrCmd_adddays(struct ScriptContext *ctx)
{
    u32 days = ScriptReadWord(ctx);

    FakeRtc_AdvanceTimeBy(days, 0, 0, 0);

    return FALSE;
}

bool8 ScrCmd_addhours(struct ScriptContext *ctx)
{
    u32 hours = ScriptReadWord(ctx);

    FakeRtc_AdvanceTimeBy(0, hours, 0, 0);

    return FALSE;
}

bool8 ScrCmd_addminutes(struct ScriptContext *ctx)
{
    u32 minutes = ScriptReadWord(ctx);

    FakeRtc_AdvanceTimeBy(0, 0, minutes, 0);

    return FALSE;
}

bool8 ScrCmd_fwdtime(struct ScriptContext *ctx)
{
    u32 hours = ScriptReadWord(ctx);
    u32 minutes = ScriptReadWord(ctx);

    FakeRtc_ForwardTimeTo(hours, minutes, 0);

    return FALSE;
}

bool8 ScrCmd_fwdweekday(struct ScriptContext *ctx)
{
    
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    
    u32 weekdayTarget = ScriptReadWord(ctx);
    u32 rtc->dayOfWeek;
    u32 daysToAdd;
    daysToAdd = ((weekdayTarget - weekdayCurrent) + 7) % 7;
    FakeRtc_AdvanceTimeBy(daysToAdd, 0, 0, 0);
    return FALSE;
}

void PrintTimesIntoMgbaPrintf(void)
{
    struct SiiRtcInfo *rtc = FakeRtc_GetCurrentTime();
    MgbaPrintf(MGBA_LOG_WARN, "gLocalTime Set");
    MgbaPrintf(MGBA_LOG_WARN, " ");
    MgbaPrintf(MGBA_LOG_WARN, "%u", gLocalTime.days);
    MgbaPrintf(MGBA_LOG_WARN, "%u", gLocalTime.hours);
    MgbaPrintf(MGBA_LOG_WARN, "%u", gLocalTime.minutes);

    MgbaPrintf(MGBA_LOG_WARN, "Fake RTC Set");
    MgbaPrintf(MGBA_LOG_WARN, " ");
    MgbaPrintf(MGBA_LOG_WARN, "days: %u", rtc->day);
    MgbaPrintf(MGBA_LOG_WARN, "hours: %u", rtc->hour);
    MgbaPrintf(MGBA_LOG_WARN, "minutes: %u", rtc->minute);
}