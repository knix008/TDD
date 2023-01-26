#include <stdio.h>
#include "fibonacci.h"

unsigned int fibonacci(unsigned int n) {
    unsigned int ret;

    if ((n == 0)||(n == 1)){
        printf("Index : %d, result : %d.\n", n, n);
        return n;
    }
    ret = fibonacci(n - 2) + fibonacci(n - 1);
    printf("Index : %d, result : %d.\n", n, ret);
    return ret;
}