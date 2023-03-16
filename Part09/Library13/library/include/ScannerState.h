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
#include "Scanner.h"

class ScannerState
{
public:
    ScannerState(Scanner* scanner)
        : mScanner(scanner)
    {
    }

    virtual ~ScannerState()
    {
    }

    virtual void ScanHolding(const std::string& barcode)=0;
    virtual void ScanBranchCard(const std::string& barcode)=0;
    virtual void ScanInventoryCard(const std::string& barcode)=0;
    virtual void ScanPatronCard(const std::string& barcode)=0;
    virtual void PressDone()=0;

protected:
    template <typename T> void SetState();

    void ShowMessage(const std::string& message);
    std::string BranchId() const;
    void SetBranchId(const std::string& id);
    std::string PatronId() const;
    void SetPatronId(const std::string& id);
    service::HoldingService* HoldingService() const;

private:
    Scanner* mScanner;
};

template <typename T>
void ScannerState::SetState()
{
    mScanner->SetCurrentState(new T(mScanner));
}
