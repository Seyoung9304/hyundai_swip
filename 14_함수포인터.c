// 14_함수포인터.c
#include <stdio.h>

// int  n;       : int
// int* p;       : p -------> int

// int x[3];     : int[3]
// int (*p)[3]   : p -------> int[3]

// int add(int a, int b) : int(int a, int b)
// int (*p)(int a, int b) : p -------> int(int, int)

// 함수의 타입은 함수의 시그니처(함수의 인자 타입과 반환 타입)에 의해 결정됩니다.
int add(int a, int b)
{
  return a + b;
}

int sub(int a, int b)
{
  return a - b;
}

// 함수 포인터는 왜 사용하는가?
//  > 실행시간에 어떤 함수를 호출할지 결정할 수 있습니다.
int main(void)
{
  int (*fp)(int, int);

  fp = &add;
  int result = (*fp)(10, 20);
  printf("result: %d\n", result);
  printf("%p\n", fp);

  fp = &sub;
  result = (*fp)(10, 20);
  printf("result: %d\n", result);
  printf("%p\n", fp);

  return 0;
}

// int (*fp)(int, int);
//               (*fp): fp는 포인터입니다. 포인터가 가르키는 타입은?
//     (*fp)(int, int): int인자 2개 받는 함수입니다. 함수의 반환타입은?
// int (*fp)(int, int): int 입니다.