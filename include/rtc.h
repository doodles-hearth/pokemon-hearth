#ifndef GUARD_RTC_UTIL_H
#define GUARD_RTC_UTIL_H

#include "global.h"
#include "siirtc.h"
#include "config/overworld.h"

#define RTC_INIT_ERROR         0x0001
#define RTC_INIT_WARNING       0x0002

#define RTC_ERR_12HOUR_CLOCK   0x0010
#define RTC_ERR_POWER_FAILURE  0x0020
#define RTC_ERR_INVALID_YEAR   0x0040
#define RTC_ERR_INVALID_MONTH  0x0080
#define RTC_ERR_INVALID_DAY    0x0100
#define RTC_ERR_INVALID_HOUR   0x0200
#define RTC_ERR_INVALID_MINUTE 0x0400
#define RTC_ERR_INVALID_SECOND 0x0800

#define RTC_ERR_FLAG_MASK      0x0FF0

#define TIME_NOONTIME_FLAG      (1 << 0)
#define TIME_DEAD_NIGHT_FLAG    (1 << 1)
#define TIME_EARLY_MORNING_FLAG (1 << 2)
#define TIME_EVENING_FLAG       (1 << 3)
#define TIME_LUNCHTIME_FLAG     (1 << 4)
#define TIME_MORNING_FLAG       (1 << 5)
#define TIME_NIGHT_FLAG         (1 << 6)

#define DEAD_NIGHT_HOUR_BEGIN 0
#define DEAD_NIGHT_HOUR_END   5

#define EARLY_MORNING_HOUR_BEGIN 5
#define EARLY_MORNING_HOUR_END   8

#define MORNING_HOUR_BEGIN 8
#define MORNING_HOUR_END   12

#define LUNCHTIME_HOUR_BEGIN 12
#define LUNCHTIME_HOUR_END   14

#define AFTERNOON_HOUR_BEGIN 14
#define AFTERNOON_HOUR_END   18

#define EVENING_HOUR_BEGIN 18
#define EVENING_HOUR_END   22

#define NIGHTTIME_HOUR_BEGIN 22
#define NIGHTTIME_HOUR_END   0

// TIMES_OF_DAY_COUNT must be last
enum TimeOfDay 
{
    TIME_EARLY_MORNING,
    TIME_MORNING,
    TIME_LUNCHTIME,
    TIME_AFTERNOON,
    TIME_EVENING,
    TIME_NIGHT,
    TIME_DEAD_NIGHT,
    TIMES_OF_DAY_COUNT,
};

#define TIME_OF_DAY_DEFAULT    0

extern struct Time gLocalTime;
extern const s32 sNumDaysInMonths[12];

void RtcDisableInterrupts(void);
void RtcRestoreInterrupts(void);
u32 ConvertBcdToBinary(u8 bcd);
bool8 IsLeapYear(u32 year);
u16 ConvertDateToDayCount(u8 year, u8 month, u8 day);
u16 RtcGetDayCount(struct SiiRtcInfo *rtc);
void RtcInit(void);
u16 RtcGetErrorStatus(void);
void RtcGetInfo(struct SiiRtcInfo *rtc);
void RtcGetDateTime(struct SiiRtcInfo *rtc);
void RtcGetStatus(struct SiiRtcInfo *rtc);
void RtcGetRawInfo(struct SiiRtcInfo *rtc);
u16 RtcCheckInfo(struct SiiRtcInfo *rtc);
void RtcReset(void);
void FormatDecimalTime(u8 *dest, s32 hour, s32 minute, s32 second);
void FormatHexTime(u8 *dest, s32 hour, s32 minute, s32 second);
void FormatHexRtcTime(u8 *dest);
void FormatDecimalDate(u8 *dest, s32 year, s32 month, s32 day);
void FormatHexDate(u8 *dest, s32 year, s32 month, s32 day);
void RtcCalcTimeDifference(struct SiiRtcInfo *rtc, struct Time *result, struct Time *t);
void RtcCalcLocalTime(void);
bool8 IsBetweenHours(s32 hours, s32 begin, s32 end);
enum TimeOfDay GetTimeOfDay(void);
enum TimeOfDay GetTimeOfDayForDex(void);
void RtcInitLocalTimeOffset(s32 hour, s32 minute);
void RtcCalcLocalTimeOffset(s32 days, s32 hours, s32 minutes, s32 seconds);
void CalcTimeDifference(struct Time *result, struct Time *t1, struct Time *t2);
u32 RtcGetMinuteCount(void);
u32 RtcGetLocalDayCount(void);
void FormatDecimalTimeWithoutSeconds(u8 *dest, s8 hour, s8 minute, bool32 is24Hour);
u16 GetFullYear(void);
enum Month GetMonth(void);
u8 GetDay(void);
enum Weekday GetDayOfWeek(void);
enum TimeOfDay TryIncrementTimeOfDay(enum TimeOfDay timeOfDay);
enum TimeOfDay TryDecrementTimeOfDay(enum TimeOfDay timeOfDay);
void TrySetSoulkeepAmbiance(void);

#endif // GUARD_RTC_UTIL_H
