#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

/*
string convert(unsigned int arabic)
{
   return "I";
}
*/

/*
TEST(RomanConverter, CanConvertPositiveDigits)
{
   EXPECT_THAT(convert(1), Eq("I"));
}
*/

string convert(unsigned int arabic)
{
   if (arabic == 2)
      return "II";
   return "I";
}

TEST(RomanConverter, CanConvertPositiveDigits)
{
   EXPECT_THAT(convert(1), Eq("I"));
   EXPECT_THAT(convert(2), Eq("II"));
}