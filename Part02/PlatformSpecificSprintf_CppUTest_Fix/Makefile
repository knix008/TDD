TARGET= platformspecificsprintf
SRC= Sprintf.c \
     SprintfTest.cpp

CC= g++
CFLAGS= -Wall
INCLUDES= -I/usr/include/CppUTest
LIBS = /usr/lib/x86_64-linux-gnu/libCppUTest.a

$(TARGET): $(SRC)
	@echo "Building $(TARGET)..."
	$(CC) -o $(TARGET) $(CFLAGS) $(SRC) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

clean:
	@rm *.o
	@rm $(TARGET)