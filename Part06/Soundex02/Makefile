TARGET= SoundexTest
TARGET_SRC=$(TARGET)12.cpp

SRCS= $(TARGET_SRC) \
      Soundex01.cpp
INCLUDE_DIRS= ../Include
INCLUDE_FILES= $(INCLUDE_DIRS)/Soundex01.h
INCLUDES= -I$(INCLUDE_DIRS)

CC= g++
CFLAGS= -Wall --std=c++14
CFLAGS_COV= -Wall -fprofile-arcs -ftest-coverage -g
INCLUDES+= -I/usr/local/include/gtest \
           -I/usr/local/include/gmock
LIBS= /usr/local/lib/libgmock.a \
      /usr/local/lib/libgtest.a \
	  -lpthread

COVERAGE_INFO=testcoverage.info
COVERAGE_OUTPUT_DIR=coverage
.SILENT: $(TARGET) coverage clean cclean

$(TARGET): $(SRCS) $(INCLUDE_FILES)
	@echo "Building $(TARGET)..."
	@$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

coverage: 
	@echo "Building Test Coverage for $(TAREGET)..."
	@$(CC) -o $(TARGET)_cov $(CFLAGS_COV) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@-./$(TARGET)_cov
	@gcov $(TARGET_SRC) 1>/dev/null
	@lcov --rc lcov_branch_coverage=1 --capture --directory ./ --output-file $(COVERAGE_INFO) 1>/dev/null
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_OUTPUT_DIR} 1>/dev/null

cclean:
	@-rm *.gcda *.gcno 
	@-rm *.gcov *.info
	@-rm -rf $(COVERAGE_OUTPUT_DIR)
	@-rm $(TARGET)_cov

clean:
	@-rm $(TARGET)
