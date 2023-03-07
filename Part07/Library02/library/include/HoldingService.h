/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include "PatronService.h"
#include "BranchService.h"
#include "Catalog.h"
#include "HoldingBarcode.h"

#include "boost/date_time/gregorian/gregorian_types.hpp"

#include <vector>
#include <set>

class Book;
class Branch;
class Patron;

namespace service {
class HoldingService
{
public:
	HoldingService();
    virtual ~HoldingService();

    static void DeleteAll();

    virtual void AddAtBranch(const std::string& branchId, const std::string& barcode);
    virtual void CheckIn(const std::string& barCode, boost::gregorian::date, const std::string& branchId);
    virtual void CheckOut(const std::string& patronCardNumber, const std::string& barCode, boost::gregorian::date);
    void Transfer(Holding&, Branch&);
    void Transfer(const std::string& barCode, const std::string& branchId);

    unsigned int InventorySize() const;
    virtual bool ExistsWithBarcode(const std::string& barCode) const;
    virtual bool IsAvailable(const std::string& barCode) const;
    bool FindByBarCode(Holding&) const;
	void FindByClassification(const std::string& classification, std::set<Holding>& holdings) const;

private:
	HoldingService(const HoldingService&);
	HoldingService& operator=(const HoldingService&);

   Patron FindPatron(Holding&);
   bool IsLate(Holding&, boost::gregorian::date& checkinDate);
   void ApplyFine(Patron&, Holding&);
   unsigned int CalculateDaysPastDue(Holding& holding);

	PatronService mPatronService;
   BranchService mBranchService;
	Catalog mCatalog;
};
}
