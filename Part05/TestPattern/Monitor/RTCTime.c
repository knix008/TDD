#include <stdlib.h>
#include <memory.h>
#include "RTCTime.h"

struct RtcTime
{
    int daysSince1980;
    int year;
    int dayOfYear;
    int month;
    int dayOfMonth;
    int dayOfWeek;
};

enum
{
    STARTING_YEAR = 1980,
    STARTING_WEEKDAY = Tuesday
};

static const int nonLeapYearDaysPerMonth[12] =
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static const int leapYearDaysPerMonth[12] =
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isLeapYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 100 == 0)
        return false;
    if (year % 4 == 0)
        return true;
    return false;
}

static int GetDaysInYear(int year)
{
    if (isLeapYear(year))
        return 366;
    else
        return 365;
}

static void FirstSetYearAndDayOfYear(RtcTime *self)
{
    int days = self->daysSince1980;
    int year = STARTING_YEAR;
    int daysInYear = GetDaysInYear(year);

    while (days > daysInYear)
    {
        year++;
        days -= daysInYear;
        daysInYear = GetDaysInYear(year);
    }

    self->dayOfYear = days;
    self->year = year;
}

static void ThenSetMonthAndDayOfMonth(RtcTime *self)
{
    int month = 0;
    int days = self->dayOfYear;
    const int *daysPerMonth = nonLeapYearDaysPerMonth;
    if (isLeapYear(self->year))
        daysPerMonth = leapYearDaysPerMonth;

    while (days > daysPerMonth[month])
    {
        days -= daysPerMonth[month];
        month++;
    }
    self->month = month + 1;
    self->dayOfMonth = days;
}

static void setDayOfWeek(RtcTime *self)
{
    self->dayOfWeek = ((self->daysSince1980 - 1) + STARTING_WEEKDAY) % 7;
}

static void initRtcTime(RtcTime *self)
{
    FirstSetYearAndDayOfYear(self);
    ThenSetMonthAndDayOfMonth(self);
    setDayOfWeek(self);
}

RtcTime *RtcTime_Create(int daysSince1980)
{
    RtcTime *self = (RtcTime *)calloc(1, sizeof(RtcTime));
    self->daysSince1980 = daysSince1980;
    initRtcTime(self);
    return self;
}

void RtcTime_Destroy(RtcTime *self)
{
    free(self);
}

int RtcTime_GetYear(RtcTime *self)
{
    return self->year;
}

int RtcTime_GetMonth(RtcTime *self)
{
    return self->month;
}

int RtcTime_GetDayOfMonth(RtcTime *self)
{
    return self->dayOfMonth;
}

int RtcTime_GetDayOfWeek(RtcTime *self)
{
    return self->dayOfWeek;
}
