TARGET= test
BUILD= build

all: 
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@$(BUILD)/$(TARGET)

clean:
	@rm -rf $(BUILD)
