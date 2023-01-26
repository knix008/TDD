#include <stdio.h>

unsigned int fibonacci(unsigned int n) {
    unsigned int ret;

    if ((n == 0)||(n == 1)){
        printf("Index : %d, result : %d\n", n, n);
        return n;
    }
    ret = fibonacci(n - 2) + fibonacci(n - 1);
    printf("Index : %d, result : %d\n", n, ret);
    return ret;
}

int main() {
    unsigned int result = fibonacci(10);
    printf("The fibonacci number : %d.\n", result);
}