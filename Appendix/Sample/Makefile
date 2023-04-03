TARGET= main
SRCS= main.cpp

CC= g++
CXXFLAGS= -std=c++14 -Wall --coverage -g -O0

GCOV_DIR= .
COVERAGE_INFO= Coverage.info
COVERAGE_DIR= Coverage
.SILENT= all clean

all: 
	@-mkdir $(COVERAGE_DIR)
	@$(CC) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	@./$(TARGET)
	@gcov $(SRCS) > /dev/null 2>&1
	@lcov --rc lcov_branch_coverage=1 --capture --directory $(GCOV_DIR) --output-file $(COVERAGE_INFO) > /dev/null 2>&1
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_DIR} > /dev/null 2>&1

clean:
	@-rm $(TARGET) 
	@-rm *.gcov *.gcda *.gcno 
	@-rm $(COVERAGE_INFO) 
	@-rm -rf $(COVERAGE_DIR)
	@-rm -rf $(TARGET).dSYM > /dev/null 2>&1