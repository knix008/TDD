#include "Portfolio.h"

using namespace std;

Portfolio::Portfolio() : shareCount_{0}
{
}

bool Portfolio::IsEmpty() const
{
   return 0 == shareCount_;
}

void Portfolio::Purchase(const string &symbol, unsigned int shareCount)
{
   if (0 == shareCount)
      throw InvalidPurchaseException();
   shareCount_ = shareCount;
}

unsigned int Portfolio::ShareCount(const string &symbol) const
{
   return shareCount_;
}
