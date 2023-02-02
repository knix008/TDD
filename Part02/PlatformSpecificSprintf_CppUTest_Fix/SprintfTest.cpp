#include <CppUTest/CommandLineTestRunner.h>
#include <stdint.h>
#include "Sprintf.h"

TEST_GROUP(PlatformSpecificSprintf)
{
    void setup(){} void teardown(){}
};

TEST_GROUP(SimpleString)
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

TEST(SimpleString, PlatformSpecificSprintf_doesNotFit)
{
   char buf[10];
   
   int count = PlatformSpecificSprintf(buf, sizeof buf, "%s", "12345678901");
   STRCMP_EQUAL("123456789", buf);
   LONGS_EQUAL(11, count);
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}