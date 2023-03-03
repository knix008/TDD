#ifndef __RETWEETCOLLECTION_H__
#define __RETWEETCOLLECTION_H__

#include "Tweet.h"

class RetweetCollection {
public:
   RetweetCollection() 
      : size_(0) {
   }

   bool isEmpty() const {
      return 0 == size();
   }

   unsigned int size() const {
      return size_;
   }

   void add(const Tweet& tweet) {
      size_ = 1;
   }

private:
   unsigned int size_;
};
#endif
