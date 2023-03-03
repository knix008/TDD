#ifndef __RETWEETCOLLECTION_H__
#define __RETWEETCOLLECTION_H__

#include "Tweet.h"

class RetweetCollection
{
public:
   RetweetCollection() : empty_(true)
   {
   }

   bool isEmpty() const
   {
      return empty_;
   }

   void add(const Tweet &tweet)
   {
      empty_ = false;
   }

   unsigned int size() const
   {
      return 0;
   }

private:
   bool empty_;
};
#endif
