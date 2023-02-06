#include <CppUTest/CommandLineTestRunner.h>
#include "LightScheduler.h"

TEST_GROUP(LightScheduler){
    void setup(){} void teardown(){}};

/* 
TEST(LightScheduler, ScheduleOnEverydayNotTimeYet)
{
   LightScheduler_ScheduleTurnOn(3, EVERYDAY, 1200);
   FakeTimeService_SetDay(MONDAY);
   FakeTimeService_SetMinute(1199);
   LightScheduler_Wakeup();
   LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
   LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}
*/

TEST(LightScheduler, NoChangeToLightsDuringInitialization)
{
   //LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
   //LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}