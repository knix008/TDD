#include <CppUTest/CommandLineTestRunner.h>
#include "LightDriver.h"
#include "LightController.h"
#include "LightDriverSpy.h"

TEST_GROUP(LightController){
    void setup(){
        LightController_Create();
LightDriverSpy_AddSpiesToController();
LightDriverSpy_Reset();
LightDriverSpy_InstallInterface();
}

void teardown()
{
    LightController_Destroy();
}
}
;

TEST(LightController, TurnOn)
{
    LightController_TurnOn(7);
    LONGS_EQUAL(LIGHT_ON, LightDriverSpy_GetState(7));
}

TEST(LightController, AddingDriverDestroysPrevious)
{
    LightDriver spy = LightDriverSpy_Create(1);
    LightController_Add(1, spy);
    LightController_Destroy();
}

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}