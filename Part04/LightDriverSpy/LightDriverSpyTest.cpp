#include <CppUTest/CommandLineTestRunner.h>
#include "LightDriverSpy.h"

TEST_GROUP(LightDriverSpy)
{
    LightDriver lightDriverSpy;

    void setup()
    {
        LightDriverSpy_Reset();
        lightDriverSpy = LightDriverSpy_Create(1);
    }

    void teardown()
    {
        LightDriverSpy_Destroy(lightDriverSpy);
    }
};

TEST(LightDriverSpy, Create)
{
    LONGS_EQUAL(LIGHT_STATE_UNKNOWN, LightDriverSpy_GetState(1));
}

TEST(LightDriverSpy, On)
{
    LightDriverSpy_TurnOn(lightDriverSpy);
    LONGS_EQUAL(LIGHT_ON, LightDriverSpy_GetState(1));
}

TEST(LightDriverSpy, Off)
{
    LightDriverSpy_TurnOff(lightDriverSpy);
    LONGS_EQUAL(LIGHT_OFF, LightDriverSpy_GetState(1));
}

TEST(LightDriverSpy, RecordsLastIdLastTurnOn)
{
    LightDriverSpy_TurnOff(lightDriverSpy);
    LONGS_EQUAL(1, LightDriverSpy_GetLastId());
    LONGS_EQUAL(LIGHT_OFF, LightDriverSpy_GetLastState());
}

TEST(LightDriverSpy, RecordsLastIdLastTurnOff)
{
    LightDriverSpy_TurnOn(lightDriverSpy);
    LONGS_EQUAL(1, LightDriverSpy_GetLastId());
    LONGS_EQUAL(LIGHT_ON, LightDriverSpy_GetLastState());
}

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}

