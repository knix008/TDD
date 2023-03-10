TARGET= faketimeservicetest

COVERAGE_SRC= FakeTimeServiceTest.cpp

TIMESERVICE_DIR= ../TimeService
TIME_DIR= ../Time

SRCS= FakeTimeServiceTest.cpp \
      FakeTimeService.c

INCLUDE_FILES= FakeTimeService.h \
               $(TIMESERVICE_DIR)/TimeService.h \
			   $(TIME_DIR)/Time.h

INCLUDES= -I$(TIMESERVICE_DIR) \
          -I$(TIME_DIR) 

CC= g++
CFLAGS= -Wall
CFLAGS_COV= -Wall -fprofile-arcs -ftest-coverage -g
INCLUDES+= -I/usr/include/CppUTest
LIBS= /usr/lib/x86_64-linux-gnu/libCppUTest.a
CPPUTESTRUN_OPTION= -c
COVERAGE_INFO=testcoverage.info
COVERAGE_OUTPUT_DIR=coverage
.SILENT: $(TARGET) coverage clean cclean

$(TARGET): $(SRCS) $(INCLUDE_FILES)
	@echo "Building $(TARGET)..."
	@$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@./$(TARGET) $(CPPUTESTRUN_OPTION)

coverage: $(SRCS) $(INCLUDE_FILES)
	@$(CC) -o $(TARGET)_cov $(CFLAGS_COV) $(SRCS) $(INCLUDES) $(LIBS)
	@-./$(TARGET)_cov $(CPPUTESTRUN_OPTION)
	@gcov $(COVERAGE_SRC) $(CPPUTESTRUN_OPTION)
	@lcov --rc lcov_branch_coverage=1 --capture --directory ./ --output-file $(COVERAGE_INFO)
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_OUTPUT_DIR}

clean:
	@rm $(TARGET)

cclean:
	@-rm *.gcda *.gcno 
	@-rm *.gcov *.info
	@-rm -rf $(COVERAGE_OUTPUT_DIR)
	@-rm $(TARGET)_cov

all: $(TARGET) coverage
cleanall: cclean clean