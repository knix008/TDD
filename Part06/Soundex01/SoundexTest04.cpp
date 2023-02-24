#include <string>
#include "gmock/gmock.h"

class Soundex
{
public:
    std::string encode(const std::string &word) const
    {
        return "";
    }
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