#ifndef __FAKETIMESERVICE_H__
#define __FAKETIMESERVICE_H__

#include "Time.h"
#include "TimeService.h"

enum {TIME_UNKNOWN = -1};

void FakeTimeService_SetMinute(int);
void FakeTimeService_SetDay(Day);
WakeupCallback FakeTimeSource_GetAlarmCallback(void);
int FakeTimeSource_GetAlarmPeriod(void);
void FakeTimeService_MinuteIsUp(void);

#endif
