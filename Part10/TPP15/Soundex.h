#ifndef __SOUNDEX_H__
#define __SOUNDEX_H__
#include <string>

class Soundex
{
public:
   Soundex()
   {
      initializeCodeMap();
   }

   void initializeCodeMap()
   {
      codes_['b'] = codes_['f'] = codes_['p'] = codes_['v'] = "1";
      codes_['c'] = codes_['g'] = codes_['j'] = codes_['k'] =
          codes_['q'] = codes_['s'] = codes_['x'] = codes_['z'] = "2";
      codes_['d'] = codes_['t'] = "3";
      codes_['l'] = "4";
      codes_['m'] = codes_['n'] = "5";
      codes_['r'] = "6";
   }

   std::string encode(const std::string &word) const
   {
      std::string code(1, head(word));
      encode(tail(word), code, head(word));
      return zeroPad(code);
   }

   void encode(const std::string &word, std::string &code, char H) const
   {
      if (word.empty() || isFull(code))
         return;
      std::string digit = codeFor(head(word));
      if (digit != codeFor(H))
         code += codeFor(head(word));
      encode(tail(word), code, head(word));
   }

   bool isFull(std::string &code) const
   {
      return code.length() == MaxCodeLength;
   }

   char head(const std::string &word) const
   {
      return word[0];
   }

   std::string tail(const std::string &word) const
   {
      return word.substr(1);
   }

   std::string codeFor(char c) const
   {
      return codes_[static_cast<size_t>(c)];
   }

   const static size_t MaxCodeLength{4};

   std::string zeroPad(const std::string &code) const
   {
      return code + std::string(MaxCodeLength - code.length(), '0');
   }

private:
   std::string codes_[128];
};

#endif