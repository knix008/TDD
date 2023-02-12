TARGET=flashdrivertest
CC=gcc
CFLAGS= -Wall
UNITY_DIR=../../CUnity
CMOCK_DIR=../CMock/src
MOCK_DIR=../Mock
IO_DIR=../../IO

SRCS=FlashDriverTest.c \
     FlashDriver.c

CMOCK_SRC=$(CMOCK_DIR)/cmock.c

MOCK_SRC=$(MOCK_DIR)/MockIO.c

UNITY_SRC=$(UNITY_DIR)/unity.c \
          $(UNITY_DIR)/extras/fixture/src/unity_fixture.c \
          $(UNITY_DIR)/extras/memory/src/unity_memory.c

INCLUDES=-I$(UNITY_DIR) \
         -I$(UNITY_DIR)/extras/fixture/src \
         -I$(UNITY_DIR)/extras/memory/src \
		 -I$(CMOCK_DIR) \
		 -I$(MOCK_DIR) \
		 -I$(IO_DIR)

UNITY_OBJS= unity.o unity_fixture.o unity_memory.o

$(TARGET): $(SRCS) $(UNITY_OBJS)
	@echo "Compiling $(TARGET).c..."
	@$(CC) -o $@ $(CFLAG) $(SRCS) $(CMOCK_SRC) $(MOCK_SRC) $(UNITY_OBJS) $(INCLUDES)
	@echo "Running $(TARGET)..."
	@./$(TARGET)

$(UNITY_OBJS): $(UNITY)
	@$(CC) -c $(UNITY_SRC) $(INCLUDES)

clean:
	@rm -rf $(UNITY_OBJS)
	@rm $(TARGET)