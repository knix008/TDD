#include <string>
#include "WavReader.h"

/* Be sure that STL related header files are included before this line. */
/* Otherwiser, it will cause compile errors. */
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>

TEST_GROUP(WavReader){};

TEST(WavReader, HasExtension)
{
   std::string s{"a.bcd"};
   CHECK(!hasExtension(s, "xxxx"));
   CHECK(hasExtension(s, "bcd"));

   std::string bigger{"aaabcd"};
   CHECK(!hasExtension(s, bigger));
}
