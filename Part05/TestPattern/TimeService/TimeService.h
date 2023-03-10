#ifndef __TIMESERVICE_H__
#define __TIMESERVICE_H__
#include <stdbool.h>
#include "Time.h"

void TimeService_Create(void);
void TimeService_Destroy(void);
int TimeService_GetMinute(void);
int TimeService_GetDay(void);
void TimeService_GetTime(Time *);

typedef void (*WakeupCallback)(void);

void TimeService_SetPeriodicAlarmInSeconds(int seconds, WakeupCallback);
void TimeService_CancelPeriodicAlarmInSeconds(int seconds, WakeupCallback);
bool TimeService_MatchesNow(int reactionDay, int minute);

#endif