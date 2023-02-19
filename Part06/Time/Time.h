#ifndef __TIME_H__
#define __TIME_H__

typedef enum Day
{
    NONE = -4,
    EVERYDAY = -3,
    WEEKDAY = -2,
    WEEKEND = -1,
    SUNDAY = 1,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY
} Day;

typedef enum Month
{
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC
} Month;

typedef struct Time Time;

struct Time
{
    int usec;
    int sec;
    int minuteOfDay;
    int minuteOfHour;
    Day dayOfWeek;
    int dayOfMonth;
    Month month;
};

bool Time_MatchesDayOfWeek(Time *time, Day day);
bool Time_MatchesMinuteOfDay(Time *time, int minute);

#endif