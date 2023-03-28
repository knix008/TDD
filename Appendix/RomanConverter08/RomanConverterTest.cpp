#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

string convert(unsigned int arabic)
{
   string roman{""};
   while (arabic >= 10)
   {
      roman += "X";
      arabic -= 10;
   }
   while (arabic >= 1)
   {
      roman += "I";
      arabic -= 1;
   }
   return roman;
}

TEST(RomanConverter, CanConvertPositiveDigits)
{
   EXPECT_THAT(convert(1), Eq("I"));
   EXPECT_THAT(convert(2), Eq("II"));
   EXPECT_THAT(convert(3), Eq("III"));
   EXPECT_THAT(convert(10), Eq("X"));
   EXPECT_THAT(convert(11), Eq("XI"));
   EXPECT_THAT(convert(12), Eq("XII"));
   EXPECT_THAT(convert(13), Eq("XIII"));
   EXPECT_THAT(convert(20), Eq("XX"));
}