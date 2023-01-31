TARGET=LedDriverTest

SRC=LedDriverTest.c \
    ../Src/LedDriver.c

UNITY=../../../CUnity/unity.c \
      ../../../CUnity/extras/fixture/src/unity_fixture.c \
      ../../../CUnity/extras/memory/src/unity_memory.c

INCLUDES=-I../../../CUnity \
         -I../../../CUnity/extras/fixture/src \
         -I../../../CUnity/extras/memory/src \
		 -I../Src 

CC=gcc
OBJS= unity.o unity_fixture.o unity_memory.o

all: $(SRC) $(OBJS)
	@echo "Compiling LedDriverTest.c..."
	@$(CC) -o $(TARGET) $(CFLAG) $(SRC) $(OBJS) $(INCLUDES)
	@echo "Running LedDriverTest..."
	@./$(TARGET)

$(OBJS): $(UNITY)
	@$(CC) -c $(UNITY) $(INCLUDES)

clean:
	@rm -rf $(OBJS)
	@rm $(TARGET)