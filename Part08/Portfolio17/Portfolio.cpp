#include "Portfolio.h"
#include "PurchaseRecord.h"

using namespace std;
using namespace boost::gregorian;

bool Portfolio::IsEmpty() const
{
   return 0 == holdings_.size();
}

void Portfolio::Purchase(const string &symbol, unsigned int shareCount, const date &transactionDate)
{
   Transact(symbol, shareCount, transactionDate);
}

void Portfolio::Sell(const string &symbol, unsigned int shareCount, const date &transactionDate)
{
   if (shareCount > ShareCount(symbol))
      throw InsufficientSharesException();
   Transact(symbol, -shareCount, transactionDate);
}

void Portfolio::Transact(const string &symbol, int shareChange, const date &transactionDate)
{
   ThrowIfShareCountIsZero(shareChange);
   UpdateShareCount(symbol, shareChange);
   AddPurchaseRecord(symbol, shareChange, transactionDate);
}

void Portfolio::ThrowIfShareCountIsZero(int shareChange) const
{
   if (0 == shareChange)
      throw ShareCountCannotBeZeroException();
}

void Portfolio::UpdateShareCount(const string &symbol, int shareChange)
{
   holdings_[symbol] = ShareCount(symbol) + shareChange;
}

void Portfolio::AddPurchaseRecord(const string &symbol, int shareChange, const date &date)
{
   if (!ContainsSymbol(symbol))
      InitializePurchaseRecords(symbol);
   Add(symbol, {shareChange, date});
}

void Portfolio::InitializePurchaseRecords(const string &symbol)
{
   purchaseRecords_[symbol] = vector<PurchaseRecord>();
}

void Portfolio::Add(const string &symbol, PurchaseRecord &&record)
{
   purchaseRecords_[symbol].push_back(record);
}

bool Portfolio::ContainsSymbol(const string &symbol) const
{
   return purchaseRecords_.find(symbol) != purchaseRecords_.end();
}

unsigned int Portfolio::ShareCount(const string &symbol) const
{
   return Find<unsigned int>(holdings_, symbol);
}

vector<PurchaseRecord> Portfolio::Purchases(const string &symbol) const
{
   return Find<vector<PurchaseRecord>>(purchaseRecords_, symbol);
}