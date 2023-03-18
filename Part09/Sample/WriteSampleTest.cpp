#include <iostream>
#include <string>
#include <sstream>
#include <CppUTest/CommandLineTestRunner.h>
#include "WriteSample.h"

using namespace std;

TEST_GROUP(WriteSample){};

TEST(WriteSample, WritesSingleSample)
{
   char data[]{"abcd"};
   ostringstream out;

   uint32_t bytesPerSample{1};
   uint32_t startingSample{0};
   uint32_t samplesToWrite{1};
   WriteSample(&out, data, startingSample, samplesToWrite, bytesPerSample);
   CHECK_EQUAL("a", out.str());
}