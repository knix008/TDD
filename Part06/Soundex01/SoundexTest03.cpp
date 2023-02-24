#include "gmock/gmock.h"

class Soundex
{
};

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    Soundex soundex;

    auto encoded = soundex.encode("A");
}

int main(int argc, char **argv)
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}