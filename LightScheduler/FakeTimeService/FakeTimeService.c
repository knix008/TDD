#include <stdlib.h>
#include <stdbool.h>
#include "FakeTimeService.h"

static Time fakeTime;
static WakeupCallback callback;
static int period;

void TimeService_Create(void)
{
    fakeTime.minuteOfDay = TIME_UNKNOWN;
    fakeTime.dayOfWeek = NONE;
    callback = NULL;
    period = -1;
}

void TimeService_Destroy(void)
{
}

void FakeTimeService_MinuteIsUp(void)
{
    if (callback != NULL)
        ;
    callback();
}

void TimeService_SetPeriodicAlarmInSeconds(int seconds, WakeupCallback cb)
{
    callback = cb;
    period = seconds;
}

void TimeService_CancelPeriodicAlarmInSeconds(int seconds, WakeupCallback cb)
{
    if (cb == callback && period == seconds)
    {
        callback = NULL;
        period = 0;
    }
}

void TimeService_GetTime(Time *time)
{
    time->minuteOfDay = fakeTime.minuteOfDay;
    time->dayOfWeek = fakeTime.dayOfWeek;
}

int TimeService_GetMinute(void)
{
    return fakeTime.minuteOfDay;
}

int TimeService_GetDay(void)
{
    return fakeTime.dayOfWeek;
}

void FakeTimeService_SetMinute(int minute)
{
    fakeTime.minuteOfDay = minute;
}

void FakeTimeService_SetDay(Day day)
{
    fakeTime.dayOfWeek = day;
}

WakeupCallback FakeTimeSource_GetAlarmCallback(void)
{
    return callback;
}

int FakeTimeSource_GetAlarmPeriod(void)
{
    return period;
}

bool TimeService_MatchesNow(int reactionDay, int minute)
{
    int today;

    if (TimeService_GetMinute() != minute)
        return false;

    today = TimeService_GetDay();
    if (reactionDay == EVERYDAY)
        return true;
    if (reactionDay == today)
        return true;
    if (reactionDay == WEEKEND && (SATURDAY == today || SUNDAY == today))
        return true;
    if (reactionDay == WEEKDAY && today >= MONDAY && today <= FRIDAY)
        return true;
    return false;
}