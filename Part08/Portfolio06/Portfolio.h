#ifndef __PORTFOLIO_H__
#define __PORTFOLIO_H__

#include <string>
#include <exception>
#include <unordered_map>
#include <vector>
#include "boost/date_time/gregorian/gregorian_types.hpp"

class InvalidPurchaseException : public std::exception
{
};

class InvalidSellException : public std::exception
{
};

struct PurchaseRecord
{
   PurchaseRecord(unsigned int shareCount, const boost::gregorian::date &date)
       : ShareCount(shareCount), Date(date)
   {
   }
   unsigned int ShareCount;
   boost::gregorian::date Date;
};

class Portfolio
{
public:
   static const boost::gregorian::date FIXED_PURCHASE_DATE;
   bool IsEmpty() const;
   void Purchase(const std::string &symbol, unsigned int shareCount,
       const boost::gregorian::date &transactionDate = Portfolio::FIXED_PURCHASE_DATE);
   void Sell(const std::string &symbol, unsigned int shareCount);
   unsigned int ShareCount(const std::string &symbol) const;
   std::vector<PurchaseRecord> Purchases(const std::string &symbol) const;

private:
   std::unordered_map<std::string, unsigned int> holdings_;
   std::vector<PurchaseRecord> purchases_;
};

#endif
