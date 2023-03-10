#include "Soundex02.h"

string Soundex::encode(const string &word) const
{
    return zeroPad(head(word) + encodedDigits(word));
}

string Soundex::zeroPad(const string &word) const
{
    auto zerosNeeded = 4 - word.length();
    return word + string(zerosNeeded, '0');
}

string Soundex::head(const string &word) const
{
    return word.substr(0, 1);
}

string Soundex::encodedDigits(const string &word) const
{
    if (word.length() > 1)
        return "1";
    return "";
}