#include <CppUTest/CommandLineTestRunner.h>
#include <memory.h>
#include "LightController.h"

TEST_GROUP(LightController)
{
    LightDriver spy;
    void setup()
    {
        LightController_Create();
        LightDriverSpy_AddSpiesToController();
    }

    void teardown()
    {
        LightController_Destroy();
    }
};

TEST(LightController, TurnOn)
{
    LightController_TurnOn(7);
    LONGS_EQUAL(LIGHT_ON, LightDriverSpy_GetState(7));
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}