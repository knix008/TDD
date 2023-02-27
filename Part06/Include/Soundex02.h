#ifndef __SOUNDEX_H__
#define __SOUNDEX_H__
#include <string>
using namespace std;

class Soundex
{
public:
    string encode(const string &word) const;

private:
    string zeroPad(const string &word) const;
    string head(const string& word) const;
    string encodedDigits(const string& word) const;
};

#endif