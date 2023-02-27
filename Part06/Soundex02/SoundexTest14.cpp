#include "gmock/gmock.h"
#include "Soundex01.h"

using namespace testing;

class SoundexEncoding : public Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
    EXPECT_THAT(soundex.encode("Ab"), Eq("A100"));
    EXPECT_THAT(soundex.encode("Ac"), Eq("A200"));
    EXPECT_THAT(soundex.encode("Ad"), Eq("A300"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}