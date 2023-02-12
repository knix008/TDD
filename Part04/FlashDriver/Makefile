TARGET=flashdrivertest
CC=gcc
CFLAGS= -Wall
CFLAGS_COV= $(CFLASG) -fprofile-arcs -ftest-coverage -g
UNITY_DIR=../../CUnity
CMOCK_DIR=../CMock/src
MOCK_DIR=../Mock
IO_DIR=../../IO

COVERAGE_SRC= FlashDriverTest.c
COVERAGE_OUTPUT_DIR= coverage
COVERAGE_INFO=testcoverage.info

SRCS= FlashDriverTest.c \
      FlashDriver.c

SRC_HEADER= FlashDriver.h

CMOCK_SRC=$(CMOCK_DIR)/cmock.c
MOCK_SRC=$(MOCK_DIR)/MockIO.c
UNITY_SRC=$(UNITY_DIR)/unity.c \
          $(UNITY_DIR)/extras/fixture/src/unity_fixture.c \
          $(UNITY_DIR)/extras/memory/src/unity_memory.c

INCLUDES=-I$(UNITY_DIR) \
         -I$(UNITY_DIR)/extras/fixture/src \
         -I$(UNITY_DIR)/extras/memory/src \
		 -I$(CMOCK_DIR) \
		 -I$(MOCK_DIR) \
		 -I$(IO_DIR)

UNITY_OBJS= unity.o unity_fixture.o unity_memory.o

$(TARGET): $(SRCS) $(SRC_HEADER) $(UNITY_OBJS) $(MOCK_SRC)
	@echo "Compiling $(TARGET).c..."
	@$(CC) -o $@ $(CFLAG) $(SRCS) $(CMOCK_SRC) $(MOCK_SRC) $(UNITY_OBJS) $(INCLUDES)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

$(UNITY_OBJS): $(UNITY)
	@$(CC) -c $(UNITY_SRC) $(INCLUDES)

coverage: $(SRCS) $(SRC_HEADER) $(UNITY_OBJS) $(MOCK_SRC)
	@$(CC) -o $(TARGET)_cov $(CFLAGS_COV) $(SRCS) $(CMOCK_SRC) $(MOCK_SRC) $(UNITY_OBJS) $(INCLUDES)
	@-./$(TARGET)_cov
	@gcov $(COVERAGE_SRC) 
	@lcov --rc lcov_branch_coverage=1 --capture --directory ./ --output-file $(COVERAGE_INFO)
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_OUTPUT_DIR}

all: $(TARGET) coverage

cclean:
	@-rm *.gcda *.gcno 
	@-rm *.gcov *.info
	@-rm -rf $(COVERAGE_OUTPUT_DIR)
	@-rm $(UNITY_OBJS)
	@-rm $(TARGET)_cov

clean:
	@rm -rf $(UNITY_OBJS)
	@rm $(TARGET)

cleanall: cclean clean