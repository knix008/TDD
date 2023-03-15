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
#include <set>

class Holding;

class Catalog
{
public:
	Catalog();
	virtual ~Catalog();

    static void DeleteAll();

	unsigned int Size() const;
	void Add(Holding& holding);
	void Update(Holding& holding);
	void FindByClassification(const std::string&, std::set<Holding>& holdings) const;
    bool FindByBarCode(Holding&) const;
    static std::vector<Holding>* Holdings();

private:
    Catalog(const Catalog&);

    static std::vector<Holding>* mHoldings;
};
