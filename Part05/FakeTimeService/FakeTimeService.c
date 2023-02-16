#include <stdlib.h>
#include "Time.h"
#include "TimeService.h"
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