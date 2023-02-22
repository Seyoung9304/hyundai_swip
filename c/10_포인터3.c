// 10_포인터3.c
#include <stdio.h>
#if 0
// 1. 포인터 변수의 크기는 8바이트 입니다. (64비트 기준)


int main(void)
{
  int n = 10;      // 4
  char c = 'A';    // 1
  double d = 3.14; // 8

  // 2. 포인터의 타입에 따라서 가르키는 대상체의 접근할 수 있는 크기가
  //    결정됩니다.
  int *pn = &n;
  char *pc = &c;
  double *pd = &d;

  printf("%zu\n", sizeof(pn));
  printf("%zu\n", sizeof(pc));
  printf("%zu\n", sizeof(pd));

  *pn = 42;
  *pc = 'X';
  *pd = 5.5;

  return 0;
}
#endif

// 포인터 연산
//  1) 포인터 + 정수
//  int* p;
//  p+1
//  => p의 현재 주소값 + (sizeof(int) * 1)

//  double* p;
//  p+1
//  => p의 현재 주소값 + (sizeof(double) * 1)

// 2) 포인터 + 포인터
//  => 불가능합니다.

// 3) 포인터 - 포인터
//  => 가능합니다.

int main(void)
{
  // int *p = 0; // 아무것도 가르키고 있지 않다.
  double *p = NULL;

  printf("%d\n", p);
  printf("%d\n", p + 1);

  return 0;
}