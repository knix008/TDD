#ifndef __STRINGUTIL_H__
#define __STRINGUTIL_H__

#include <string>

namespace stringutil
{
   std::string head(const std::string &word);
   std::string tail(const std::string &word);
   std::string zeroPad(const std::string &text, unsigned int toLength);
   std::string upperFront(const std::string &string);
}

#endif
