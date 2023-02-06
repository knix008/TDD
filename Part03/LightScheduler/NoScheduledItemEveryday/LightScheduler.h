#ifndef __LIGHTSCHEDULER_H__
#define __LIGHTSCHEDULER_H__

#include "TimeService.h"

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
int LightScheduler_ScheduleTurnOn(int id, Day day, int minute);
int LightScheduler_ScheduleTurnOff(int id, Day day, int minute);
void LightScheduler_ScheduleRemove(int id, Day day, int minute);
void LightScheduler_Wakeup(void);

#endif