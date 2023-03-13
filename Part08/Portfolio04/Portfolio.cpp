#include "Portfolio.h"

using namespace std;
using namespace std;
using namespace boost::gregorian;

const date Portfolio::FIXED_PURCHASE_DATE(date(2014, Jan, 1));

bool Portfolio::IsEmpty() const
{
   return 0 == holdings_.size();
}

void Portfolio::Purchase(const string &symbol, unsigned int shareCount)
{
   if (0 == shareCount)
      throw InvalidPurchaseException();
   holdings_[symbol] = shareCount + ShareCount(symbol);
   purchases_.push_back(PurchaseRecord(shareCount, FIXED_PURCHASE_DATE));
}

void Portfolio::Sell(const string &symbol, unsigned int shareCount)
{
   if (shareCount > ShareCount(symbol))
      throw InvalidSellException();
   holdings_[symbol] = ShareCount(symbol) - shareCount;
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
