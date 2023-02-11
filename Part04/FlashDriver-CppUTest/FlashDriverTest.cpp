#include <CppUTest/CommandLineTestRunner.h>
#include "MockIO.h"
#include "FlashDriver.h"

TEST_GROUP(Flash)
{
    void setup()
    {
        MockIO_Init();
    }

    void teardown()
    {
        MockIO_Destroy();
    }
};

TEST(Flash, WriteSucceeds_ReadyImmediately)
{
    int result = 0;
    IO_Write_Expect(0, 0x40);
    IO_Write_Expect(0x1000, 0xBEEF);
    IO_Read_ExpectAndReturn(0, 1 << 7);
    IO_Read_ExpectAndReturn(0x1000, 0xBEEF);
    result = Flash_Write(0x1000, 0xBEEF);
    LONGS_EQUAL(0, result);
    MockIO_Verify();
}

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}