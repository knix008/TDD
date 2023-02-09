#include <CppUTest/CommandLineTestRunner.h>
#include "FormatOutput.h"
#include "Util.h"

TEST_GROUP(FormatOutputSpy)
{
    void setup()
    {
        UT_PTR_SET(FormatOutput, FormatOutputSpy);
    }

    void teardown()
    {
        FormatOutputSpy_Destroy();
    }
};

TEST(FormatOutputSpy, HelloWorld)
{
    FormatOutputSpy_Create(20);
    FormatOutput("Hello, World\n");
    STRCMP_EQUAL("Hello, World\n", FormatOutputSpy_GetOutput());
}

int main(int ac, char **av)
{
    int result = CommandLineTestRunner::RunAllTests(ac, av);
    return result;
}