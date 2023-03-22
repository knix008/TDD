#include <condition_variable>
#include <mutex>
#include <chrono>

#include "ThreadPool.h"
#include "CppUTest/TestHarness.h"

using namespace std;

TEST_GROUP(AThreadPool) {
   mutex m;
   ThreadPool pool;
};

TEST(AThreadPool, HasNoWorkOnCreation)
{
   CHECK_FALSE(pool.hasWork());
}

TEST(AThreadPool, HasWorkAfterAdd)
{
   pool.add(Work{});
   CHECK_TRUE(pool.hasWork());
}

TEST(AThreadPool, AnswersWorkAddedOnPull)
{
   pool.add(Work{1});
   auto work = pool.pullWork();

   LONGS_EQUAL(1, work.id());
}

TEST(AThreadPool, PullsElementsInFIFOOrder)
{
   pool.add(Work{1});
   pool.add(Work{2});
   auto work = pool.pullWork();

   LONGS_EQUAL(1, work.id());
}

TEST(AThreadPool, HasNoWorkAfterLastElementRemoved)
{
   pool.add(Work{});
   pool.pullWork();
   CHECK_FALSE(pool.hasWork());
}

TEST(AThreadPool, HasWorkAfterWorkRemovedButWorkRemains)
{
   pool.add(Work{});
   pool.add(Work{});
   pool.pullWork();
   CHECK_TRUE(pool.hasWork());
}

TEST(AThreadPool, PullsWorkInAThread)
{
   pool.start();
   condition_variable wasExecuted;
   bool wasWorked{0};
   Work work{[&]
             {
                unique_lock<mutex> lock(m);
                wasWorked = true;
                wasExecuted.notify_all();
             }};

   pool.add(work);

   unique_lock<mutex> lock(m);
   CHECK_TRUE(wasExecuted.wait_for(lock, chrono::milliseconds(100),
                                   [&]
                                   { return wasWorked; }));
}