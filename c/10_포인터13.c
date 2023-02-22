// 10_포인터13.c

#include <stdio.h>

#if 0
// 함수에서 지역 변수의 메모리를 반환하면 안됩니다.
int *foo(void)
{
  int n = 100;
  return &n;
}

int main(void)
{
  int *p = foo();
  *p = 1000;          /* 미정의 동작 */
  printf("%d\n", *p); /* 미정의 동작 */

  return 0;
}
#endif

int *foo(void)
{
  static int n = 100;
  return &n;
}

int *goo(void)
{
  static int x[3] = {10, 20, 30};
  return x;
}

typedef int ARR3[3];

// int (*hoo(void))[3]
ARR3 *hoo(void)
{
  static int x[2][3] = {10, 20, 30, 40, 50, 60};
  return x;
  // int(*)[3]
}

int add(int a, int b) { return a + b; }

typedef int (*FP)(int, int);
// int (*koo(void))(int, int)
FP koo(void)
{
  return &add;
}

int main(void)
{
  printf("%p\n", &add);

  //  add: int(int, int)
  // &add: int(*)(int, int)

  int *p = foo();
  *p = 1000;
  printf("%d\n", *p);

  p = goo();
  p[0] = 100;
  p[2] = 200;
  printf("%d %d\n", p[0], p[2]);

  return 0;
}