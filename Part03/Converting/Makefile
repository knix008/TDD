TARGET= platformspecificsprintf

SRCS=./SprintfTest.c \
     ./Sprintf.c

RUNTIME=../../Util/RuntimeErrorStub.c

CC=gcc
CFLAGS= -Wall

UNITY=../../CUnity/unity.c \
      ../../CUnity/extras/fixture/src/unity_fixture.c \
      ../../CUnity/extras/memory/src/unity_memory.c

INCLUDES=-I../../CUnity \
         -I../../CUnity/extras/fixture/src \
         -I../../CUnity/extras/memory/src \
         -I../../Util

OBJS= unity.o unity_fixture.o unity_memory.o

$(TARGET): $(SRCS) $(OBJS)
	@echo "Compiling $(TARGET).c..."
	@$(CC) -o $@ $(CFLAGS) $(SRCS) $(RUNTIME) $(OBJS) $(INCLUDES)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

$(OBJS): $(UNITY)
	@$(CC) -c $(UNITY) $(INCLUDES)

clean:
	@rm -rf $(OBJS)
	@rm $(TARGET)