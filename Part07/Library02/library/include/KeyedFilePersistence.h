/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include <string>
#include <memory>

#include "Persistence.h"
#include "Serializable.h"

template <class T>
class KeyedFilePersistence: public Persistence<T>
{
public:
    KeyedFilePersistence(const std::string& table) 
        : Persistence<T>(table) 
    {
    }

    virtual ~KeyedFilePersistence(void) 
    {
    }

    unsigned int Size() const 
    { 
        return 0; 
    }

    virtual void Clear()
    {
    }

    void Add(T& object) 
    { 
    }

    std::auto_ptr<T> Get(const std::string& id) const
    {
        return std::auto_ptr<T>(NULL);
    }

    virtual bool Matches(MatcherFunction matches, const std::string& name) const
    {
        return false;
    }

    virtual void FindAllMatching(MatcherFunction matches, const std::string& name, std::vector<Serializable*>& matchesToPopulate) const
    {
    }

private:
    std::map<std::string,Serializable*> mData;
};
