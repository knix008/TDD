/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include "PatronAccess.h"
#include "CreditVerifier.h"

#include <vector>

class AlwaysTrueCreditVerifier: public CreditVerifier
{
public:
    virtual bool Verify(const std::string& cardNumber)
    {
        return true;
    }
};

class Patron;

class PatronService
{
public:
    PatronService(
        CreditVerifier* verifier=new AlwaysTrueCreditVerifier());
    virtual ~PatronService(void);

    void Add(const std::string& name, int id, const std::string& cardNumber="");
    void Add(const Patron& patron);
    bool Find(Patron& patron) const;
    short PatronCount() const;
    void Update(const Patron& patron);
    std::vector<Patron> GetAll() const; // bad!

    static void DeleteAll();
    void SetCreditVerifier(CreditVerifier* verifier);
private:
    CreditVerifier* mCreditVerifier;
    PatronAccess mPatronAccess;
};
