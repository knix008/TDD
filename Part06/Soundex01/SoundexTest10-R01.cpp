#include <string>
#include "gmock/gmock.h"
using ::testing::Eq;

class Soundex
{
public:
    std::string encode(const std::string &word) const
    {
        return zeroPad(word);
    }

private:
    std::string zeroPad(const std::string &word) const
    {
        return word + "000";
    }
};

class SoundexEncoding : public testing::Test
{
public:
    Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
    /* NOTICE : “Soundex soundex” is moved to SoundexEncoding Test Class */
    auto encoded = soundex.encode("A");
    ASSERT_THAT(encoded, Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
    /* NOTICE : “Soundex soundex” is moved to SoundexEncoding Test Class */
    auto encoded = soundex.encode("I");
    ASSERT_THAT(encoded, Eq("I000"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}