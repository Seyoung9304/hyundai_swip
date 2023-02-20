// 10_포인터16.c
#include <stdio.h>

// int*
// char*

// *p;   <- 몇 바이트를 읽을지?
// p+1;  <- 얼마나 이동할지?
// 1. 포인터의 대상체 타입에 따라 연산이 수행됩니다.

// 2. void*는 대상체의 타입 정보가 존재하지 않습니다.
// => 연산을 수행할 수 없습니다.
// * 참조 연산 불가능.
// +, - 연산 불가능.

// 3. void*는 타입에 상관없이 주소를 저장하기 위한 용도로만 사용합니다.
#if 0
int main(void)
{
  void *p = NULL;

  int a = 42;
  char c = 'A';
  double d = 3.14;

  p = &a; /* OK */
  p = &c; /* OK */
  p = &d; /* OK */

  // *p = 42; /* ERROR */
  // p++;     /* ERROR */

  return 0;
}
#endif

int main(void)
{
  int n = 100;

  void *p = &n;
  // int*에서 void*로의 암묵적인 변환이 허용됩니다.

  int *pn = (int *)p;
  // void*에서 int*로의 암묵적인 변환이 허용됩니다.
  // => C에서는 허용되지만, C++은 허용되지 않습니다.
  //    명시적인 캐스팅이 필요합니다.

  printf("%d\n", *(int *)p);
  printf("%d\n", *pn);

  return 0;
}
