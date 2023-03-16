/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include <istream>
#include <string>

class StreamLineReader
{
public:
    StreamLineReader(std::istream* input);
    ~StreamLineReader(void);
    void Read(std::string& stringMember);
    void Read(unsigned int& intMember);

private:
    std::istream* mInput;
};
