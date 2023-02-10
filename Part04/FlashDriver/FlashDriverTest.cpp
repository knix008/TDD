#include <CppUTest/CommandLineTestRunner.h>
#include "IO.h"
#include "FlashDriver.h"

TEST_GROUP(FlashDriver)
{
    void setup()
    {
    }

    void teardown()
    {
    }
};

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}