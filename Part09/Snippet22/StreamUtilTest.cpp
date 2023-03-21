#include <fstream>
#include <sstream>
#include "StreamUtil.h"

/* The following line should be included after the other header file */
#include <CppUTest/CommandLineTestRunner.h>

using namespace std;

TEST_GROUP(StreamUtil_Size) {
};

TEST(StreamUtil_Size, AnswersNumberOfBytesWrittenToStream) {
   istringstream readFrom{"abcdefg"};

   CHECK_EQUAL(7, StreamUtil::size(readFrom));
}

