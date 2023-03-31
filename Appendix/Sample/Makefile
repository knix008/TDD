TARGET= main
CC= g++
FLAGS= -Wall --coverage -g -O0
SRCS= main.cpp

all: 
	@$(CC) $(FLAGS) -o $(TARGET) $(SRCS)

clean:
	@-rm $(TARGET)
	@-rm $(TARGET).gcno
	@-rm -rf $(TARGET).dSYM