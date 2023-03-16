/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include "Serializable.h"

#include <string>
#include <vector>
#include <ostream>
#include <istream>
#include <iostream>

class Branch: public Serializable
{
public:
    Branch();
    Branch(const std::string& id, const std::string& name="");
	virtual ~Branch();

    static Branch CHECKED_OUT;

    virtual void WriteOn(std::ostream& output);
    virtual void Load(std::istream& input);
    virtual Branch* Clone() const;
    std::string Id() const;
    std::string Name() const;
	void SetAddress(const std::string&);
	std::string Address() const;
    bool operator==(const Branch& other) const;
	bool operator!=(const Branch& other) const;

private:
    std::string mId;
    std::string mName;
	std::string mAddress;
    friend std::istream& operator>>(std::istream &, Branch&);
    friend std::ostream& operator<<(std::ostream &, Branch&);
};

typedef std::vector<Branch>::iterator BranchIterator;

std::istream& operator >>(std::istream&, Branch&);
std::ostream& operator <<(std::ostream&, Branch&);
