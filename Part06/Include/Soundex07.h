#ifndef __SOUNDEX_H__
#define __SOUNDEX_H__
#include <string>
#include <unordered_map>
using namespace std;

class Soundex
{
public:
    string encode(const string &word) const;

private:
    string zeroPad(const string &word) const;
    string head(const string& word) const;
    string tail(const string &word) const;
    string encodedDigits(const string& word) const;
    string encodedDigit(char letter) const;
    bool isComplete(const std::string &encoding) const;
};

#endif