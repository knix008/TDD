#include <iostream>
#include <string>
#include <sstream>
#include "WriteSample.h"

#include <CppUTest/CommandLineTestRunner.h>

using namespace std;

TEST_GROUP(WriteSamplesTest){
   ostringstream out;
};

TEST(WriteSamplesTest, WritesSingleSample)
{
   char data[]{"abcd"};

   uint32_t bytesPerSample{1};
   uint32_t startingSample{0};
   uint32_t samplesToWrite{1};

   WriteSamples(&out, data, startingSample, samplesToWrite, bytesPerSample);

   CHECK_EQUAL("a", out.str());
}

TEST(WriteSamplesTest, WritesMultibyteSampleFromMiddle)
{
   char data[]{"0123456789ABCDEFG"};
   uint32_t bytesPerSample{2};
   uint32_t startingSample{4};
   uint32_t samplesToWrite{3};

   WriteSamples(&out, data, startingSample, samplesToWrite, bytesPerSample);
   CHECK_EQUAL("89ABCD", out.str());
}