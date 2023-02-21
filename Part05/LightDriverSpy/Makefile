TARGET= lightdriverspytest
COVERAGE_SRC=LightDriverSpyTest.cpp

LIGHTDRIVER_DIR= ../LightDriver
LIGHTCONTROLLER_DIR= ../LightController

SRCS= $(COVERAGE_SRC) \
      LightDriverSpy.c \
	  $(LIGHTDRIVER_DIR)/LightDriver.c \
	  $(LIGHTCONTROLLER_DIR)/LightController.c

INCLUDE_FILES= LightDriverSpy.h \
      $(LIGHTDRIVER_DIR)/LightDriver.h \
	  $(LIGHTCONTROLLER_DIR)/LightController.h

INCLUDES= -I$(LIGHTDRIVER_DIR) \
	  -I$(LIGHTCONTROLLER_DIR) \
	  -I.

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
	./$(TARGET) $(CPPUTESTRUN_OPTION)

coverage: $(SRCS) $(INCLUDE_FILES)
	@$(CC) -o $(TARGET)_cov $(CFLAGS_COV) $(SRCS) $(INCLUDES) $(LIBS)
	@-./$(TARGET)_cov $(CPPUTESTRUN_OPTION)
	@gcov $(COVERAGE_SRC) 
	@lcov --rc lcov_branch_coverage=1 --capture --directory ./ --output-file $(COVERAGE_INFO)
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_OUTPUT_DIR}

cclean:
	@-rm *.gcda *.gcno 
	@-rm *.gcov *.info
	@-rm -rf $(COVERAGE_OUTPUT_DIR)
	@-rm $(TARGET)_cov

clean:
	@-rm $(TARGET)

all: $(TARGET) coverage
cleanall: cclean clean