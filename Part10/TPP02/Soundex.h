#ifndef __SOUNDEX_H__
#define __SOUNDEX_H__
#include <string>

class Soundex
{
public:
   std::string encode(const std::string &word) const
   {
      return "A000";
   }
};
#endif