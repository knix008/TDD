/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include "Branch.h"

#include <string>
#include <vector>

#include "boost/date_time/gregorian/gregorian_types.hpp"

class Holding
{
public:
   Holding();
   explicit Holding(const std::string& barcode);
   Holding(const std::string& classification, unsigned short copyNumber);
   virtual ~Holding();

   static std::string ConstructBarcode(const std::string& classification, const int& copyNumber);

   bool operator==(const Holding& rhs) const;
   bool operator!=(const Holding& rhs) const;
   bool operator<(const Holding& rhs) const;

   Branch CurrentBranch() const;
   unsigned short CopyNumber() const;
   std::string Barcode() const;
   boost::gregorian::date LastCheckedOutOn() const;
   boost::gregorian::date DueDate() const;
   bool IsAvailable() const;
   std::string Classification() const;

   void Transfer(Branch&);
   void CheckOut(boost::gregorian::date);
   void CheckIn(boost::gregorian::date, const Branch&);

private:
   std::string mClassification;
   unsigned short mCopyNumber;
   Branch mBranch;
   boost::gregorian::date mLastCheckedOutOn;
};

typedef std::vector<Holding>::iterator HoldingIterator;
