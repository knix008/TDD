#ifndef __TWEET_H__
#define __TWEET_H__

#include <string>
#include <stdexcept>
#include <iostream>

class InvalidUserException : public std::invalid_argument
{
public:
   InvalidUserException(const std::string &user)
       : std::invalid_argument(user) {}
};

class Tweet
{
public:
   static const std::string NULL_USER;
   Tweet(const std::string &message = "",
         const std::string &user = Tweet::NULL_USER)
       : message_(message), user_(user)
   {
      if (!isValid(user_))
         throw InvalidUserException(user_);
   }

   bool isValid(const std::string &user) const
   {
      return '@' == user[0];
   }

   std::string user() const
   {
      return user_;
   }

   bool operator==(const Tweet &rhs) const
   {
      return message_ == rhs.message_ &&
             user_ == rhs.user_;
   }

   bool operator!=(const Tweet &rhs) const
   {
      return !(*this == rhs);
   }

   bool operator<(const Tweet &rhs) const
   {
      if (user_ == rhs.user_)
         return message_ < rhs.message_;
      return user_ < rhs.user_;
   }

private:
   std::string message_;
   std::string user_;
};

#endif
