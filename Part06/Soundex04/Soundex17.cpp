#include "Soundex08.h"

static const size_t MaxCodeLength{4};

string Soundex::encode(const string &word) const
{
    return zeroPad(head(word) + encodedDigits(tail(word)));
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

string Soundex::encodedDigits(const std::string &word) const
{
    string encoding;
    for (auto letter : word)
    {
        if (isComplete(encoding))
            break;
        encoding += encodedDigit(letter);
    }

    return encoding;
}

bool Soundex::isComplete(const std::string &encoding) const
{
    return encoding.length() == MaxCodeLength - 1;
}

string Soundex::encodedDigit(char letter) const
{
    const unordered_map<char, string> encodings{
        {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"}, {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"}, {'s', "2"}, {'x', "2"}, {'z', "2"}, {'d', "3"}, {'t', "3"}, {'l', "4"}, {'m', "5"}, {'n', "5"}, {'r', "6"}};

    auto it = encodings.find(letter);
    return it == encodings.end() ? "" : it->second;
}