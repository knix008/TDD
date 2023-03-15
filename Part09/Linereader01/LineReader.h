#ifndef __LINEREADER_H__
#define __LINEREADER_H__

#include <stdint.h>
#include <assert.h>
#include <string.h>
#include "linux_syscall_support.h"

// A class for reading a file, line by line, without using
// fopen/fgets or other functions which may allocate memory.
class LineReader
{
public:
  LineReader(int fd) : fd_(fd), hit_eof_(false), buf_used_(0)
  {
  }

  // The maximum length of a line.
  static const size_t kMaxLineLen = 512;

  // Return the next line from the file.
  //   line: (output) a pointer to the start of the line. The line is NUL
  //     terminated.
  //   len: (output) the length of the line (not inc the NUL byte)
  //
  // Returns true iff successful (false on EOF).
  //
  // One must call |PopLine| after this function, otherwise you'll continue to
  // get the same line over and over.
  bool GetNextLine(const char **line, unsigned *len)
  {
    for (;;)
    {
      if (buf_used_ == 0 && hit_eof_)
        return false;

      for (unsigned i = 0; i < buf_used_; ++i)
      {
        if (buf_[i] == '\n' || buf_[i] == 0)
        {
          buf_[i] = 0;
          *len = i;
          *line = buf_;
          return true;
        }
      }

      if (buf_used_ == sizeof(buf_))
      {
        // we scanned the whole buffer and didn't find an end-of-line marker.
        // This line is too long to process.
        return false;
      }

      // We didn't find any end-of-line terminators in the buffer. However, if
      // this is the last line in the file it might not have one:
      if (hit_eof_)
      {
        assert(buf_used_);
        // There's room for the NUL because of the buf_used_ == sizeof(buf_)
        // check above.
        buf_[buf_used_] = 0;
        *len = buf_used_;
        buf_used_ += 1; // since we appended the NUL.
        *line = buf_;
        return true;
      }

      // Otherwise, we should pull in more data from the file
      const ssize_t n = sys_read(fd_, buf_ + buf_used_, sizeof(buf_) - buf_used_);
      if (n < 0)
      {
        return false;
      }
      else if (n == 0)
      {
        hit_eof_ = true;
      }
      else
      {
        buf_used_ += n;
      }

      // At this point, we have either set the hit_eof_ flag, or we have more
      // data to process...
    }
  }

  void PopLine(unsigned len)
  {
    // len doesn't include the NUL byte at the end.
    assert(buf_used_ >= len + 1);
    buf_used_ -= len + 1;
    memmove(buf_, buf_ + len + 1, buf_used_);
  }

private:
  const int fd_;
  bool hit_eof_;
  unsigned buf_used_;
  char buf_[kMaxLineLen];
};

#endif
