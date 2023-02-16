// add.c
#include <stdio.h>

int global;

void foo(void)
{
  printf("global: %d\n", global);
}