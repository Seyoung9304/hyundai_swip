// add.c
#include <stdio.h>

#include "add.h"

// 선언
// extern int global;
// extern int internal_global;

// 정의
void foo(void)
{
  goo();

  printf("global: %d\n", global);
  // printf("internal_global: %d\n", internal_global);
}

void goo(void)
{
  foo();
}
