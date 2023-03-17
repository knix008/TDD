//#include "CppUTest/TestHarness.h"
#include <string>
#include <iostream>
#include <CppUTest/CommandLineTestRunner.h>
#include "WavReader.h"

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
