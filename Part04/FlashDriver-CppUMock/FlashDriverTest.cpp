#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>
#include "IO.h"
#include "FlashDriver.h"

TEST_GROUP(FlashDriver){
    ioAddress address;
    ioData data;
    int result;
    void setup(){
        address = 0xfeed;
        data = 0x1dea;
    }
    void teardown() {
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(FlashDriver, WriteSuccessImmediately)
{
    mock().expectOneCall("IO_Write").withParameter("addr", CommandRegister).withParameter("value", ProgramCommand);
    mock().expectOneCall("IO_Write").withParameter("addr", (int)address).withParameter("value", data);
    mock().expectOneCall("IO_Read").withParameter("addr", StatusRegister).andReturnValue((int)ReadyBit);
    mock().expectOneCall("IO_Read").withParameter("addr", (int)address).andReturnValue((int)data);
    int result = Flash_Write(address, data);
    LONGS_EQUAL(FLASH_SUCCESS, result);
}

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}