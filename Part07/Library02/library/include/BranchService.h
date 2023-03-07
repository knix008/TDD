/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include <exception>

#include "BranchAccess.h"

class DuplicateBranchNameException: public std::exception {
};

class BranchService
{
public:
    BranchService(void);
    virtual ~BranchService(void);

    static void DeleteAll();

    void Add(Branch& branch);
    std::string Add(const std::string& name, const std::string& address);
    short BranchCount() const;
    bool Find(Branch& branch) const;
    bool ExistsWithName(const std::string& name) const;

private:
    BranchAccess mBranchAccess;
};
