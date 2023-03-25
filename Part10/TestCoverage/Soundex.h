#ifndef __SOUNDEX_H__
#define __SOUNDEX_H__
#include <string>

class Soundex
{
public:
   std::string encode(const std::string &word) const
   {
      std::string code("");
      code += head(word) + encodeTail(word);
      return zeroPad(code);
   }
   
   char head(const std::string &word) const
   {
      return word[0];
   }

   std::string encodeTail(const std::string &word) const
   {
      if (word[1] == 0)
         return "";
      return "1";
   }

   std::string zeroPad(const std::string &code) const
   {
      if (code[1] != 0)
         return code + "00";
      return code + "000";
   }
};
#endif