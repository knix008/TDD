TARGET= circularbuffertest
COVERAGE_SRC=CircularBufferTest.cpp

UTIL_DIR= ../Util
FORMATOUTPUTSPY_DIR= ../FormatOutputSpy

SRCS= $(COVERAGE_SRC) \
      $(FORMATOUTPUTSPY_DIR)/FormatOutputSpy.c \
	  $(UTIL_DIR)/Util.c \
	  CircularBuffer.c \
	  CircularBufferPrintTest.cpp

INCLUDE_FILES= $(UTIL_DIR)/Util.h \
               $(FORMATOUTPUTSPY_DIR)/FormatOutputSpy.h \
			   CircularBuffer.h

INCLUDES= -I$(UTIL_DIR) \
          -I$(FORMATOUTPUTSPY_DIR)
            
CC= g++
CFLAGS= -Wall
CFLAGS_COV= -Wall -fprofile-arcs -ftest-coverage -g
INCLUDES+= -I/usr/include/CppUTest
LIBS= /usr/lib/x86_64-linux-gnu/libCppUTest.a
CPPUTESTRUN_OPTION= -c
COVERAGE_INFO=testcoverage.info
COVERAGE_OUTPUT_DIR=coverage
.SILENT: $(TARGET) clean

$(TARGET): $(SRCS) $(INCLUDE_FILES)
	@echo "Building $(TARGET)..."
	@$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	./$(TARGET) $(CPPUTESTRUN_OPTION)

coverage: 
	@$(CC) -o $(TARGET)_cov $(CFLAGS_COV) $(SRCS) $(INCLUDES) $(LIBS)
	@-./$(TARGET)_cov $(CPPUTESTRUN_OPTION)
	@gcov $(COVERAGE_SRC) 
	@lcov --rc lcov_branch_coverage=1 --capture --directory ./ --output-file $(COVERAGE_INFO)
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_OUTPUT_DIR}

all: $(TARGET) coverage

cclean:
	@-rm *.gcda *.gcno 
	@-rm *.gcov *.info
	@-rm -rf $(COVERAGE_OUTPUT_DIR)
	@-rm $(TARGET)_cov

clean:
	@-rm $(TARGET)

cleanall: cclean clean