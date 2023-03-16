/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include "gtest/gtest.h"

#include "KeyedFilePersistence.h"
#include "KeyedMemoryPersistence.h"
#include "TestSerializable.h"

using namespace std;

typedef Persistence<TestSerializable>* (*PersistenceFactoryFunction)();

class PersistenceTest: public ::testing::TestWithParam<PersistenceFactoryFunction> {
public:
    Persistence<TestSerializable>* persister;

    TestSerializable* objectWithId1;
    TestSerializable* objectWithId2;

    void SetUp() override 
    {
        persister = (*InjectedFactoryFunction())();
        persister->Clear();
        objectWithId1 = new TestSerializable("one", "1");
        objectWithId2 = new TestSerializable("two", "2");
    }

    PersistenceFactoryFunction InjectedFactoryFunction() 
    {
        return GetParam();
    }

    void TearDown() override
    {
        persister->Clear();
        delete objectWithId2;
        delete objectWithId1;
        delete persister;
    }

};
