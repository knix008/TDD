TARGET= Test
BUILD= Build
.SILENT=all clean
CPPUTEST_OPTION= -c -v

all: 
	@echo "<======================Buiing Image=====================>"
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@echo "<====================Running CppUTest===================>"
	@$(BUILD)/$(TARGET) $(CPPUTEST_OPTION)

clean:
	@-rm -rf $(BUILD)