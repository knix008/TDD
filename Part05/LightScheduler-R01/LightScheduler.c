#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Time.h"
#include "TimeService.h"
#include "RandomMinute.h"
#include "LightDriver.h"
#include "LightController.h"
#include "LightScheduler.h"

enum
{
    TURN_ON,
    TURN_OFF,
    DIM,
    RANDOM_ON,
    RANDOM_OFF
};

enum
{
    MAX_EVENTS = 64,
    UNUSED = -1
};

typedef struct
{
    int id;
    Day day;
    long int minuteOfDay;
    int event;
    int randomize;
    int randomMinutes;

} ScheduledLightEvent;

static ScheduledLightEvent eventList[MAX_EVENTS];

void LightScheduler_Create(void)
{
    int i;
    ScheduledLightEvent *event = eventList;

    for (i = 0; i < MAX_EVENTS; i++, event++)
    {
        event->id = UNUSED;
    }
}

void LightScheduler_Destroy(void)
{
}

static void resetRandomize(ScheduledLightEvent *e);

static void setEventSchedule(ScheduledLightEvent *event, int id, Day day, long int minute, int control, int randomize)
{
    event->id = id;
    event->day = day;
    event->minuteOfDay = minute;
    event->event = control;
    event->randomize = randomize;
    resetRandomize(event);
}

static bool isInUse(ScheduledLightEvent *event)
{
    return event->id != UNUSED;
}

static ScheduledLightEvent *findUnusedEvent(void)
{
    int i;
    ScheduledLightEvent *event = eventList;

    for (i = 0; i < MAX_EVENTS; i++, event++)
    {
        if (!isInUse(event))
            return event;
    }
    return NULL;
}

static void scheduleEvent(int id, Day day, long int minute, int control, int randomize)
{
    ScheduledLightEvent *event = findUnusedEvent();
    if (event)
        setEventSchedule(event, id, day, minute, control, randomize);
}

void LightScheduler_ScheduleTurnOn(int id, Day day, long int minute)
{
    scheduleEvent(id, day, minute, TURN_ON, RANDOM_OFF);
}

void LightScheduler_ScheduleTurnOff(int id, Day day, long int minute)
{
    scheduleEvent(id, day, minute, TURN_OFF, RANDOM_OFF);
}

static bool matchEvent(ScheduledLightEvent *e, int id, Day day, long int minute)
{
    return e->id == id && e->day == day && e->minuteOfDay == minute;
}

void LightScheduler_Randomize(int id, Day day, long int minute)
{
    int i;
    ScheduledLightEvent *event = eventList;

    for (i = 0; i < MAX_EVENTS; i++, event++)
    {
        if (matchEvent(event, id, day, minute))
        {
            event->randomize = RANDOM_ON;
            resetRandomize(event);
        }
    }
}

void LightScheduler_ScheduleRemove(int id, Day day, long int minute)
{
    int i;
    ScheduledLightEvent *event = eventList;

    for (i = 0; i < MAX_EVENTS; i++, event++)
    {
        if (matchEvent(event, id, day, minute))
            event->id = UNUSED;
    }
}

static void operateLight(ScheduledLightEvent *event)
{
    if (event->event == TURN_ON)
        LightController_TurnOn(event->id);
    else if (TURN_OFF == event->event)
        LightController_TurnOff(event->id);
}

static void resetRandomize(ScheduledLightEvent *event)
{
    if (event->randomize == RANDOM_ON)
        event->randomMinutes = RandomMinute_Get();
    else
        event->randomMinutes = 0;
}

static bool isEventDueNow(Time *time, ScheduledLightEvent *event)
{
    int todaysMinute = event->minuteOfDay + event->randomMinutes;
    Day day = event->day;
    if (!Time_MatchesMinuteOfDay(time, todaysMinute))
        return false;
    if (!Time_MatchesDayOfWeek(time, day))
        return false;
    return true;
}

static void processEventsDueNow(Time *time, ScheduledLightEvent *event)
{
    if (!isInUse(event))
        return;

    if (isEventDueNow(time, event))
    {
        operateLight(event);
        resetRandomize(event);
    }
}

void LightScheduler_WakeUp(void)
{
    int i;
    Time time;

    TimeService_GetTime(&time);

    for (i = 0; i < MAX_EVENTS; i++)
    {
        processEventsDueNow(&time, &eventList[i]);
    }
}
