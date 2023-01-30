SRC= sprintf_cpputest.cpp
TARGET= sprintf_cpputest

all: $(SRC)
	@echo "Compile & linking the test executable."
	g++ -o $(TARGET) $(SRC) -I/usr/include/CppUTest /usr/lib/x86_64-linux-gnu/libCppUTest.a
	@echo "Running the test."
	./$(TARGET)
clean:
	@rm $(TARGET)