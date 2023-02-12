#include "unity_fixture.h"
#include "MockIO.h"
#include "FlashDriver.h"

TEST_GROUP(Flash);

ioAddress address = 0x1000;
ioData data = 0xBEEF;
int result = -1;

TEST_SETUP(Flash)
{
    MockIO_Init();
    Flash_Create();
}

TEST_TEAR_DOWN(Flash)
{
    // MockIO_Verify();
    Flash_Destroy();
    MockIO_Destroy();
}

TEST(Flash, WriteSucceeds_ReadyImmediately)
{
    IO_Write_Expect(CommandRegister, ProgramCommand);
    IO_Write_Expect(address, data);
    IO_Read_ExpectAndReturn(StatusRegister, ReadyBit);
    IO_Read_ExpectAndReturn(address, data);
    result = Flash_Write(address, data);
    TEST_ASSERT_EQUAL_INT32(FLASH_SUCCESS, result);
    MockIO_Verify();
}

TEST(Flash, ProgramSucceedsNotImmediatelyReady)
{
    IO_Write_Expect(CommandRegister, ProgramCommand);
    IO_Write_Expect(address, data);
    IO_Read_ExpectAndReturn(StatusRegister, 0);
    IO_Read_ExpectAndReturn(StatusRegister, 0);
    IO_Read_ExpectAndReturn(StatusRegister, 0);
    IO_Read_ExpectAndReturn(StatusRegister, ReadyBit);
    IO_Read_ExpectAndReturn(address, data);
    result = Flash_Write(address, data);
    TEST_ASSERT_EQUAL_INT32(FLASH_SUCCESS, result);
}

TEST_GROUP_RUNNER(Flash)
{
    RUN_TEST_CASE(Flash, WriteSucceeds_ReadyImmediately);
    RUN_TEST_CASE(Flash, ProgramSucceedsNotImmediatelyReady);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(Flash);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}