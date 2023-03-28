#include "gmock/gmock.h"

using namespace ::testing;
using namespace std;

TEST(RomanConverter, CanConvertPositiveDigits)
{
   EXPECT_THAT(convert(1), Eq("I"));
}
