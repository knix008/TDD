#ifndef __TESTTIME_H__
#define __TESTTIME_H__

#include <string>
#include <chrono>

struct TestTimer
{
   TestTimer();
   TestTimer(const std::string &text);
   ~TestTimer();

   std::chrono::time_point<std::chrono::system_clock> Start;
   std::chrono::time_point<std::chrono::system_clock> Stop;
   std::chrono::microseconds Elapsed;
   std::string Text;
};

#endif
