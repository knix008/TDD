#ifndef __PURCHASERECORD_H__
#define __PURCHASERECORD_H__

#include "boost/date_time/gregorian/gregorian_types.hpp"

struct PurchaseRecord
{
   PurchaseRecord(int shareCount, const boost::gregorian::date &date)
       : ShareCount(shareCount), Date(date)
   {
   }
   int ShareCount;
   boost::gregorian::date Date;
};

#endif
