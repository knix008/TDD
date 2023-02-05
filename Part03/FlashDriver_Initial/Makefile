TARGET= flashdrivertest

SRCS= FlashDriver.cpp \
      IO.cpp \
      FlashDriverTest.cpp

INCLUDE_FILES= FlashDriver.hpp \
               IO.hpp

CC= g++
CFLAGS= -Wall
INCLUDES= -I/usr/include/CppUTest
LIBS= /usr/lib/x86_64-linux-gnu/libCppUTest.a
CPPUTESTRUNTIME_OPTION= -c
.SILENT: $(TARGET) clean

$(TARGET): $(SRCS) $(INCLUDE_FILES)
	@echo "Building $(TARGET)..."
	@$(CC) -o $(TARGET) $(CFLAGS) $(SRCS) $(INCLUDES) $(LIBS)
	@echo "Running $(TARGET)..."
	@./$(TARGET) $(CPPUTESTRUNTIME_OPTION) 

clean:
	@rm $(TARGET)