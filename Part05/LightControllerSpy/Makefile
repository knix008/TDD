TARGET= lightcontrollertest

COVERAGE_SRC=LightControllerSpyTest.c
LIGHTCONTROLLER_DIR= ../LightController
LIGHTDRIVER_DIR= ../LightDriver
LIGHTDRIVERSPY_DIR= ../LightDriverSpy

SRCS= LightControllerSpyTest.cpp \
      LightControllerSpy.c \
	  $(LIGHTDRIVER_DIR)/LightDriver.c

INCLUDE_FILES= $(LIGHTCONTROLLER_DIR)/LightController.h \
               $(LIGHTDRIVER_DIR)/LightDriver.h \
			   $(LIGHTDRIVERSPY_DIR)/LightDriverSpy.h \
               LightControllerSpy.h

INCLUDES= -I$(LIGHTCONTROLLER_DIR) \
          -I$(LIGHTDRIVER_DIR) \
		  -I$(LIGHTDRIVERSPY_DIR)

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
	@gcov $(COVERAGE_SRC) 
	@lcov --rc lcov_branch_coverage=1 --capture --directory ./ --output-file $(COVERAGE_INFO)
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_OUTPUT_DIR}

cclean:
	@-rm *.gcda *.gcno 
	@-rm *.gcov *.info
	@-rm -rf $(COVERAGE_OUTPUT_DIR)
	@-rm $(TARGET)_cov

clean:
	@rm $(TARGET)

all: $(TARGET) coverage
cleanall: cclean clean