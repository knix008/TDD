TARGET= flashdrivertest
COVERAGE_SRC=FlashDriverTest.cpp
MOCK_DIR= ../Mock
IO_DIR= ../IO
CMOCK_DIR=../CMock/src
UNITY_DIR=../../CUnity

SRCS= $(COVERAGE_SRC) \
      FlashDriver.c \
	  $(MOCK_DIR)/MockIO.c \
	  $(CMOCK_DIR)/cmock.c

INCLUDE_FILES= FlashDriver.h \
               $(MOCK_DIR)/MockIO.h \
			   $(IO_DIR)/IO.h

INCLUDES= -I$(MOCK_DIR) \
          -I$(IO_DIR) \
          -I$(CMOCK_DIR) \
		  -I$(UNITY_DIR)
            
CC= g++
CFLAGS= -Wall
CFLAGS_COV= -Wall -fprofile-arcs -ftest-coverage -g
INCLUDES+= -I/usr/include/CppUTest
LIBS= /usr/lib/x86_64-linux-gnu/libCppUTest.a
CPPUTESTRUN_OPTION= -c
COVERAGE_INFO=testcoverage.info
COVERAGE_OUTPUT_DIR=coverage
.SILENT: $(TARGET) clean

UNITY_SRC=$(UNITY_DIR)/unity.c \
          $(UNITY_DIR)/extras/fixture/src/unity_fixture.c \
          $(UNITY_DIR)/extras/memory/src/unity_memory.c

UNITY_INCLUDES=-I$(UNITY_DIR) \
              -I$(UNITY_DIR)/extras/fixture/src \
              -I$(UNITY_DIR)/extras/memory/src

OBJS= unity.o unity_fixture.o unity_memory.o

$(TARGET): $(SRCS) $(INCLUDE_FILES) $(OBJS)
	@echo "Building $(TARGET)..."
	@$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS) $(OBJS)
	@echo "Running $(TARGET)..."
	./$(TARGET) $(CPPUTESTRUN_OPTION)

$(OBJS): $(UNITY_SRC)
	@$(CC) -c $(UNITY_SRC) $(UNITY_INCLUDES)

coverage: 
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
	@-rm $(OBJS)
	@-rm $(TARGET)_cov

clean:
	@-rm $(OBJS)
	@-rm $(TARGET)

cleanall: cclean clean