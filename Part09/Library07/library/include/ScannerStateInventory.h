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

#include "ScannerState.h"

class Scanner;

class ScannerStateInventory: public ScannerState
{
public:
    ScannerStateInventory(Scanner*);
    ~ScannerStateInventory(void);

    void ScanHolding(const std::string&);
    void ScanPatronCard(const std::string&);
    void ScanInventoryCard(const std::string&);
    void ScanBranchCard(const std::string&);
    void PressDone();

    static const std::string MSG_COMPLETE_INVENTORY;
    static const std::string MSG_BRANCH_CHANGED;
    static const std::string MSG_HOLDING_ADDED;
};
