TARGET= Test
BUILD= Build
CPPUTEST_OPTION= -c -v

TARGET_SRC= testmain.cpp
COVERAGE_INFO= testcoverage.info
COVERAGE_DIR= Coverage
GCOV_DIR= $(BUILD)/CMakeFiles/Test.dir/

all: 
	@echo "<======== Making Test Coverage =========>"
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@$(BUILD)/$(TARGET) $(CPPUTEST_OPTION)
	@gcov $(TARGET_SRC) > /dev/null 2>&1
	@lcov --rc lcov_branch_coverage=1 --capture --directory $(GCOV_DIR) --output-file $(COVERAGE_INFO) 1>/dev/null
	@genhtml ${COVERAGE_INFO} --branch-coverage --output-directory ${COVERAGE_DIR} 1>/dev/null

clean:
	@-rm $(COVERAGE_INFO) > /dev/null 2>&1
	@-rm -rf $(COVERAGE_DIR) > /dev/null 2>&1
	@-rm -rf $(BUILD) > /dev/null 2>&1