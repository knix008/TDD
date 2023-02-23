#include "unity_fixture.h"
#include "MockIO.h"
#include "FlashDriver.h"

TEST_GROUP(LegacyFlash);

/*
ioAddress address = 0x1000;
ioData data = 0xBEEF;
*/
int result = -1;

TEST_SETUP(LegacyFlash)
{
    MockIO_Init();
}

TEST_TEAR_DOWN(LegacyFlash)
{
    Flash_Destroy();
    MockIO_Verify();
    MockIO_Destroy();
}

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

#if 0 //START: FlashProgramSuccess4
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
#endif //END: FlashProgramSuccess4

#if 0 //START: FlashProgramSuccess3
TEST(LegacyFlash, FlashProgramSuccess)
{
    MockIO_Expect_Write(CommandRegister, ProgramCommand);
    MockIO_Expect_Write(0x1000, 0xBEEF);
    result = Flash_Write(0x1000, 0xBEEF);
    LONGS_EQUAL(0, result);
}
#endif //END: FlashProgramSuccess3

#if 0 //START: FlashProgramSuccess2
TEST(LegacyFlash, FlashProgramSuccess)
{
    MockIO_Expect_Write(CommandRegister, ProgramCommand);
    result = Flash_Write(0x1000, 0xBEEF);
    LONGS_EQUAL(0, result);
}
#endif //END: FlashProgramSuccess2

#if 0 //START: FlashProgramSuccess1
TEST(LegacyFlash, FlashProgramSuccess)
{
    result = Flash_Write(0x1000, 0xBEEF);
    LONGS_EQUAL(0, result);
}
#endif //END: FlashProgramSuccess1

#if 0 //START: FlashProgramSuccess0
TEST(LegacyFlash, FlashProgramSuccess)
{
    FAIL("Getting started");
}
#endif //END: FlashProgramSuccess0

TEST_GROUP_RUNNER(LegacyFlash)
{
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


