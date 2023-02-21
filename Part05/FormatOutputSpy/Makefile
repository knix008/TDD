TARGET= formatoutputspy
COVERAGE_SRC=FormatOutputSpyTest.cpp

FORMATOUTPUTSPY_DIR= ../FormatOutputSpy
UTIL_DIR=../Util

SRCS= $(COVERAGE_SRC) \
      $(FORMATOUTPUTSPY_DIR)/FormatOutputSpy.c \
	  $(UTIL_DIR)/Util.c

INCLUDE_FILES= $(FORMATOUTPUTSPY_DIR)/FormatOutputSpy.h \
               $(UTIL_DIR)/Util.h

INCLUDES= -I$(FORMATOUTPUTSPY_DIR) \
          -I$(UTIL_DIR)
            
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
	@-./$(TARGET)_cov
	@gcov $(COVERAGE_SRC) $(CPPUTESTRUN_OPTION)
	@lcov --rc lcov_branch_coverage=1 --capture --directory ./ --output-file $(COVERAGE_INFO)
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_OUTPUT_DIR}

cclean:
	@-rm *.gcda *.gcno 
	@-rm *.gcov *.info
	@-rm -rf $(COVERAGE_OUTPUT_DIR)
	@-rm $(TARGET)_cov

clean:
	@-rm $(TARGET)