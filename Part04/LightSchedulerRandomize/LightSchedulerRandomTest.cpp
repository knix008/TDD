#include <CppUTest/CommandLineTestRunner.h>
#include "FakeTimeService.h"
#include "FakeRandomMinute.h"
#include "LightControllerSpy.h"
#include "LightScheduler.h"
#include "RandomMinute.h"

TEST_GROUP(LightSchedulerRandomize)
{
   //int (*savedRandomMinute_Get)();
   void setup()
   {
         LightController_Create();
         LightScheduler_Create();
         //savedRandomMinute_Get = RandomMinute_Get;
         //RandomMinute_Get = FakeRandomMinute_Get;
         UT_PTR_SET(RandomMinute_Get, FakeRandomMinute_Get);
   }
   
   void teardown()
   {
      LightScheduler_Destroy();
      LightController_Destroy();
      //RandomMinute_Get = savedRandomMinute_Get;
   }
   
   void checkLightState(int id, int level)
   {
      if (id == LIGHT_ID_UNKNOWN)
      {
         LONGS_EQUAL(id, LightControllerSpy_GetLastId());
         LONGS_EQUAL(level, LightControllerSpy_GetLastState());
      }
      else
      {
         LONGS_EQUAL(level, LightControllerSpy_GetLightState(id));
      }
   }

   void setTimeTo(Day day, int minute)
   {
      FakeTimeService_SetDay(day);
      FakeTimeService_SetMinute(minute);
   }
};

TEST(LightSchedulerRandomize, TurnsOnEarly)
{
   FakeRandomMinute_SetFirstAndIncrement(-10, 5);
   LightScheduler_ScheduleTurnOn(4, EVERYDAY, 600);
   LightScheduler_Randomize(4, EVERYDAY, 600);
   //setTimeTo(MONDAY, 600);
   setTimeTo(MONDAY, 600 - 10);
   LightScheduler_WakeUp();
   checkLightState(4, LIGHT_ON);
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}