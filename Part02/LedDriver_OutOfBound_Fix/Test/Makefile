TARGET=LedDriverTest
CC=gcc

SRCS=LedDriverTest.c \
    ../Src/LedDriver.c

UNITY=../../../CUnity/unity.c \
      ../../../CUnity/extras/fixture/src/unity_fixture.c \
      ../../../CUnity/extras/memory/src/unity_memory.c
INCLUDES=-I../../../CUnity \
         -I../../../CUnity/extras/fixture/src \
         -I../../../CUnity/extras/memory/src \
		 -I../Src 
OBJS= unity.o unity_fixture.o unity_memory.o

all: $(SRCS) $(OBJS)
	@echo "Compiling $(TARGET).c..."
	@$(CC) -o $(TARGET) $(CFLAG) $(SRCS) $(OBJS) $(INCLUDES)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

$(OBJS): $(UNITY)
	@$(CC) -c $(UNITY) $(INCLUDES)

clean:
	@rm -rf $(OBJS)
	@rm $(TARGET)