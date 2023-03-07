/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include "gmock/gmock.h"

#include "Scanner.h"
#include "ScannerState.h"
#include "DisplayListener.h"
#include "Holding.h"

#include "boost/date_time/gregorian/gregorian_types.hpp"
#include <string>

class MockDisplayListener: public DisplayListener {
public:
   virtual ~MockDisplayListener() {}
    MOCK_METHOD1(ShowMessage, void(const std::string& text));
};

class MockHoldingService: public service::HoldingService
{
public:
    MOCK_METHOD3(CheckIn, void(const std::string& barCode, boost::gregorian::date, const std::string& branchId));
    MOCK_METHOD3(CheckOut, void(const std::string& patronCardNumber, const std::string& barCode, boost::gregorian::date));
    MOCK_CONST_METHOD1(ExistsWithBarcode, bool(const std::string& barCode));
    MOCK_CONST_METHOD1(IsAvailable, bool(const std::string& barCode));
    MOCK_METHOD2(AddAtBranch, void(const std::string& branchId, const std::string& barcode));
};

// TODO holding service should be an override mock, not required in ctor

// TODO not sure this is a good idea
class TestScanner
{
public:
    Scanner* scanner;
    MockDisplayListener* display;
    MockHoldingService* holdingService;

    TestScanner() {
        display = new MockDisplayListener;
        holdingService = new MockHoldingService;
        scanner = new Scanner(display, holdingService);
    }

    virtual ~TestScanner() {
        delete scanner;
        delete holdingService;
        delete display;
    }

    MockHoldingService* HoldingService()
    {
         return dynamic_cast<MockHoldingService*>(scanner->HoldingService());
    }
};
