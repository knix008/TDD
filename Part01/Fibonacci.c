#include <stdio.h>

fibonacci(unsigned int n) {
    if ((n == 0)||(n == 1)){
        return n;
    }
    return fibonacci(n - 2) + (n -1 );
}

int main() {
    unsigned int result = fibonacci(20);
    printf("The fibonacci number : %d.\n", result);
}