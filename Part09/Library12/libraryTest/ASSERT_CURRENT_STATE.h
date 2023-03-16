/***
 * Excerpted from "Modern C++ Programming with Test-Driven Development",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material, 
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose. 
 * Visit http://www.pragmaticprogrammer.com/titles/lotdd for more book information.
***/
#pragma once

#include "Scanner.h"

// TODO create a custom matcher for this instead!
template <typename T> static void ASSERT_CURRENT_STATE(Scanner* scanner)
{
    ASSERT_TRUE(dynamic_cast<T*>(scanner->CurrentState()) != NULL);
}
