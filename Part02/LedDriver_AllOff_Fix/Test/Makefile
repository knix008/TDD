TARGET=LedDriverTest
CC=gcc
CFLAGS= -Wall

SRCS=LedDriverTest.c \
    ../Src/LedDriver.c

UTIL_DIR=../../../Util
UTIL=$(UTIL_DIR)/RuntimeErrorStub.c

UNITY_DIR=../../../CUnity
UNITY=$(UNITY_DIR)/unity.c \
      $(UNITY_DIR)/extras/fixture/src/unity_fixture.c \
      $(UNITY_DIR)/extras/memory/src/unity_memory.c

INCLUDES=-I$(UNITY_DIR) \
         -I$(UNITY_DIR)/extras/fixture/src \
         -I$(UNITY_DIR)/extras/memory/src \
         -I$(UTIL_DIR) \
		 -I../Src

OBJS= unity.o unity_fixture.o unity_memory.o

.SILENT: $(TARGET) clean

$(TARGET): $(SRCS) $(OBJS)
	@echo "Compiling $(TARGET).c..."
	@$(CC) -o $@ $(CFLAGS) $(SRCS) $(UTIL) $(OBJS) $(INCLUDES)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

$(OBJS): $(UNITY)
	@$(CC) -c $(UNITY) $(INCLUDES)

clean:
	@rm -rf $(OBJS)
	@rm $(TARGET)