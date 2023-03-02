#ifndef __SOUNDEX_H__
#define __SOUNDEX_H__
#include <string>
#include <unordered_map>
using namespace std;

class Soundex
{
public:
    string encode(const string &word) const;
    string encodedDigit(char letter) const;

private:
    string zeroPad(const string &word) const;
    string head(const string& word) const;
    string tail(const string &word) const;
    string lastDigit(const string &encoding) const;
    string encodedDigits(const string& word) const;
    void encodeHead(string &encoding, const string &word) const;
    void encodeTail(string &encoding, const string &word) const;
    void encodeLetter(string &encoding, char letter, char lastLetter) const;
    bool isVowel(char letter) const;
    bool isComplete(const string &encoding) const;
    string upperFront(const string &string) const;
    char lower(char c) const;
};

#endif