TARGET= WriteSampleTest
CC= g++
CXXFLAGS= -Wall -std=c++0x
CPPUTEST_OPTION= -c

SRCS= testmain.cpp \
      WriteSample.cpp \
	  WriteSampleTest.cpp 

INCS= WriteSample.h

# For Apple MacOS
# LIBS= -lcpputest 

# For x86_64 Ubuntu
LIBS=-lCppUTest -lCppUTestExt

all: $(SRCS) $(INCS)
	@echo "Building..."
	@$(CC) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LIBS)
	@./$(TARGET) $(CPPUTEST_OPTION)

clean:
	@rm $(TARGET)