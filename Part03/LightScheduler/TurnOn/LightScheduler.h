#ifndef __LIGHTSCHEDULER_H__
#define __LIGHTSCHEDULER_H__

#include "TimeService.h"
#include "LightController.h"

void LightScheduler_Create(void);
void LightScheduler_Destroy(void);
void LightScheduler_ScheduleTurnOn(int id, Day day, int minuteOfDay);
int LightScheduler_ScheduleTurnOff(int id, Day day, int minuteOfDay);
void LightScheduler_ScheduleRemove(int id, Day day, int minuteOfDay);
void LightScheduler_Wakeup(void);

#endif