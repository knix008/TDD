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
    int minuteOfDay;
} ScheduledLightEvent;

static ScheduledLightEvent scheduledEvent;

void LightScheduler_Create(void)
{
    scheduledEvent.id = UNUSED;
}

void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay)
{
    scheduledEvent.id = id;
    scheduledEvent.minuteOfDay = minuteOfDay;
}

void LightScheduler_Wakeup(void)
{
    Time time;
    TimeService_GetTime(&time);
    if (scheduledEvent.id == UNUSED)
        return;
    if (time.minuteOfDay != scheduledEvent.minuteOfDay)
        return;
    LightController_On(scheduledEvent.id);
}

void LightScheduler_Destroy(void)
{
}

int LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay)
{
    return 0;
}

void LightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay)
{
}