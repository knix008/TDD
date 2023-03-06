#ifndef __RETWEETCOLLECTION_H__
#define __RETWEETCOLLECTION_H__

#include <set>
#include "Tweet.h"

class RetweetCollection
{
public:
   RetweetCollection()
       : size_(0)
   {
   }

   bool isEmpty() const
   {
      return 0 == size();
   }

   void add(const Tweet &tweet)
   {
      tweets.insert(tweet);
      ++size_;
   }

   unsigned int size() const
   {
      return tweets.size();
   }

   void remove(const Tweet &tweet)
   {
      --size_;
   }

private:
   unsigned int size_;
   std::set<Tweet> tweets;
};
#endif
