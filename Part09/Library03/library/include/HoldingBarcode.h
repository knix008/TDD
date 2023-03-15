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
#include <sstream>

class HoldingBarcode
{
public:
    HoldingBarcode(const std::string& classification, unsigned int copyNumber) 
        : mClassification(classification)
        , mCopyNumber(copyNumber) 
    {
    }
    
    ~HoldingBarcode(void) 
    {
    }

    std::string AsString() const
    {
        std::stringstream buffer;
        buffer << mClassification << ":" << mCopyNumber;
        return buffer.str();
    }

    std::string Classification() const 
    { 
        return mClassification; 
    }
    
    unsigned int CopyNumber() const 
    { 
        return mCopyNumber; 
    }

private:
    std::string mClassification;
    unsigned int mCopyNumber;
};
