TARGET= SoundexTest
TARGET_SRC=$(TARGET)14.cpp

SRCS= $(TARGET_SRC) \
       Soundex09.cpp
#       Soundex08.cpp
#       Soundex07.cpp
#  	    Soundex06.cpp
#       Soundex05.cpp
#       Soundex04.cpp
#       Soundex03.cpp
#       Soundex02.cpp
#       Soundex01.cpp

INCLUDE_DIRS= ../Include
INCLUDE_FILE= Soundex05.h
#             Soundex04.h
#             Soundex03.h
#             Soundex02.h
#             Soundex01.h
INCLUDE_FILES= $(INCLUDE_DIRS)/$(INCLUDE_FILE)
INCLUDES= -I$(INCLUDE_DIRS)

CC= g++
CFLAGS= -Wall --std=c++14
CFLAGS_COV= -Wall -fprofile-arcs -ftest-coverage -g
INCLUDES+= -I/usr/local/include/gtest \
           -I/usr/local/include/gmock
LIBS= /usr/local/lib/libgmock.a \
      /usr/local/lib/libgtest.a \
	  -lpthread

COVERAGE_INFO=testcoverage.info
COVERAGE_OUTPUT_DIR=coverage
.SILENT: $(TARGET) coverage clean cclean

$(TARGET): $(TARGET_SRC) $(SRCS) $(INCLUDE_FILES)
	@echo "Building $(TARGET) with $(SRCS) $(INCLUDE_FILE)..."
	@$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

coverage: $(TARGET_SRC) $(SRCS) $(INCLUDE_FILES)
	@echo "Building Test Coverage with $(SRCS) $(INCLUDE_FILE)..."
	@$(CC) -o $(TARGET)_cov $(CFLAGS_COV) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@-./$(TARGET)_cov
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
