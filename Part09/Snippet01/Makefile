TARGET= Test
BUILD= Build
GOOGLETEST_OPTION= --gtest_catch_exceptions=0 
GOOGLETEST_FILTER= --gtest_filter=*.*
.SILENT=all clean

all: 
	@echo "<======================Buiing Image=====================>"
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@echo "<======================Running Test=====================>"
	@$(BUILD)/$(TARGET) $(GOOGLETEST_OPTION)
	@$(BUILD)/$(TARGET) $(GOOGLETEST_FILTER)

clean:
	@-rm -rf $(BUILD)