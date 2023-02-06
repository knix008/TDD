#include <CppUTest/CommandLineTestRunner.h>
#include "LightScheduler.h"
#include "FakeTimeService.h"
#include "LightControllerSpy.h"

TEST_GROUP(LightScheduler){
   void setup()
   {
        LightController_Create();
        LightScheduler_Create();
   }

   void teardown()
   {
      LightScheduler_Destroy();
      LightController_Destroy();
   }
};

TEST(LightScheduler, NoScheduledNothingHappens)
{
   FakeTimeService_SetDay(MONDAY);
   FakeTimeService_SetMinute(100);
   LightScheduler_Wakeup();
   LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightControllerSpy_GetLastId());
   LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightControllerSpy_GetLastState());
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}