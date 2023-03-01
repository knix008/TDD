#include "Soundex11.h"

static const size_t MaxCodeLength{4};

string Soundex::encode(const std::string &word) const
{
    return zeroPad(upperFront(head(word)) + encodedDigits(tail(word)));
}

string Soundex::upperFront(const std::string &string) const
{
    return std::string(1, toupper(static_cast<unsigned char>(string.front())));
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

string Soundex::tail(const string &word) const
{
    return word.substr(1);
}

bool Soundex::isComplete(const string &encoding) const
{
    return encoding.length() == MaxCodeLength - 1;
}

const string NotADigit{"*"};

string Soundex::encodedDigits(const string &word) const
{
    string encoding;
    for (auto letter : word)
    {
        if (isComplete(encoding))
            break;
        auto digit = encodedDigit(letter);
        if (digit != NotADigit && digit != lastDigit(encoding))
            encoding += digit;
    }
    return encoding;
}

string Soundex::lastDigit(const string &encoding) const
{
    if (encoding.empty())
        return NotADigit;
    return string(1, encoding.back());
}

string Soundex::encodedDigit(char letter) const
{
    const unordered_map<char, string> encodings{
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"}, {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"}};

    auto it = encodings.find(lower(letter));
    return it == encodings.end() ? NotADigit : it->second;
}

char Soundex::lower(char c) const
{
    return tolower(static_cast<unsigned char>(c));
}