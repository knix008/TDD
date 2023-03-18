TARGET= WriteSample
CC= g++
CXXFLAGS= -Wall -std=c++0x
SRCS= main.cpp

all: $(SRCS)
	@echo "Building..."
	@$(CC) $(CXXFLAGS) -o $(TARGET) $(SRCS)
	@./$(TARGET)

clean:
	@rm $(TARGET)