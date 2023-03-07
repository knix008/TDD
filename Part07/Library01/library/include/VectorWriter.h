/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include <vector>
#include <fstream>

template <typename T> // T should be a derivative of Serializable
class VectorWriter
{
public:
    VectorWriter(const std::string& filename)
        : mFilename(filename) {}

    virtual ~VectorWriter(void) {}

    virtual void WriteAll(std::vector<T>& objects)
    {
        // TODO: introduce raii-writer to ensure file close
        std::ofstream output(mFilename.c_str());
        for (typename std::vector<T>::iterator it = objects.begin(); it != objects.end(); it++)
            it->WriteOn(output);
        output.flush();
        output.close();
    }

private:
    std::string mFilename;
};
