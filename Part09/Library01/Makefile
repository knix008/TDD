TARGET= test
BUILD= build

all: 
	@-mkdir $(BUILD)
	@cd $(BUILD) && cmake ..
	@make -C $(BUILD)
	@$(BUILD)/libraryTest/$(TARGET)

clean:
	@-rm -rf $(BUILD)
	@-rm test.dat
