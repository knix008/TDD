#ifndef __LIGHTSCHEDULER_H__
#define __LIGHTSCHEDULER_H__

enum
{
    LS_OK = 0,
    LS_TOO_MANY_EVENTS,
    LS_ID_OUT_OF_BOUNDS
};

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
int LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay);
int LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay);
void LightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay);
void LightScheduler_Wakeup(void);

#endif