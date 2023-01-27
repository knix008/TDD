TARGET = sprintf_test

all: sprintf_test.o 
	gcc -o $(TARGET) sprintf_test.o unity.o unity_fixture.o unity_memory.o
 
sprintf_test.o: sprintf_test.c unity.o unity_fixture.o unity_memory.o
	gcc -c -o sprintf_test.o sprintf_test.c -I../../CUnity -I../../CUnity/extras/fixture/src -I../../CUnity/extras/memory/src

unity.o:
	gcc -c -o unity.o ../../CUnity/unity.c -I../../CUnity

unity_fixture.o:
	gcc -c -o unity_fixture.o ../../CUnity/extras/fixture/src/unity_fixture.c -I../../CUnity -I../../CUnity/extras/fixture/src -I../../CUnity/extras/memory/src

unity_memory.o:
	gcc -c -o unity_memory.o ../../CUnity/extras/memory/src/unity_memory.c -I../../CUnity -I../../CUnity/extras/memory/src
 
clean:
	@rm -rf *.o
	@rm $(TARGET)