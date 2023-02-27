#include "Soundex05.h"

static const size_t MaxCodeLength{4};

string Soundex::encode(const string &word) const
{
    return zeroPad(head(word) + encodedDigits(word));
}

string Soundex::zeroPad(const string &word) const
{
    auto zerosNeeded = MaxCodeLength - word.length();
    return word + string(zerosNeeded, '0');
}

string Soundex::head(const string &word) const
{
    return word.substr(0, 1);
}

string Soundex::encodedDigits(const string &word) const
{
    if (word.length() > 1)
        return encodedDigit(word[1]);
    return "";
}

string Soundex::encodedDigit(char letter) const
{
    const std::unordered_map<char, string> encodings{
        {'b', "1"},
        {'c', "2"},
        {'d', "3"}};
    return encodings.find(letter)->second;
}