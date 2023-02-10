#include "unity_fixture.h"
#include "MockIO.h"
#include "FlashDriver.h"

TEST_GROUP(Flash);

TEST_SETUP(Flash)
{
    MockIO_Init();
}

TEST_TEAR_DOWN(Flash)
{
    MockIO_Destroy();
}

TEST(Flash, WriteSucceeds_ReadyImmediately)
{
    int result = 0;
    IO_Write_Expect(0, 0x40);
    IO_Write_Expect(0x1000, 0xBEEF);
    IO_Read_ExpectAndReturn(0, 1 << 7);
    IO_Read_ExpectAndReturn(0x1000, 0xBEEF);
    result = Flash_Write(0x1000, 0xBEEF);
    TEST_ASSERT_EQUAL_INT32(0, result);
    MockIO_Verify();
}

TEST_GROUP_RUNNER(Flash)
{
    RUN_TEST_CASE(Flash, WriteSucceeds_ReadyImmediately);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(Flash);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}