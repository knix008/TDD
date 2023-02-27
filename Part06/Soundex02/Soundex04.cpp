#include "Soundex01.h"

string Soundex::encode(const string &word) const
{
    auto encoded = word.substr(0, 1);
    if (word.length() > 1)
        encoded += "1";
    return zeroPad(encoded);
}

string Soundex::zeroPad(const string &word) const
{
    auto zerosNeeded = 4 - word.length();
    return word + string(zerosNeeded, '0');
}