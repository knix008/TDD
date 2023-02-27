#include "Soundex01.h"

string Soundex::encode(const string &word) const
{
    return zeroPad(word);
}

string Soundex::zeroPad(const string &word) const
{
    return word + "000";
}
