TARGET= WriteSampleTest
CC= g++
CXXFLAGS= -Wall -std=c++0x
SRCS= testmain.cpp \
      WriteSample.cpp \
	  WriteSampleTest.cpp 

INCS= WriteSample.h

LIBS= -lcpputest

all: $(SRCS) $(INCS)
	@echo "Building..."
	@$(CC) $(CXXFLAGS) -o $(TARGET) $(SRCS) $(LIBS)
	@./$(TARGET)

clean:
	@rm $(TARGET)