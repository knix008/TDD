#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "WavReader.h"

/* Be sure that STL related header files are included before this line. */
/* Otherwiser, it will cause compile errors. */
#include <CppUTest/CommandLineTestRunner.h>
#include <CppUTestExt/MockSupport.h>

using namespace std;

TEST_GROUP(WavReader){};

TEST(WavReader, HasExtension)
{
   string s{"a.bcd"};
   CHECK(!hasExtension(s, "xxxx"));
   CHECK(hasExtension(s, "bcd"));
   string bigger{"aaabcd"};
   CHECK(!hasExtension(s, bigger));
}

TEST_GROUP(WavReader_WriteSamples)
{
   WavReader reader{"", ""};
   ostringstream out;
};

TEST(WavReader_WriteSamples, WritesSingleSample)
{
   char data[]{"abcd"};
   uint32_t bytesPerSample{1};
   uint32_t startingSample{0};
   uint32_t samplesToWrite{1};

   reader.writeSamples(&out, data, startingSample, samplesToWrite, bytesPerSample);

   CHECK_EQUAL("a", out.str());
}

TEST(WavReader_WriteSamples, WritesMultibyteSampleFromMiddle)
{
   char data[]{"0123456789ABCDEFG"};
   uint32_t bytesPerSample{2};
   uint32_t startingSample{4};
   uint32_t samplesToWrite{3};

   reader.writeSamples(&out, data, startingSample, samplesToWrite, bytesPerSample);

   CHECK_EQUAL("89ABCD", out.str());
}

TEST(WavReader_WriteSamples, IncorporatesChannelCount)
{
   char data[]{"0123456789ABCDEFG"};
   uint32_t bytesPerSample{2};
   uint32_t startingSample{0};
   uint32_t samplesToWrite{2};
   uint32_t channels{2};

   reader.writeSamples(&out, data, startingSample, samplesToWrite, bytesPerSample, channels);

   CHECK_EQUAL("01234567", out.str());
}

TEST_GROUP(WavReader_DataLength)
{
   WavReader reader{"", ""};
};

TEST(WavReader_DataLength, IsProductOfChannels_BytesPerSample_and_Samples)
{
   uint32_t bytesPerSample{2};
   uint32_t samples{5};
   uint32_t channels{4};

   uint32_t length{reader.dataLength(bytesPerSample, samples, channels)};

   CHECK_EQUAL(2 * 5 * 4, length);
}

class MockWavDescriptor : public WavDescriptor
{
public:
   MockWavDescriptor() : WavDescriptor("") {}
   void add(
       const string &, const string &,
       uint32_t totalSeconds,
       uint32_t, uint32_t,
       uint32_t fileSize) override
   {
      mock().actualCall("add")
         .withParameter("totalSeconds", (int)totalSeconds)
         .withParameter("fileSize", (int)fileSize);
   }
};

class MockFileUtil : public FileUtil
{
public:
   streamsize size(const string &name) override
   {
      return mock().actualCall("size").returnValue().getIntValue();
   }
};

TEST_GROUP(WavReader_WriteSnippet)
{
   shared_ptr<MockWavDescriptor> descriptor{new MockWavDescriptor};
   WavReader reader{"", "", descriptor};
   shared_ptr<MockFileUtil> fileUtil{make_shared<MockFileUtil>()};
   istringstream input{""};
   FormatSubchunk formatSubchunk;
   ostringstream output;
   DataChunk dataChunk;
   char *data;
   uint32_t TwoBytesWorthOfBits{2 * 8};
   const int ArbitraryFileSize{5};

   void setup() override
   {
      data = new char[4];
      reader.useFileUtil(fileUtil);
   }

   void teardown() override
   {
      mock().clear();
      delete[] data;
   }
};

TEST(WavReader_WriteSnippet, SendsFileLengthAndTotalSecondsToDescriptor)
{
   dataChunk.length = 8;
   formatSubchunk.bitsPerSample = TwoBytesWorthOfBits;
   formatSubchunk.samplesPerSecond = 1;
   mock().expectOneCall("size").andReturnValue(ArbitraryFileSize);
   mock().expectOneCall("add")
      .withParameter("totalSeconds", 8 / 2 / 1)
      .withParameter("fileSize", ArbitraryFileSize);

   reader.writeSnippet("any", input, output, formatSubchunk, dataChunk, data);

   mock().checkExpectations();
}