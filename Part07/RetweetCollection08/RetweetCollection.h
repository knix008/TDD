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
      return isEmpty() ? 0 : 1;
   }

   void remove(const Tweet &tweet)
   {
      empty_ = true;
   }

private:
   bool empty_;
};
#endif
