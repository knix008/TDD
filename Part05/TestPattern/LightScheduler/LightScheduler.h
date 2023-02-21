#ifndef __LIGHTSCHEDULER_H__
#define __LIGHTSCHEDULER_H__

#include "TimeService.h"

enum
{
    LS_OK,
    LS_TOO_MANY_EVENTS,
    LS_ID_OUT_OF_BOUNDS
};

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
int LightScheduler_ScheduleTurnOn(int id, Day day, int minute);
int LightScheduler_ScheduleTurnOff(int id, Day day, int minute);
void LightScheduler_ScheduleRemove(int id, Day day, int minute);
void LightScheduler_WakeUp(void);

#endif