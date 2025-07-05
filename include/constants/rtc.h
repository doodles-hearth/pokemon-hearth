#ifndef GUARD_CONSTANTS_RTC_H
#define GUARD_CONSTANTS_RTC_H

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

//Morning and evening don't exist in Gen 3
#if OW_TIMES_OF_DAY == GEN_3
    #define MORNING_HOUR_BEGIN 0
    #define MORNING_HOUR_END   0

    #define DAY_HOUR_BEGIN     12
    #define DAY_HOUR_END       HOURS_PER_DAY

    #define EVENING_HOUR_BEGIN 0
    #define EVENING_HOUR_END   0

    #define NIGHT_HOUR_BEGIN   0
    #define NIGHT_HOUR_END     12
//Evening doesn't exist in Gen 4
#elif OW_TIMES_OF_DAY == GEN_4
    #define MORNING_HOUR_BEGIN 4
    #define MORNING_HOUR_END   10

    #define DAY_HOUR_BEGIN     10
    #define DAY_HOUR_END       20

    #define EVENING_HOUR_BEGIN 0
    #define EVENING_HOUR_END   0

    #define NIGHT_HOUR_BEGIN   20
    #define NIGHT_HOUR_END     4
//Gen 5 currently not included as the seasons change the times of day
#elif OW_TIMES_OF_DAY <= GEN_6
    #define MORNING_HOUR_BEGIN 4
    #define MORNING_HOUR_END   11

    #define DAY_HOUR_BEGIN     11
    #define DAY_HOUR_END       18

    #define EVENING_HOUR_BEGIN 18
    #define EVENING_HOUR_END   21

    #define NIGHT_HOUR_BEGIN   21
    #define NIGHT_HOUR_END     4
//These are the Sun/Ultra Sun times
#elif OW_TIMES_OF_DAY == GEN_7
    #define MORNING_HOUR_BEGIN 6
    #define MORNING_HOUR_END   10

    #define DAY_HOUR_BEGIN     10
    #define DAY_HOUR_END       17

    #define EVENING_HOUR_BEGIN 17
    #define EVENING_HOUR_END   18

    #define NIGHT_HOUR_BEGIN   18
    #define NIGHT_HOUR_END     6
#elif OW_TIMES_OF_DAY >= GEN_8 && OW_TIMES_OF_DAY != RTC_CUSTOM
    #define MORNING_HOUR_BEGIN 6
    #define MORNING_HOUR_END   10

    #define DAY_HOUR_BEGIN     10
    #define DAY_HOUR_END       19

    #define EVENING_HOUR_BEGIN 19
    #define EVENING_HOUR_END   20

    #define NIGHT_HOUR_BEGIN   20
    #define NIGHT_HOUR_END     6
#elif OW_TIMES_OF_DAY == RTC_CUSTOM
    #define DEAD_NIGHT_HOUR_BEGIN    0
    #define DEAD_NIGHT_HOUR_END      5

    #define EARLY_MORNING_HOUR_BEGIN 5
    #define EARLY_MORNING_HOUR_END   8

    #define MORNING_HOUR_BEGIN       8
    #define MORNING_HOUR_END         12

    #define LUNCHTIME_HOUR_BEGIN     12
    #define LUNCHTIME_HOUR_END       14

    #define AFTERNOON_HOUR_BEGIN     14
    #define AFTERNOON_HOUR_END       18

    #define EVENING_HOUR_BEGIN       18
    #define EVENING_HOUR_END         22

    #define NIGHTTIME_HOUR_BEGIN     22
    #define NIGHTTIME_HOUR_END       0
#endif

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

#define TIME_OF_DAY_DEFAULT TIME_MORNING

#define TIME_NOONTIME_FLAG      (1 << 0)
#define TIME_DEAD_NIGHT_FLAG    (1 << 1)
#define TIME_EARLY_MORNING_FLAG (1 << 2)
#define TIME_EVENING_FLAG       (1 << 3)
#define TIME_LUNCHTIME_FLAG     (1 << 4)
#define TIME_MORNING_FLAG       (1 << 5)
#define TIME_NIGHT_FLAG         (1 << 6)

#endif // GUARD_CONSTANTS_RTC_H
