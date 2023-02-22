// 10_포인터7.c

#include <stdio.h>

// 문제점
// - 지역 변수의 주소를 반환하면 안됩니다.

#if 0
int *foo(void)
{
  static int p = 10;
  return &p;
}

int main(void)
{
  int *p = foo();
  printf("%d\n", *p);

  return 0;
}
#endif

#if 0
int *foo(void)
{
  static int x[3] = {10, 20, 30};
  return x;
}

int main(void)
{
  int *p = foo();
  printf("%d\n", p[0]);
  printf("%d\n", p[1]);
  printf("%d\n", p[2]);

  return 0;
}
#endif

typedef int ARR2[2];

// int (*foo(void))[2]
ARR2 *foo(void)
{
  static int x[3][2] = {10, 20, 30, 40, 50, 60};
  return x;
  // int(*)[2]
}

int main(void)
{
  // int(*p)[2] = foo();
  ARR2 *p = foo();
  printf("%d\n", p[0][0]);
  printf("%d\n", p[1][1]);
  printf("%d\n", p[2][0]);
}

// int (*foo(void))[2]

//           foo(void): foo는 인자 없는 함수입니다. 반환 타입은?
//        (*foo(void)): 포인터 타입입니다. 포인터가 가르키는 타입은?
//     (*foo(void))[2]: 2개짜리 배열입니다. 배열의 원소 타입은?
// int (*foo(void))[2]: int 입니다.