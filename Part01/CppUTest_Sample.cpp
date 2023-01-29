#include <CppUTest/CommandLineTestRunner.h>
#include <stdint.h>

int main(int ac, char** av){
   int result = CommandLineTestRunner::RunAllTests(ac, av);
   return result;
}

TEST_GROUP(FirstTestGroup)
{
   void setup()
   {
   }

   void teardown()
   {
   }
};

TEST(FirstTestGroup, FirstTest)
{
  CHECK_TRUE(1);
}