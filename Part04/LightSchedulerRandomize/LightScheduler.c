#include <stdbool.h>
#include "TimeService.h"
#include "LightController.h"
#include "LightScheduler.h"
#include "RandomMinute.h"

enum
{
    UNUSED = -1,
    TURN_OFF,
    TURN_ON,
    DIM,
    RANDOM_ON,
    RANDOM_OFF,
    MAX_EVENTS = 128
};

typedef struct
{
    int id;
    int event;
    Day day;
    int minuteOfDay;
    int randomize;
    int randomMinutes;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvents[MAX_EVENTS];

static int scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
    int i;

    if (id < 0 || id >= MAX_LIGHTS)
        return LS_ID_OUT_OF_BOUNDS;

    for (i = 0; i < MAX_EVENTS; i++)
    {
        if (scheduledEvents[i].id == UNUSED)
        {
            scheduledEvents[i].day = day;
            scheduledEvents[i].minuteOfDay = minuteOfDay;
            scheduledEvents[i].event = event;
            scheduledEvents[i].id = id;
            return LS_OK;
        }
    }
    return LS_TOO_MANY_EVENTS;
}

static void operateLight(ScheduledLightEvent *lightEvent)
{
    if (lightEvent->event == TURN_ON){
        LightController_On(lightEvent->id);
    }
    else if (lightEvent->event == TURN_OFF) {
        LightController_Off(lightEvent->id);
    }
}

static bool DoesLightRespondToday(Time *time, int reactionDay)
{
    int today = time->dayOfWeek;

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

static void processEventDueNow(Time *time, ScheduledLightEvent *lightEvent)
{
    if (lightEvent->id == UNUSED)
        return;
    if (!DoesLightRespondToday(time, lightEvent->day))
        return;
    if (lightEvent->minuteOfDay != time->minuteOfDay)
        return;
    operateLight(lightEvent);
}

void LightScheduler_Create(void)
{
    int i;

    for (i = 0; i < MAX_EVENTS; i++)
        scheduledEvents[i].id = UNUSED;

    TimeService_SetPeriodicAlarmInSeconds(60, LightScheduler_WakeUp);
}

int LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    return scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

int LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    return scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}

void LightScheduler_WakeUp(void)
{
    int i;
    Time time;
    Day td;
    int min;

    TimeService_GetTime(&time);
    td = time.dayOfWeek;
    min = time.minuteOfDay;

    for (i = 0; i < MAX_EVENTS; i++)
    {
        ScheduledLightEvent * se = &scheduledEvents[i];
        if (se->id != UNUSED)
        {
            Day d = se->day;
            if ( (d == EVERYDAY) || (d == td) || (d == WEEKEND && (SATURDAY == td || SUNDAY == td)) || (d == WEEKDAY && (td >= MONDAY && td <= FRIDAY)))
            {
                /* it's the right day */
                if (min == se->minuteOfDay + se->randomMinutes)
                {
                    if (TURN_ON == se->event)
                        LightController_On(se->id);
                    else if (TURN_OFF == se->event)
                        LightController_Off(se->id);

                    if (se->randomize == RANDOM_ON)
                        se->randomMinutes = RandomMinute_Get();
                    else
                        se->randomMinutes = 0;

                }
            }
        }
    }
}

void LightScheduler_Destroy(void)
{
    TimeService_CancelPeriodicAlarmInSeconds(60, LightScheduler_WakeUp);
}

void LightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay)
{
    int i;

    for (i = 0; i < MAX_EVENTS; i++)
    {
        if (scheduledEvents[i].id == id && scheduledEvents[i].day == day && scheduledEvents[i].minuteOfDay == minuteOfDay)
        {
            scheduledEvents[i].id = UNUSED;
        }
    }
}

void LightScheduler_Randomize(int id, Day day, int minuteOfDay)
{
    int i;

    for (i = 0; i < MAX_EVENTS; i++)
    {
        ScheduledLightEvent *e = &scheduledEvents[i];
        if (e->id == id && e->day == day && e->minuteOfDay == minuteOfDay)
        {
            e->randomize = RANDOM_ON;
            e->randomMinutes = RandomMinute_Get();
        }
    }
}