#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include "gmock/gmock.h"
#include "LineReader.h"

static int TemporaryFile()
{
  static const char templ[] = "/tmp/line-reader-unittest-XXXXXX";
  char templ_copy[sizeof(templ)];
  memcpy(templ_copy, templ, sizeof(templ));
  const int fd = mkstemp(templ_copy);
  if (fd >= 0)
    unlink(templ_copy);

  return fd;
}

static int WriteTemporaryFile(const char *records)
{
  const int fd = TemporaryFile();
  write(fd, records, strlen(records));
  lseek(fd, 0, SEEK_SET);
  return fd;
}

class LineReaderTest : public testing::Test
{
public:
  int fd;
  void TearDown()
  {
    close(fd);
  }
};

// namespace {
// typedef testing::Test LineReaderTest;
// }

TEST_F(LineReaderTest, EmptyFile)
{
  fd = WriteTemporaryFile("");
  LineReader reader(fd);

  const char *line;
  unsigned len;
  ASSERT_FALSE(reader.GetNextLine(&line, &len));
}

TEST_F(LineReaderTest, OneLineTerminated)
{
  int fd = WriteTemporaryFile("a\n");
  LineReader reader(fd);

  const char *line;
  unsigned int len;
  ASSERT_TRUE(reader.GetNextLine(&line, &len));
  ASSERT_EQ(len, (unsigned int)1);
  ASSERT_EQ(line[0], 'a');
  ASSERT_EQ(line[1], 0);
  reader.PopLine(len);

  ASSERT_FALSE(reader.GetNextLine(&line, &len));
}

TEST_F(LineReaderTest, OneLine)
{
  fd = WriteTemporaryFile("a");
  LineReader reader(fd);

  const char *line;
  unsigned len;
  ASSERT_TRUE(reader.GetNextLine(&line, &len));
  ASSERT_EQ(len, (unsigned)1);
  ASSERT_EQ(line[0], 'a');
  ASSERT_EQ(line[1], 0);
  reader.PopLine(len);

  ASSERT_FALSE(reader.GetNextLine(&line, &len));
}

TEST_F(LineReaderTest, TwoLinesTerminated)
{
  fd = WriteTemporaryFile("a\nb\n");
  LineReader reader(fd);

  const char *line;
  unsigned len;
  ASSERT_TRUE(reader.GetNextLine(&line, &len));
  ASSERT_EQ(len, (unsigned)1);
  ASSERT_EQ(line[0], 'a');
  ASSERT_EQ(line[1], 0);
  reader.PopLine(len);

  ASSERT_TRUE(reader.GetNextLine(&line, &len));
  ASSERT_EQ(len, (unsigned)1);
  ASSERT_EQ(line[0], 'b');
  ASSERT_EQ(line[1], 0);
  reader.PopLine(len);

  ASSERT_FALSE(reader.GetNextLine(&line, &len));
}

TEST_F(LineReaderTest, TwoLines)
{
  fd = WriteTemporaryFile("a\nb");
  LineReader reader(fd);

  const char *line;
  unsigned len;
  ASSERT_TRUE(reader.GetNextLine(&line, &len));
  ASSERT_EQ(len, (unsigned)1);
  ASSERT_EQ(line[0], 'a');
  ASSERT_EQ(line[1], 0);
  reader.PopLine(len);

  ASSERT_TRUE(reader.GetNextLine(&line, &len));
  ASSERT_EQ(len, (unsigned)1);
  ASSERT_EQ(line[0], 'b');
  ASSERT_EQ(line[1], 0);
  reader.PopLine(len);

  ASSERT_FALSE(reader.GetNextLine(&line, &len));
}

TEST_F(LineReaderTest, MaxLength)
{
  char l[LineReader::kMaxLineLen - 1];
  memset(l, 'a', sizeof(l));
  fd = WriteTemporaryFile(l);
  LineReader reader(fd);

  const char *line;
  unsigned len;
  ASSERT_TRUE(reader.GetNextLine(&line, &len));
  ASSERT_EQ(len, sizeof(l));
  ASSERT_TRUE(memcmp(l, line, sizeof(l)) == 0);
  ASSERT_EQ(line[len], 0);
}

TEST_F(LineReaderTest, TooLong)
{
  char l[LineReader::kMaxLineLen];
  memset(l, 'a', sizeof(l));
  fd = WriteTemporaryFile(l);
  LineReader reader(fd);

  const char *line;
  unsigned len;
  ASSERT_FALSE(reader.GetNextLine(&line, &len));
}
