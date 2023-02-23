#include "unity_fixture.h"
#include "MockIO.h"
#include "FlashDriver.h"

TEST_GROUP(LegacyFlash);

int result = -1;

TEST_SETUP(LegacyFlash)
{
    MockIO_Init();
    Flash_Create();
    result = 0;
}

TEST_TEAR_DOWN(LegacyFlash)
{
    Flash_Destroy();
    MockIO_Verify();
    MockIO_Destroy();
}

/*
TEST(LegacyFlash, FlashProgramSuccess)
{
    IO_Write_Expect(CommandRegister, ProgramCommand);
    IO_Write_Expect(0x1000, 0xBEEF);
    IO_Read_ExpectAndReturn(StatusRegister, 0);
    IO_Read_ExpectAndReturn(StatusRegister, 0);
    IO_Read_ExpectAndReturn(StatusRegister, ReadyBit);
    IO_Read_ExpectAndReturn(0x1000, 0xBEEF);
    result = Flash_Write(0x1000, 0xBEEF);
    TEST_ASSERT_EQUAL_INT32(0, result);
}

/*
TEST(LegacyFlash, FlashProgramSuccess)
{
    MockIO_Expect_Write(CommandRegister, ProgramCommand);
    MockIO_Expect_Write(0x1000, 0xBEEF);
    MockIO_Expect_ReadThenReturn(StatusRegister, 0);
    MockIO_Expect_ReadThenReturn(StatusRegister, 0);
    MockIO_Expect_ReadThenReturn(StatusRegister, ReadyBit);
    result = Flash_Write(0x1000, 0xBEEF);
    LONGS_EQUAL(0, result);
}

TEST(LegacyFlash, FlashProgramSuccess)
{
    MockIO_Expect_Write(CommandRegister, ProgramCommand);
    MockIO_Expect_Write(0x1000, 0xBEEF);
    result = Flash_Write(0x1000, 0xBEEF);
    LONGS_EQUAL(0, result);
}

TEST(LegacyFlash, FlashProgramSuccess)
{
    MockIO_Expect_Write(CommandRegister, ProgramCommand);
    result = Flash_Write(0x1000, 0xBEEF);
    LONGS_EQUAL(0, result);
}
*/

TEST(LegacyFlash, FlashProgramSuccess)
{
    result = Flash_Write(0x1000, 0xBEEF);
    TEST_ASSERT_EQUAL_INT32(0, result);
}

TEST(LegacyFlash, FlashProgramStart)
{
    TEST_IGNORE_MESSAGE("Flash Write Test - Getting Started!!!");
}

TEST_GROUP_RUNNER(LegacyFlash)
{
    RUN_TEST_CASE(LegacyFlash, FlashProgramStart);
    RUN_TEST_CASE(LegacyFlash, FlashProgramSuccess);
}

static void RunAllTests(void)
{
    RUN_TEST_GROUP(LegacyFlash);
}

int main(int argc, const char *argv[])
{
    return UnityMain(argc, argv, RunAllTests);
}


