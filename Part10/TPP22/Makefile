TARGET= Test
BUILD= Build
.SILENT=all clean
GOOGLETEST_OPTION= --gtest_catch_exceptions=0 --gtest_filter=*.*

all: 
	@echo "<======================Buiing Image=====================>"
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@echo "<====================Running CppUTest===================>"
	@$(BUILD)/$(TARGET) $(GOOGLETEST_OPTION)

clean:
	@-rm -rf $(BUILD)