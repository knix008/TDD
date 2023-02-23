#include "unity_fixture.h"
#include "MockIO.h"
#include "FlashDriver.h"
#include "FakeMicroTime.h"

TEST_GROUP(Flash);

ioAddress address = 0x1000;
ioData data = 0xBEEF;
int result = -1;

TEST_SETUP(Flash)
{
    MockIO_Init();
}

TEST_TEAR_DOWN(Flash)
{
    Flash_Destroy();
    MockIO_Verify();
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

TEST(Flash, WriteFails_VppError)
{
    IO_Write_Expect(CommandRegister, ProgramCommand);
    IO_Write_Expect(address, data);
    IO_Read_ExpectAndReturn(StatusRegister, ReadyBit | VppErrorBit);
    IO_Write_Expect(CommandRegister, Reset);
    result = Flash_Write(address, data);
    TEST_ASSERT_EQUAL_INT32(FLASH_VPP_ERROR, result);
}

TEST(Flash, WriteFails_FlashReadBackError)
{
    IO_Write_Expect(CommandRegister, ProgramCommand);
    IO_Write_Expect(address, data);
    IO_Read_ExpectAndReturn(StatusRegister, ReadyBit);
    IO_Read_ExpectAndReturn(address, data - 1);
    result = Flash_Write(address, data);
    TEST_ASSERT_EQUAL_INT32(FLASH_READ_BACK_ERROR, result);
}

TEST(Flash, WriteSucceeds_IgnoresOtherBitsUntilReady)
{
    IO_Write_Expect(CommandRegister, ProgramCommand);
    IO_Write_Expect(address, data);
    IO_Read_ExpectAndReturn(StatusRegister, ~ReadyBit);
    IO_Read_ExpectAndReturn(StatusRegister, ReadyBit);
    IO_Read_ExpectAndReturn(address, data);
    result = Flash_Write(address, data);
    TEST_ASSERT_EQUAL_INT32(FLASH_SUCCESS, result);
}

TEST(Flash, WriteFails_Timeout)
{
    FakeMicroTime_Init(0, 500);
    Flash_Create();
    IO_Write_Expect(CommandRegister, ProgramCommand);
    IO_Write_Expect(address, data);
    for (int i = 0; i < 10; i++)
        IO_Read_ExpectAndReturn(StatusRegister, ~ReadyBit);
    result = Flash_Write(address, data);
    TEST_ASSERT_EQUAL_INT32(FLASH_TIMEOUT_ERROR, result);
}

TEST(Flash, WriteFails_TimeoutAtEndOfTime)
{
    FakeMicroTime_Init(0xffffffff, 500);
    Flash_Create();
    IO_Write_Expect(CommandRegister, ProgramCommand);
    IO_Write_Expect(address, data);
    for (int i = 0; i < 10; i++)
        IO_Read_ExpectAndReturn(StatusRegister, ~ReadyBit);
    result = Flash_Write(address, data);
    TEST_ASSERT_EQUAL_INT32(FLASH_TIMEOUT_ERROR, result);
}

TEST_GROUP_RUNNER(Flash)
{
    RUN_TEST_CASE(Flash, WriteSucceeds_ReadyImmediately);
    RUN_TEST_CASE(Flash, ProgramSucceedsNotImmediatelyReady);
    RUN_TEST_CASE(Flash, WriteFails_VppError);
    RUN_TEST_CASE(Flash, WriteFails_FlashReadBackError);
    RUN_TEST_CASE(Flash, WriteSucceeds_IgnoresOtherBitsUntilReady);
    RUN_TEST_CASE(Flash, WriteFails_Timeout);
    RUN_TEST_CASE(Flash, WriteFails_TimeoutAtEndOfTime);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(Flash);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}