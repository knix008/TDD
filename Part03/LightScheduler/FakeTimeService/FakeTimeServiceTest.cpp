#include <CppUTest/CommandLineTestRunner.h>

TEST_GROUP(FakeTimeService){
    void setup(){} void teardown(){}};

TEST(FakeTimeService, Create)
{
    Time time;
    TimeService_GetTime(&time);
    LONGS_EQUAL(TIME_UNKNOWN, time.minuteOfDay);
    LONGS_EQUAL(TIME_UNKNOWN, time.dayOfWeek);
}

TEST(FakeTimeService, Set)
{
    Time time;
    FakeTimeService_SetMinute(42);
    FakeTimeService_SetDay(SATURDAY);
    TimeService_GetTime(&time);
    LONGS_EQUAL(42, time.minuteOfDay);
    LONGS_EQUAL(SATURDAY, time.dayOfWeek);
}

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}