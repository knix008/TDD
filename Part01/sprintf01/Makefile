TARGET = sprintf

${TARGET}: sprintf_test.o 
	gcc -o sprintf sprintf_test.o unity.o
 
sprintf_test.o: sprintf_test.c unity.o
	gcc -c -o sprintf_test.o sprintf_test.c -I../../CUnity

unity.o:
	gcc -c -o unity.o ../../CUnity/unity.c -I../../CUnity
 
clean:
	@rm -rf *.o
	@rm ${TARGET}