TARGET= Test
BUILD= Build
CPPUTEST_OPTION= -c -v

TARGET_SRC= testmain.cpp
COVERAGE_INFO=testcoverage.info
COVERAGE_DIR=Coverage

all: 
	@echo "<======== Making Test Coverage =========>"
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@$(BUILD)/$(TARGET) $(CPPUTEST_OPTION)
#@gcov $(TARGET_SRC) 1> /dev/null
	@lcov --rc lcov_branch_coverage=1 --capture --directory ./ --output-file $(COVERAGE_INFO) 1>/dev/null
	@genhtml ${COVERAGE_INFO} --output-directory ${COVERAGE_DIR} 1>/dev/null

clean:
#@-rm *.gcda *.gcno 
#@-rm *.gcov *.info
	@-rm $(COVERAGE_INFO)
	@-rm -rf $(COVERAGE_DIR)
	@-rm -rf $(BUILD)