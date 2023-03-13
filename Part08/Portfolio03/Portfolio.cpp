#include "Portfolio.h"

using namespace std;

bool Portfolio::IsEmpty() const
{
   return 0 == holdings_.size();
}

void Portfolio::Purchase(const string &symbol, unsigned int shareCount)
{
   if (0 == shareCount)
      throw InvalidPurchaseException();
   holdings_[symbol] = shareCount + ShareCount(symbol);
}

void Portfolio::Sell(const std::string &symbol, unsigned int shareCount)
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