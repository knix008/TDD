#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include <string>
#include <deque>
#include <thread>
#include <memory>
#include <atomic>
#include "Work.h"

class ThreadPool
{
public:
   virtual ~ThreadPool()
   {
      done_ = true;
      if (workThread_)
         workThread_->join();
   }

   void start()
   {
      workThread_ = std::make_shared<std::thread>(&ThreadPool::worker, this);
   }

   bool hasWork()
   {
      return !workQueue_.empty();
   }

   void add(Work work)
   {
      workQueue_.push_front(work);
   }

   Work pullWork()
   {
      auto work = workQueue_.back();
      workQueue_.pop_back();
      return work;
   }

private:
   void worker()
   {
      while (!done_)
      {
         while (!done_ && !hasWork())
            ;
         if (done_)
            break;
         pullWork().execute();
      }
   }

   std::atomic<bool> done_{false};
   std::deque<Work> workQueue_;
   std::shared_ptr<std::thread> workThread_;
};

#endif
