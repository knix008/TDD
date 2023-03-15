TARGET= PortfolioTest
CC= g++
GOOGLETEST_OPTION= --gtest_catch_exceptions=0
CFLAGS= -Wall --std=c++0x
CFLAGS_COV= -Wall -fprofile-arcs -ftest-coverage -g
INCLUDES= -I/usr/local/include/gtest \
          -I/usr/local/include/gmock \
		  -I/usr/local/include/boost

LIBS= /usr/local/lib/libgmock.a \
      /usr/local/lib/libgtest.a \
	  -lpthread

TARGET_SRC= PortfolioTest.cpp
SRCS= Holding.cpp \
	  HoldingTest.cpp \
	  Portfolio.cpp

INCLUDE_FILES= DateTestConstants.h \
               Holding.h \
			   Portfolio.h \
			   PurchaseRecord.h

SRCS+= $(TARGET_SRC) main.cpp
COVERAGE_INFO=testcoverage.info
COVERAGE_OUTPUT_DIR=coverage
.SILENT: $(TARGET) coverage clean cclean

$(TARGET): $(TARGET_SRC) $(SRCS) $(INCLUDE_FILES)
	@echo "Building $(TARGET) with $(SRCS) $(INCLUDE_FILE)..."
	@$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@./$(TARGET) $(GOOGLETEST_OPTION)

coverage: $(TARGET_SRC) $(SRCS) $(INCLUDE_FILES)
	@echo "Building Test Coverage with $(SRCS) $(INCLUDE_FILE)..."
	@$(CC) $(CFLAGS_COV) -o $(TARGET)_cov $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@-./$(TARGET)_cov $(GOOGLETEST_OPTION)
	@gcov $(TARGET_SRC) 1>/dev/null
	@lcov --rc lcov_branch_coverage=1 --capture --directory ./ --output-file $(COVERAGE_INFO) 1>/dev/null
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_OUTPUT_DIR} 1>/dev/null

cclean:
	@-rm *.gcda *.gcno 
	@-rm *.gcov *.info
	@-rm -rf $(COVERAGE_OUTPUT_DIR)
	@-rm $(TARGET)_cov

clean:
	@-rm $(TARGET)

all: $(TARGET) coverage
cleanall : cclean clean