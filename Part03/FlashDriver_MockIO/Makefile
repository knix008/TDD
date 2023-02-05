TARGET= flashdrivertest

IO_HOME=../../IO
CPPUMOCK_HOME=../../Mocks

SRCS= FlashDriver.cpp \
      $(CPPUMOCK_HOME)/MockIO.c \
      FlashDriverTest.cpp

INCLUDE_FILES= FlashDriver.hpp \
               $(CPPUMOCK_HOME)/MockIO.h

CC= g++
CFLAGS= -Wall -Wno-write-strings
INCLUDES= -I/usr/include/CppUTest \
          -I$(IO_HOME) \
          -I$(CPPUMOCK_HOME)

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