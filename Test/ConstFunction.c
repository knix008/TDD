#include <stdio.h>

int fun(int y) __attribute__((const));
/* void fun(int y) __attribute__((pure)); */
int x = 1;

int fun(int y)
{
  x = y;
  return x;
}

void normal(int y)
{
    x = y;
}

void main()
{
    fun(100);
    printf("The X variable : %d\n", x);
    normal(100);
    printf("The X variable : %d\n", x);
}
