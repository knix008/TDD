/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#ifndef AddressExtractor_h
#define AddressExtractor_h

#include <json/reader.h>
#include <json/value.h>
#include <string>
#include "Address.h"

class AddressExtractor {
public:
   Address addressFrom(const std::string& json) const;

private:
   Json::Value jsonAddressFrom(const std::string& json) const;
   void populate(Address& address, Json::Value& jsonAddress) const;
   Json::Value parse(const std::string& json) const;
   std::string getString(Json::Value& result, const std::string& name) const;
};

#endif
