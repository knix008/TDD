#include <stdlib.h>
#include <stdbool.h>
#include "TimeService.h"

void TimeService_Create(void)
{
	/* OS dependent init */
	explodesInTestEnvironment(NULL);
}

void TimeService_Destroy(void)
{
	/* OS dependent cleanup */
	explodesInTestEnvironment(NULL);
}

int TimeService_GetMinute(void)
{
	/* OS dependent get minute */
	explodesInTestEnvironment(NULL);
	return 0;
}

int TimeService_GetDay(void)
{
	/* OS dependent get day */
	explodesInTestEnvironment(NULL);
	return 0;
}

bool TimeService_MatchesNow(int reactionDay, int minute)
{
    int today;

    if (TimeService_GetMinute() != minute)
        return false;

    today = TimeService_GetDay();
    if (reactionDay == EVERYDAY)
        return true;
    if (reactionDay == today)
        return true;
    if (reactionDay == WEEKEND && (SATURDAY == today || SUNDAY == today))
        return true;
    if (reactionDay == WEEKDAY && today >= MONDAY && today <= FRIDAY)
        return true;
    return false;
}

