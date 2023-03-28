#ifndef __WORK_H__
#define __WORK_H__

#include <functional>

class Work
{
public:
   static const int DefaultId{0};

   Work(int id = DefaultId)
       : id_{id}, executeFunction_{[] {}} {}

   Work(std::function<void()> executeFunction, int id = DefaultId)
       : id_{id}, executeFunction_{executeFunction}
   {
   }

   void execute()
   {
      executeFunction_();
   }

   int id() const
   {
      return id_;
   }

private:
   int id_;
   std::function<void()> executeFunction_;
};

#endif