TARGET= Test
BUILD= Build
GOOGLETEST_OPTION= --gtest_catch_exceptions=0
GOOGLETEST_FILTER= --gtest_filter=*.*

all: 
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@$(BUILD)/$(TARGET) $(GOOGLETEST_OPTION) $(GOOGLETEST_FILTER)

clean:
	@-rm -rf $(BUILD)