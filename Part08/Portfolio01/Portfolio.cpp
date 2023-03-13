#include "Portfolio.h"

using namespace std;

Portfolio::Portfolio() : isEmpty_{true}, shareCount_{0u}
{
}

bool Portfolio::IsEmpty() const
{
   return isEmpty_;
}

void Portfolio::Purchase(const string &symbol, unsigned int shareCount)
{
   isEmpty_ = false;
   shareCount_ = shareCount;
}

unsigned int Portfolio::ShareCount(const string &symbol) const
{
   return shareCount_;
}
