#include <fstream>
#include <istream>
#include <stdio.h>
#include "FileUtil.h"
#include "StreamUtil.h"
/* The following line should be included after the other header file */
#include <CppUTest/CommandLineTestRunner.h>

using namespace std;

class FileUtilTests: public Utest  {
protected:
   const string TempFileName{"FileUtil_SizeTest.dat"};
   FileUtil util;

   void teardown() {
      remove(TempFileName.c_str());
   }

   void createTempFile(const std::string& content) {
      ofstream stream{TempFileName, ios::out | ios::binary};
      stream << content << endl;
      stream.close();
   }
};

// slow tests that must interact with the filesystem
TEST_GROUP_BASE(FileUtil_Size, FileUtilTests) {
};

TEST(FileUtil_Size, AnswersFileContentSize) {
   string content("12345");
   createTempFile(content);

   size_t expectedSize { content.length() + sizeof('\0') };
   LONGS_EQUAL(expectedSize, (unsigned)util.size(TempFileName));
}

TEST_GROUP_BASE(FileUtil_Execute, FileUtilTests) {
};

TEST(FileUtil_Execute, IsPassedStreamFromFile) {
   string content("abcdefg");
   streamsize returnValue{999};
   createTempFile(content);
   string buffer;

   auto func = [&](istream& stream) { 
      getline(stream, buffer);
      return returnValue; 
   };
   auto result = util.execute(TempFileName, func);

   LONGS_EQUAL(returnValue, result);
   CHECK_EQUAL(content, buffer);
}

TEST(FileUtil_Execute, DemonstratedWithStreamUtilSizeFunction) {
   string content("abcdefg");
   createTempFile(content);

   streamsize size = util.execute(TempFileName, 
                  [&](istream& s) { return StreamUtil::size(s); });

   LONGS_EQUAL(content.length() + sizeof('\0'), (unsigned)size);
}

