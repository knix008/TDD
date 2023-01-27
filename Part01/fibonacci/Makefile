fibonacci: fibonacci_test.o fibonacci.o
	gcc -o fibonacci fibonacci_test.o fibonacci.o unity.o
 
fibonacci_test.o: fibonacci_test.c unity.o
	gcc -c -o fibonacci_test.o fibonacci_test.c -I../../CUnity

unity.o:
	gcc -c -o unity.o ../../CUnity/unity.c -I../../CUnity
 
fibonacci.o : fibonacci.c fibonacci.h
	gcc -c -o fibonacci.o fibonacci.c

clean:
	@rm -rf *.o
	@rm fibonacci