#include <CppUTest/CommandLineTestRunner.h>
#include "MockIO.h"
#include "FlashDriver.hpp"

TEST_GROUP(FlashDriver){
    void setup(){} void teardown(){}};

TEST(FlashDriver, ReadyImmediately)
{
   int result = 0;
   MockIO_Expect_Write(0, 0x40);
   MockIO_Expect_Write(0x1000, 0xBEEF);
   MockIO_Expect_ReadThenReturn(0, 1 << 7);
   MockIO_Expect_ReadThenReturn(0x1000, 0xBEEF);
   result = Flash_Write(0x1000, 0xBEEF);
   LONGS_EQUAL(0, result);
   MockIO_Verify_Complete();
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}