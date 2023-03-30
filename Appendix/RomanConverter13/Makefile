TARGET= Test
BUILD= Build
GOOGLETEST_OPTION= --gtest_catch_exceptions=0
GOOGLETEST_FILTER= --gtest_filter=*.*

TARGET_SRC= RomanConverterTest.cpp
COVERAGE_INFO= testcoverage.info
COVERAGE_DIR= Coverage
GCOV_DIR= $(BUILD)/CMakeFiles/Test.dir/

all: 
	@echo "<===============Building...=================>"
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@echo "<===============Running...==================>"
	@$(BUILD)/$(TARGET) $(GOOGLETEST_OPTION) $(GOOGLETEST_FILTER)
	@gcov $(TARGET_SRC) > /dev/null 2>&1
	@lcov --rc lcov_branch_coverage=1 --capture --directory $(GCOV_DIR) --output-file $(COVERAGE_INFO) 1>/dev/null
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_DIR} 1>/dev/null

clean:
	@-rm -rf $(BUILD)
	@-rm $(COVERAGE_INFO)
	@-rm -rf $(COVERAGE_DIR)