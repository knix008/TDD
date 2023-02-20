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
void LightScheduler_ScheduleTurnOn(int id, Day day, long int minute);
void LightScheduler_ScheduleTurnOff(int id, Day day, long int minute);
void LightScheduler_Randomize(int id, Day day, long int minute);
void LightScheduler_ScheduleRemove(int id, Day day, long int minute);
void LightScheduler_WakeUp(void);

#endif