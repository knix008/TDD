TARGET= lightcontrollertest
COVERAGE_SRC=LightControllerTest.cpp

LIGHTDRIVERSPY_DIR= ../LightDriverSpy
DEVICES_DIR= ../Devices
LIGHTDRIVER_DIR= ../LightDriver
COMMON_DIR= ../Common

SRCS= LightControllerTest.cpp \
      LightController.c \
	  $(LIGHTDRIVERSPY_DIR)/LightDriverSpy.c \
	  $(DEVICES_DIR)/AcmeWirelessLightDriver.c \
	  $(DEVICES_DIR)/MemMappedLightDriver.c \
	  $(DEVICES_DIR)/X10LightDriver.c \
	  $(LIGHTDRIVER_DIR)/LightDriver.c \
	  $(COMMON_DIR)/Explodes.c

INCLUDE_FILES= LightController.h \
      $(LIGHTDRIVERSPY_DIR)/LightDriverSpy.h \
	  $(DEVICES_DIR)/AcmeWirelessLightDriver.h \
	  $(DEVICES_DIR)/MemMappedLightDriver.h \
	  $(DEVICES_DIR)/X10LightDriver.h \
      $(LIGHTDRIVER_DIR)/LightDriver.h \
	  $(COMMON_DIR)/Explodes.h

INCLUDES= -I$(LIGHTDRIVERSPY_DIR) \
      -I$(DEVICES_DIR) \
	  -I$(LIGHTDRIVER_DIR) \
	  -I$(COMMON_DIR) \
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

all: $(TARGET) coverage
cleanall: cclean clean