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
#include <ctype.h>

using std::string;

class BarcodeUtil
{
public:
    BarcodeUtil(void) {}
    ~BarcodeUtil(void) {}

    static bool IsBranchId(const string& barcode)
    {
        return toupper(barcode[0]) == 'B';
    }

    static bool IsPatronId(const string& barcode)
    {
        return toupper(barcode[0]) == 'P';
    }

    static bool IsHoldingBarcode(const string& barcode)
    {
        return barcode.find(":") != string::npos;
    }
};
