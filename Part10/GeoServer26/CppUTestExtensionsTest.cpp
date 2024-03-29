#include "CppUTestExtensions.h"
#include "CppUTest/TestHarness.h"

TEST_GROUP(StringFrom_ForAVector){};

TEST(StringFrom_ForAVector, AnswersEmptyStringWhenVectorEmpty)
{
   std::vector<std::string> strings{};

   CHECK_EQUAL("", StringFrom(strings));
}

TEST(StringFrom_ForAVector, AnswersCommaSeparatedList)
{
   std::vector<std::string> strings{"alpha", "beta", "gamma"};

   CHECK_EQUAL("alpha,beta,gamma", StringFrom(strings));
}

struct TestItem
{
   TestItem(int number) : Number(number) {}
   int Number;
};

TEST(StringFrom_ForAVector, AcceptsTransformLambdaSoYouCanBuildYourOwnEasily)
{
   std::vector<TestItem> items{TestItem(1), TestItem(2), TestItem(3)};

   auto string = StringFrom<TestItem>(items,
                                      [](TestItem item)
                                      { return std::to_string(item.Number); });

   CHECK_EQUAL("1,2,3", string);
}