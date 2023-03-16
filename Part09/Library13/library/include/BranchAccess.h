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
#include <vector>
#include <fstream>
#include <memory>

#include "Persistence.h"

class Branch;

class BranchAccess
{
public:
    BranchAccess();
    explicit BranchAccess(std::shared_ptr<Persistence<Branch>> persister);
    virtual ~BranchAccess();

    static std::string DataFileName();

    bool Find(Branch&) const;
    int Size() const;
    bool ExistsWithName(const std::string& name) const;
    void Save(Branch&);
    void DeleteAll();

private:
    std::shared_ptr<Persistence<Branch>> mPersister;
};
