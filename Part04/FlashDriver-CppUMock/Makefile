TARGET= flashdrivertest
COVERAGE_SRC=FlashDriverTest.cpp

IO_DIR= ../IO
IOMOCK_DIR= ../IOMock
MICROTIME_DIR= ../MicroTime
FAKEMICROTIME_DIR= ../FakeMicroTime

SRCS= $(COVERAGE_SRC) \
      FlashDriver.c \
	  $(IOMOCK_DIR)/IOMock.c \
	  $(FAKEMICROTIME_DIR)/FakeMicroTime.c

INCLUDE_FILES= FlashDriver.h \
			   $(IO_DIR)/IO.h \
			   $(IOMOCK_DIR)/IOMock.h \
			   $(MICROTIME_DIR)/MicroTime.h \
			   $(FAKEMICROTIME_DIR)/FakeMicroTime.h

INCLUDES= -I$(IO_DIR) \
          -I$(IOMOCK_DIR) \
          -I$(MICROTIME_DIR) \
		  -I$(FAKEMICROTIME_DIR)
            
CC= g++
CFLAGS= -Wall
INCLUDES+= -I/usr/include/CppUTest \
           -I/usr/include/CppUTestExt
LIBS= /usr/lib/x86_64-linux-gnu/libCppUTest.a \
      /usr/lib/x86_64-linux-gnu/libCppUTestExt.a
CPPUTESTRUN_OPTION= -c

CFLAGS_COV= -Wall -fprofile-arcs -ftest-coverage -g
COVERAGE_INFO=testcoverage.info
COVERAGE_OUTPUT_DIR=coverage

.SILENT: $(TARGET) clean

$(TARGET): $(SRCS) $(INCLUDE_FILES)
	@echo "Building $(TARGET)..."
	@$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS) $(OBJS)
	@echo "Running $(TARGET)..."
	@./$(TARGET) $(CPPUTESTRUN_OPTION)

coverage: $(SRCS) $(INCLUDE_FILES)
	@$(CC) -o $(TARGET)_cov $(CFLAGS_COV) $(SRCS) $(INCLUDES) $(LIBS) $(OBJS)
	@-./$(TARGET)_cov
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