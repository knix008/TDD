#include <vector>
#include <string>
#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

string convert(unsigned int arabic)
{
   const auto arabicToRomanConversions = {
       make_pair(1000u, "M"),
       make_pair(900u, "CM"),
       make_pair(500u, "D"),
       make_pair(400u, "CD"),
       make_pair(100u, "C"),
       make_pair(90u, "XC"),
       make_pair(50u, "L"),
       make_pair(40u, "XL"),
       make_pair(10u, "X"),
       make_pair(9u, "IX"),
       make_pair(5u, "V"),
       make_pair(4u, "IV"),
       make_pair(1u, "I")};

   string roman{""};
   for (auto arabicToRoman : arabicToRomanConversions)
      while (arabic >= arabicToRoman.first)
      {
         roman += arabicToRoman.second;
         arabic -= arabicToRoman.first;
      }
   return roman;
}

TEST(RomanConverter, CanConvertPositiveDigits)
{
   EXPECT_THAT(convert(1), Eq("I"));
   EXPECT_THAT(convert(2), Eq("II"));
   EXPECT_THAT(convert(3), Eq("III"));
   EXPECT_THAT(convert(4), Eq("IV"));
   EXPECT_THAT(convert(5), Eq("V"));
   EXPECT_THAT(convert(10), Eq("X"));
   EXPECT_THAT(convert(11), Eq("XI"));
   EXPECT_THAT(convert(12), Eq("XII"));
   EXPECT_THAT(convert(13), Eq("XIII"));
   EXPECT_THAT(convert(20), Eq("XX"));
   EXPECT_THAT(convert(50), Eq("L"));
   EXPECT_THAT(convert(80), Eq("LXXX"));
   EXPECT_THAT(convert(100), Eq("C"));
   EXPECT_THAT(convert(288), Eq("CCLXXXVIII"));
   EXPECT_THAT(convert(2999), Eq("MMCMXCIX"));
   EXPECT_THAT(convert(3447), Eq("MMMCDXLVII"));
   EXPECT_THAT(convert(1513), Eq("MDXIII"));
}