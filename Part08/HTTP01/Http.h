#ifndef __HTTP_H__
#define __HTTP_H__

#include <string>

class Http
{
public:
   virtual ~Http() {}
   virtual void initialize() = 0;
   virtual std::string get(const std::string &url) const = 0;
};

#endif
