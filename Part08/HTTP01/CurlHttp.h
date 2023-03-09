/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef CurlHttp_h
#define CurlHttp_h

#include <curl/curl.h>
#include <string>

#include "Http.h"

class CurlHttp: public Http {
public:
   CurlHttp();
   virtual ~CurlHttp();

   void initialize();
   virtual std::string get(const std::string& url) const;
   static std::string Response();
   static size_t writeCallback(const char* buf, size_t size, size_t nMemb, void*);

private:
   CURL* curl;

   static std::string response_;
};

#endif
