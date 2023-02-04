#include <CppUTest/CommandLineTestRunner.h>
#include "IO.hpp"

TEST_GROUP(FlashDriver){
    void setup(){} void teardown(){}};

TEST(FlashDriver, NullTest)
{
   //FAIL_TEST("Start here...")
}

int main(int ac, char **av)
{
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}