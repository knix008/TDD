#include <stdio.h>

int constfunction(int y) __attribute__((const));
/* void fun(int y) __attribute__((pure)); */
int x = 1;

int constfunction(int y)
{
  x = y;
}

void normal(int y)
{
    x = y;
}

void main()
{
    constfunction(100);
    printf("Const Function - The X variable : %d\n", x);
    normal(100);
    printf("Normal Function - The X variable : %d\n", x);
}
