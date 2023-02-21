#include <CppUTest/CommandLineTestRunner.h>
#include "LightDriver.h"

TEST_GROUP(LightDriver)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

#define NONSENSE_POINTER (LightDriver)~0
static LightDriver savedDriver = NONSENSE_POINTER;
static void shouldNotBeCalled(LightDriver self) { savedDriver = self ;}

LightDriverInterfaceStruct interface =
{
    shouldNotBeCalled,
    shouldNotBeCalled,
    shouldNotBeCalled
};

LightDriverStruct testDriver =
{
    "testDriver",
    13
};

TEST(LightDriver, NullDriverDoesNotCrash)
{
    LightDriver_SetInterface(&interface);
    LightDriver_TurnOn(NULL);
    LightDriver_TurnOff(NULL);
    LightDriver_Destroy(NULL);
    POINTERS_EQUAL(NONSENSE_POINTER, savedDriver);
}

TEST(LightDriver, NullInterfaceDoesNotCrash)
{
    LightDriver_SetInterface(NULL);
    LightDriver_TurnOn(&testDriver);
    LightDriver_TurnOff(&testDriver);
    LightDriver_Destroy(&testDriver);
    POINTERS_EQUAL(NONSENSE_POINTER, savedDriver);
}

TEST(LightDriver, Accessors)
{
    LONGS_EQUAL(13, LightDriver_GetId(&testDriver));
    STRCMP_EQUAL("testDriver", LightDriver_GetType(&testDriver));
}

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}
