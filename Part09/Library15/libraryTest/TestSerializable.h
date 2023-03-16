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
#include <fstream>

#include "Serializable.h"
#include "StreamLineReader.h"

class TestSerializable: public Serializable
{
public:
    TestSerializable() 
        : mName("")
        , mId("") 
    {
    }

    TestSerializable(const std::string& name, const std::string& id)
        : mName(name)
        , mId(id) 
    {
    }

    virtual ~TestSerializable() 
    {
    }

    std::string Name() 
    { 
        return mName; 
    }

    virtual std::string Id() const 
    { 
        return mId; 
    }
    
    virtual void Load(std::istream& input)
    {
        StreamLineReader reader(&input);
        reader.Read(mName);
        reader.Read(mId);
    }

    virtual TestSerializable* Clone() const
    {
        return new TestSerializable(mName, mId);
    }

    virtual void WriteOn(std::ostream& output)
    {
        output << mName << std::endl << mId << std::endl;
    }

    bool operator==(const TestSerializable& other) const
    {
        return 
            mId == other.mId && 
            mName == other.mName;
    }

private:
    std::string mName;
    std::string mId;
};
