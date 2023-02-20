#include <stdbool.h>
#include "Time.h"

bool Time_MatchesDayOfWeek(Time *time, Day day)
{
	int today = time->dayOfWeek;

	if (day == EVERYDAY)
		return true;
	if (day == today)
		return true;
	if (day == WEEKEND && (SATURDAY == today || SUNDAY == today))
		return true;
	if (day == WEEKDAY && today >= MONDAY && today <= FRIDAY)
		return true;
	return false;
}

bool Time_MatchesMinuteOfDay(Time *time, int minute)
{
	return time->minuteOfDay == minute;
}