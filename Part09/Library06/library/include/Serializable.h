/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include <string>
#include <iostream>

class Serializable
{
public:
    virtual void Load(std::istream& input)=0;
    virtual void WriteOn(std::ostream& output)=0;
    virtual std::string Id() const=0;
    virtual Serializable* Clone() const=0;
};
