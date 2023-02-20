#include <CppUTest/CommandLineTestRunner.h>
#include "Time.h"
#include "TimeService.h"
#include "FakeTimeService.h"

TEST_GROUP(Time)
{
    Time time;
    void setup()
    {
        TimeService_Create();
    }
    void givenThatItIs(Day day)
    {
        FakeTimeService_SetDay(day);
    }
    void CheckThatTimeMatches(Day day)
    {
        TimeService_GetTime(&time);
        CHECK(Time_MatchesDayOfWeek(&time, day));
    }
    void CheckThatTimeDoesNotMatch(Day day)
    {
        TimeService_GetTime(&time);
        CHECK(!Time_MatchesDayOfWeek(&time, day));
    }
};

TEST(Time, ExactMatch)
{
    givenThatItIs(MONDAY);
    CheckThatTimeMatches(MONDAY);
    givenThatItIs(TUESDAY);
    CheckThatTimeMatches(TUESDAY);
    givenThatItIs(WEDNESDAY);
    CheckThatTimeMatches(WEDNESDAY);
    givenThatItIs(THURSDAY);
    CheckThatTimeMatches(THURSDAY);
    givenThatItIs(FRIDAY);
    CheckThatTimeMatches(FRIDAY);
    givenThatItIs(SATURDAY);
    CheckThatTimeMatches(SATURDAY);
    givenThatItIs(SUNDAY);
    CheckThatTimeMatches(SUNDAY);
}

TEST(Time, WeekendDays)
{
    givenThatItIs(SATURDAY);
    CheckThatTimeMatches(WEEKEND);
    givenThatItIs(SUNDAY);
    CheckThatTimeMatches(WEEKEND);
}

TEST(Time, NotWeekendDays)
{
    givenThatItIs(MONDAY);
    CheckThatTimeDoesNotMatch(WEEKEND);
    givenThatItIs(TUESDAY);
    CheckThatTimeDoesNotMatch(WEEKEND);
    givenThatItIs(WEDNESDAY);
    CheckThatTimeDoesNotMatch(WEEKEND);
    givenThatItIs(THURSDAY);
    CheckThatTimeDoesNotMatch(WEEKEND);
    givenThatItIs(FRIDAY);
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}
