#ifndef __STREAMUTIL_H__
#define __STREAMUTIL_H__

#include <ios>
#include <istream>

namespace StreamUtil {
   std::streamsize size(std::istream& stream);
}

#endif
