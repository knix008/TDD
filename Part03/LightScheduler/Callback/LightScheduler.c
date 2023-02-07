#include <stdbool.h>
#include "TimeService.h"
#include "LightController.h"
#include "LightScheduler.h"

enum
{
    UNUSED = -1,
    TURN_OFF,
    TURN_ON,
    MAX_EVENTS = 128
};

typedef struct
{
    int id;
    int event;
    Day day;
    int minuteOfDay;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

void LightScheduler_Create(void)
{
    scheduledEvent.id = UNUSED;
    TimeService_SetPeriodicAlarmInSeconds(60, LightScheduler_Wakeup);
}

static void scheduleEvent(int id, Day day, int minuteOfDay, int event)
{
    scheduledEvent.minuteOfDay = minuteOfDay;
    scheduledEvent.day = day;
    scheduledEvent.event = event;
    scheduledEvent.id = id;
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_ON);
}

void LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    scheduleEvent(id, day, minuteOfDay, TURN_OFF);
}

static void operateLight(ScheduledLightEvent *lightEvent)
{
    if (lightEvent->event == TURN_ON)
        LightController_On(lightEvent->id);
    else if (lightEvent->event == TURN_OFF)
        LightController_Off(lightEvent->id);
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

void LightScheduler_Wakeup(void)
{
    Time time;

    TimeService_GetTime(&time);
    processEventDueNow(&time, &scheduledEvent);
}

void LightScheduler_Destroy(void)
{
    TimeService_CancelPeriodicAlarmInSeconds(60, LightScheduler_Wakeup);
}

void LightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay)
{
}