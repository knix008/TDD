#include <CppUTest/CommandLineTestRunner.h>
#include <memory.h>
#include "Time.h"
#include "TimeService.h"
#include "FakeTimeService.h"
#include "FakeRandomMinute.h"
#include "LightDriver.h"
#include "LightDriverSpy.h"
#include "LightController.h"
#include "LightScheduler.h"
#include "RandomMinute.h"

TEST_GROUP(LightScheduler)
{
   int scheduledMinute;
   int expectedId;
   int expectedLevel;
   int lightNumber;

   void setup()
   {
      LightDriverSpy_Reset();
      LightDriverSpy_InstallInterface();
      LightController_Create();
      LightDriverSpy_AddSpiesToController();
      LightScheduler_Create();

      scheduledMinute = 1234;
      checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
      lightNumber = 4;
   }

   void teardown()
   {
      LightScheduler_Destroy();
      LightController_Destroy();
   }

   void checkLightState(int id, int level)
   {
      if (id == LIGHT_ID_UNKNOWN)
      {
         LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightDriverSpy_GetLastState());
      }
      else
      {
         LONGS_EQUAL(level, LightDriverSpy_GetState(id));
      }
   }

   void setTimeTo(Day day, int minute)
   {
      FakeTimeService_SetDay(day);
      FakeTimeService_SetMinute(minute);
   }
};

TEST(LightScheduler, CreateDoesNotChangeTheLights)
{
   LONGS_EQUAL(LIGHT_ID_UNKNOWN, LightDriverSpy_GetLastId());
   LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightDriverSpy_GetLastState());
}

TEST(LightScheduler, ScheduleEverydayNotTimeYet)
{
   LightScheduler_ScheduleTurnOn(3, EVERYDAY, scheduledMinute);
   setTimeTo(MONDAY, scheduledMinute - 1);
   LightScheduler_WakeUp();
   checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, ScheduleOnTodayItsTime)
{
   LightScheduler_ScheduleTurnOn(3, EVERYDAY, scheduledMinute);
   setTimeTo(MONDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(3, LIGHT_ON);
}

TEST(LightScheduler, ScheduleOnTuesdayAndItsNotTuesdayAndItsTime)
{
   LightScheduler_ScheduleTurnOn(3, TUESDAY, scheduledMinute);
   setTimeTo(MONDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, ScheduleOnTuesdayAndItsTuesdayAndItsTime)
{
   LightScheduler_ScheduleTurnOn(3, TUESDAY, scheduledMinute);
   setTimeTo(TUESDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(3, LIGHT_ON);
}

TEST(LightScheduler, ScheduleOffTuesdayAndItsTuesdayAndItsTime)
{
   LightScheduler_ScheduleTurnOff(lightNumber, TUESDAY, scheduledMinute);
   setTimeTo(TUESDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(lightNumber, LIGHT_OFF);
}

TEST(LightScheduler, ScheduleOffWeekendAndItsSaturdayAndItsTime)
{
   LightScheduler_ScheduleTurnOff(lightNumber, WEEKEND, scheduledMinute);
   setTimeTo(SATURDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(lightNumber, LIGHT_OFF);
}

TEST(LightScheduler, ScheduleOnWeekendAndItsSundayAndItsTime)
{
   LightScheduler_ScheduleTurnOn(lightNumber, WEEKEND, scheduledMinute);
   setTimeTo(SUNDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(lightNumber, LIGHT_ON);
}

TEST(LightScheduler, ScheduleOnWeekendAndItsMondayAndItsTime)
{
   LightScheduler_ScheduleTurnOff(lightNumber, WEEKEND, scheduledMinute);
   setTimeTo(MONDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, ScheduleOnWeekdayAndItsSundayAndItsTime)
{
   LightScheduler_ScheduleTurnOn(lightNumber, WEEKEND, scheduledMinute);
   setTimeTo(SUNDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(lightNumber, LIGHT_ON);
}

TEST(LightScheduler, ScheduleOnWeekdayAndItsMondayAndItsTime)
{
   LightScheduler_ScheduleTurnOn(lightNumber, WEEKDAY, scheduledMinute);
   setTimeTo(MONDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(lightNumber, LIGHT_ON);
}

TEST(LightScheduler, ScheduleOnWeekdayAndItsFridayAndItsTime)
{
   LightScheduler_ScheduleTurnOn(lightNumber, WEEKDAY, scheduledMinute);
   setTimeTo(FRIDAY, scheduledMinute);
   LightScheduler_WakeUp();
   checkLightState(lightNumber, LIGHT_ON);
}

TEST(LightScheduler, ScheduleOnWeekdayAndItsSaturdayAndItsTime)
{
   LightScheduler_ScheduleTurnOn(lightNumber, WEEKDAY, scheduledMinute);

   setTimeTo(SATURDAY, scheduledMinute);
   LightScheduler_WakeUp();

   checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, RemoveScheduledEvent)
{
   LightScheduler_ScheduleTurnOn(6, MONDAY, scheduledMinute);
   LightScheduler_ScheduleRemove(6, MONDAY, scheduledMinute);

   setTimeTo(MONDAY, scheduledMinute);
   LightScheduler_WakeUp();

   checkLightState(LIGHT_ID_UNKNOWN, LIGHT_STATE_UNKNOWN);
}

TEST(LightScheduler, MultipleScheduledEventsSameTime)
{
   LightScheduler_ScheduleTurnOff(4, MONDAY, scheduledMinute);
   LightScheduler_ScheduleTurnOn(3, MONDAY, scheduledMinute);

   setTimeTo(MONDAY, scheduledMinute);
   LightScheduler_WakeUp();

   checkLightState(4, LIGHT_OFF);
   checkLightState(3, LIGHT_ON);
}

TEST(LightScheduler, MultipleScheduledEventsDifferentTimes)
{
   LightScheduler_ScheduleTurnOff(4, MONDAY, scheduledMinute);
   LightScheduler_ScheduleTurnOn(3, MONDAY, scheduledMinute + 1);

   setTimeTo(MONDAY, scheduledMinute);
   LightScheduler_WakeUp();

   checkLightState(4, LIGHT_OFF);

   setTimeTo(MONDAY, scheduledMinute + 1);
   LightScheduler_WakeUp();

   checkLightState(3, LIGHT_ON);
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}