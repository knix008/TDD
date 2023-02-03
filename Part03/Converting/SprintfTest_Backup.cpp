#include <CppUTest/CommandLineTestRunner.h>
#include <stdint.h>
#include "Sprintf.h"

TEST_GROUP(PlatformSpecificSprintf)
{
    void setup(){} void teardown(){}
};

TEST(PlatformSpecificSprintf, OutputFitsInBuffer)
{
   char buf[10];

   int count = PlatformSpecificSprintf(buf, sizeof buf, "%s", "12345");
   STRCMP_EQUAL("12345", buf);
   LONGS_EQUAL(5, count);
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}