TARGET=LedDriverTest
SRC=LedDriverTest.c \
    ../Src/LedDriver.c
INCLUDES=-I../../../CUnity \
         -I../../../CUnity/extras/fixture/src \
         -I../../../CUnity/extras/memory/src \
		 -I../Src 

all: $(SRC) unity.o unity_fixture.o unity_memory.o
	@echo "Compiling the test..."
	gcc -o $(TARGET) $(SRC) unity.o unity_fixture.o unity_memory.o $(INCLUDES)
	@echo "Running the test..."
	@./$(TARGET)
 
unity.o:
	@gcc -c -o unity.o ../../../CUnity/unity.c $(INCLUDES)

unity_fixture.o:
	@gcc -c -o unity_fixture.o ../../../CUnity/extras/fixture/src/unity_fixture.c $(INCLUDES)

unity_memory.o:
	@gcc -c -o unity_memory.o ../../../CUnity/extras/memory/src/unity_memory.c $(INCLUDES)
 
clean:
	@rm -rf *.o
	@rm $(TARGET)