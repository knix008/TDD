/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include <list>
#include "boost/date_time/gregorian/gregorian_types.hpp"

class TimestampSource
{
public:
    TimestampSource(void);
    ~TimestampSource(void);

    static void ClearQueue();
    static void QueueNextTime(boost::gregorian::date&);
    static boost::gregorian::date Now();
    static bool IsExhausted();

private:
    static std::list<boost::gregorian::date> mStoredTimes;
};
