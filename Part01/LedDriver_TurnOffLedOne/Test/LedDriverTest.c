#include "unity_fixture.h"
#include "LedDriver.h"

TEST_GROUP(LedDriver);

TEST_SETUP(LedDriver)
{
}

TEST_TEAR_DOWN(LedDriver)
{
}

TEST(LedDriver, TurnOnLedOne)
{
    uint16_t virtualLeds;

    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(1);
    TEST_ASSERT_EQUAL_HEX16(1, virtualLeds);
}

TEST(LedDriver, TurnOffLedOne)
{
    uint16_t virtualLeds;
    
    LedDriver_Create(&virtualLeds);
    LedDriver_TurnOn(1);
    LedDriver_TurnOff(1);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST(LedDriver, LedsOffAfterCreate)
{
    uint16_t virtualLeds = 0xffff;

    LedDriver_Create(&virtualLeds);
    TEST_ASSERT_EQUAL_HEX16(0, virtualLeds);
}

TEST_GROUP_RUNNER(LedDriver)
{
    RUN_TEST_CASE(LedDriver, LedsOffAfterCreate);
    RUN_TEST_CASE(LedDriver, TurnOnLedOne);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(LedDriver);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}