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

class Patron;

class PatronAccess
{
public:
	PatronAccess();
	virtual ~PatronAccess();

	void Save(const Patron&);
	bool Find(Patron&) const;
	Patron& FindByName(const std::string&) const;
	int Size() const;
	void Update(const Patron&);
	std::vector<Patron> GetAll() const;

	static void DeleteAll();

private:
	PatronAccess& operator=(const PatronAccess&);
	PatronAccess(const PatronAccess&);
	
   std::vector<Patron>::iterator Locate(const Patron&) const;
	std::vector<Patron>::iterator Begin() const;
	std::vector<Patron>::iterator End() const;

	static std::vector<Patron>* mPatrons;
	static std::vector<Patron>* Patrons();
};
