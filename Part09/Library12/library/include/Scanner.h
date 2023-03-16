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

#include "HoldingService.h"
// TODO class HoldingService; need namespace wrappers
class DisplayListener;
class ScannerState;

class Scanner
{
public:
    const static std::string INVENTORY_CARD_NUMBER;
    const static std::string MSG_INVALID_BARCODE;

    Scanner(DisplayListener*, service::HoldingService*);
    virtual ~Scanner();

	void Scan(const std::string& barcode);
	void PressDone();

    void ShowMessage(const std::string& message);
    ScannerState* CurrentState();
    void SetCurrentState(ScannerState* state);

    std::string BranchId();
    void SetBranchId(const std::string&);
    std::string PatronId();
    void SetPatronId(const std::string&);

    service::HoldingService* HoldingService();

private:
    DisplayListener* mDisplay;
    std::string mBranchId;
    ScannerState* mCurrentState;
    std::string mPatronId;
    service::HoldingService* mHoldingService;
};
