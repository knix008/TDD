#ifndef __RTCTIME_H__
#define __RTCTIME_H__
#include <stdbool.h>

typedef struct RtcTime RtcTime;

RtcTime *RtcTime_Create(int daysSince1980);
void RtcTime_Destroy(RtcTime *);
int RtcTime_GetYear(RtcTime *);
int RtcTime_GetMonth(RtcTime *);
int RtcTime_GetDayOfMonth(RtcTime *);
int RtcTime_GetDayOfWeek(RtcTime *);
bool isLeapYear(int year);

enum
{
    Sunday = 0,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

#endif