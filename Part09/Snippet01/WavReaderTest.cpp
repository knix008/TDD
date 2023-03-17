#include <string>
#include <iostream>
#include "WavReader.h"
/* Be sure that STL related header files are included before this line. */
/* Otherwiser, it will cause compile errors. */
#include <CppUTest/CommandLineTestRunner.h>

using namespace std;

TEST_GROUP(WavReader) {
};

TEST(WavReader, HasExtension) {
   string s{"a.bcd"};
   CHECK(!hasExtension(s, "xxxx"));
   CHECK(hasExtension(s, "bcd"));
   string bigger{"aaabcd"};
   CHECK(!hasExtension(s, bigger));
}
