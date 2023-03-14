#ifndef __PORTFOLIO_H__
#define __PORTFOLIO_H__

#include <string>
#include <exception>
#include <unordered_map>
#include <vector>
#include "boost/date_time/gregorian/gregorian_types.hpp"

class ShareCountCannotBeZeroException : public std::exception
{
};

class InsufficientSharesException : public std::exception
{
};

struct PurchaseRecord
{
   PurchaseRecord(int shareCount, const boost::gregorian::date &date)
       : ShareCount(shareCount), Date(date)
   {
   }
   int ShareCount;
   boost::gregorian::date Date;
};

class Portfolio
{
public:
   bool IsEmpty() const;
   void Purchase(const std::string &symbol, unsigned int shareCount, const boost::gregorian::date &transactionDate);
   void Sell(const std::string &symbol, unsigned int shareCount, const boost::gregorian::date &transactionDate);
   unsigned int ShareCount(const std::string &symbol) const;
   std::vector<PurchaseRecord> Purchases(const std::string &symbol) const;

private:
   void Transact(const std::string &symbol, int shareChange, const boost::gregorian::date &date);
   void UpdateShareCount(const std::string &symbol, int shareChange);
   void AddPurchaseRecord(int, const boost::gregorian::date &);
   void ThrowIfShareCountIsZero(int shareChange) const;
   std::unordered_map<std::string, unsigned int> holdings_;
   std::vector<PurchaseRecord> purchases_;
};

#endif
