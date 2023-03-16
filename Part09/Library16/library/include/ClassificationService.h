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
#include <stdexcept>

#include "Book.h"

class ClassificationService
{
public:
    ClassificationService(void);
    ~ClassificationService(void);

    Book RetrieveDetails(const std::string& classification) const;
};

class ClassificationNotFoundException: public std::runtime_error {
public:
    ClassificationNotFoundException(const std::string& classification) 
        : std::runtime_error("classification not found")
        , mClassification(classification) {}

    std::string mClassification;
};
