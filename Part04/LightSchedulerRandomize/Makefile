TARGET= lightschedulertest
COVERAGE_SRC=LightSchedulerTest.cpp

FAKETIMESERVICE_DIR= ../FakeTimeService
FAKERANDOMMINUTE_DIR= ../FakeRandomMinute
LIGHTCONTROLLERSPY_DIR= ../LightControllerSpy
RANDOMMINUTE_DIR=../RandomMinute

#SRCS= LightSchedulerRandomTest.cpp
SRCS= LightSchedulerTest.cpp \
      LightScheduler.c \
      $(FAKETIMESERVICE_DIR)/FakeTimeService.c \
	  $(FAKERANDOMMINUTE_DIR)/FakeRandomMinute.c \
      $(LIGHTCONTROLLERSPY_DIR)/LightControllerSpy.c \
	  $(RANDOMMINUTE_DIR)/RandomMinute.c

INCLUDE_FILES= LightScheduler.h \
               $(FAKETIMESERVICE_DIR)/FakeTimeService.h \
			   $(FAKERANDOMMINUTE_DIR)/FakeRandomMinute.h \
               $(LIGHTCONTROLLERSPY_DIR)/LightControllerSpy.h \
			   $(RANDOMMINUTE_DIR)/RandomMinute.h

INCLUDES= -I$(FAKETIMESERVICE_DIR) \
          -I$(FAKERANDOMMINUTE_DIR) \
          -I$(LIGHTCONTROLLERSPY_DIR) \
		  -I$(RANDOMMINUTE_DIR)
            
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