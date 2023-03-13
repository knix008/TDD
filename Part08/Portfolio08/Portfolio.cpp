#include "Portfolio.h"

using namespace std;
using namespace boost::gregorian;

bool Portfolio::IsEmpty() const
{
   return 0 == holdings_.size();
}

void Portfolio::Purchase(const string &symbol, unsigned int shareCount, 
   const date &transactionDate)
{
   if (0 == shareCount)
      throw InvalidPurchaseException();
   holdings_[symbol] = shareCount + ShareCount(symbol);
   purchases_.push_back(PurchaseRecord(shareCount, transactionDate));
}

void Portfolio::Sell(const string &symbol, unsigned int shareCount, 
   const date &transactionDate)
{
   if (shareCount > ShareCount(symbol))
      throw InvalidSellException();
   holdings_[symbol] = ShareCount(symbol) - shareCount;
   purchases_.push_back(PurchaseRecord(-shareCount, transactionDate));
}

unsigned int Portfolio::ShareCount(const string &symbol) const
{
   auto it = holdings_.find(symbol);
   if (it == holdings_.end())
      return 0;
   return it->second;
}

vector<PurchaseRecord> Portfolio::Purchases(const string &symbol) const
{
   return purchases_;
}
