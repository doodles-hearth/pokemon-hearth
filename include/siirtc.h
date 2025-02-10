#ifndef GUARD_RTC_H
#define GUARD_RTC_H

#include "gba/gba.h"

#define SIIRTCINFO_INTFE  0x01 // frequency interrupt enable
#define SIIRTCINFO_INTME  0x02 // per-minute interrupt enable
#define SIIRTCINFO_INTAE  0x04 // alarm interrupt enable
#define SIIRTCINFO_24HOUR 0x40 // 0: 12-hour mode, 1: 24-hour mode
#define SIIRTCINFO_POWER  0x80 // power on or power failure occurred

#define HOURS_PER_DAY       24
#define MINUTES_PER_HOUR    60
#define SECONDS_PER_MINUTE  60

enum
{
    WEEKDAY_SUN,
    WEEKDAY_MON,
    WEEKDAY_TUE,
    WEEKDAY_WED,
    WEEKDAY_THU,
    WEEKDAY_FRI,
    WEEKDAY_SAT,
    WEEKDAY_COUNT,
};

enum
{
    MONTH_JAN = 1,
    MONTH_FEB = 2,
    MONTH_MAR = 3,
    MONTH_APR = 4,
    MONTH_MAY = 5,
    MONTH_JUN = 6,
    MONTH_JUL = 7,
    MONTH_AUG = 8,
    MONTH_SEP = 9,
    MONTH_OCT = 10,
    MONTH_NOV = 11,
    MONTH_DEC = 12,
};

struct SiiRtcInfo
{
    u8 year;
    u8 month;
    u8 day;
    u8 dayOfWeek;
    u8 hour;
    u8 minute;
    u8 second;
    u8 status;
    u8 alarmHour;
    u8 alarmMinute;
};

void SiiRtcUnprotect(void);
void SiiRtcProtect(void);
u8 SiiRtcProbe(void);
bool8 SiiRtcReset(void);
bool8 SiiRtcGetStatus(struct SiiRtcInfo *rtc);
bool8 SiiRtcSetStatus(struct SiiRtcInfo *rtc);
bool8 SiiRtcGetDateTime(struct SiiRtcInfo *rtc);
bool8 SiiRtcSetDateTime(struct SiiRtcInfo *rtc);
bool8 SiiRtcGetTime(struct SiiRtcInfo *rtc);
bool8 SiiRtcSetTime(struct SiiRtcInfo *rtc);
bool8 SiiRtcSetAlarm(struct SiiRtcInfo *rtc);

#endif // GUARD_RTC_H
