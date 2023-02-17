// 10_포인터10.c
#include <stdio.h>

#if 0
void swap(int a, int b)
{
  int temp = a;
  a = b;
  b = temp;
}

int main(void)
{
  int a = 10;
  int b = 20;

  swap(a, b);

  printf("%d %d\n", a, b);

  return 0;
}
#endif

#if 0
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main(void)
{
  int a = 10;
  int b = 20;

  swap(&a, &b);

  printf("%d %d\n", a, b);

  return 0;
}
#endif

// const 위치
//  1. * 기호의 앞에 있다면
//   pa1을 통해서 대상체를 수정할 수 없다.
//    const int *pa1 = &a;
//  pa1 -------> <a>

//    int const *pa2 = &a;
//  pa2 -------> <a>

//  2. * 기호의 뒤에 있다면
//    포인터 변수가 상수이므로, 다른 주소로 변경할 수 없습니다.
//  int *const pa3 = &a;
//    <pa3> -----> a

//
//   p -----> a
#if 0
int main(void)
{
  const int a = 10;
  int b = 20;

  const int *pa1 = &a;
  pa1 = &b; /* OK */
  // *pa1 = 1000; /* Error */

  int const *pa2 = &a;

  int *const pa3 = &a;
  *pa3 = 1000; /* OK */
  // pa3 = &b;    /* Error */

  const int *const pa4 = &a;
  int const *const pa5 = &a;

  return 0;
}
#endif

int main(void)
{
  int n = 10;
  n = 100;

  // p를 통해서 대상체를 수정하지 않겠다.
  const int *p = &n;
  // *p = 1000; /* Error */

  return 0;
}