TARGET= test
BUILD= build
GOOGLETEST_OPTION= --gtest_catch_exceptions=0
GOOGLETEST_FILTER= --gtest_filter=KeyedMemory/PersistenceTest.*
.SILENT=all clean

all: 
	@echo "<======================Buiing Image=====================>"
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@echo "<======================Running Test=====================>"
	@$(BUILD)/libraryTest/$(TARGET) $(GOOGLETEST_OPTION) $(GOOGLETEST_FILTER)

clean:
	@-rm -rf $(BUILD)
	@-rm test.dat