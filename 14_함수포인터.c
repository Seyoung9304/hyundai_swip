// 14_함수포인터.c
#include <stdio.h>

// int  n;       : int
// int* p;       : p -------> int

// int x[3];     : int[3]
// int (*p)[3]   : p -------> int[3]

// int add(int a, int b) : int(int a, int b)
// int (*p)(int a, int b) : p -------> int(int, int)

// 함수의 타입은 함수의 시그니처(함수의 인자 타입과 반환 타입)에 의해 결정됩니다.
#if 1
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

  int (*fp2)(int, int);

  // 함수 포인터에 주소를 담고, 호출하는 방법 2가지
  // 1) C++ 선호 스타일
  fp2 = &add;
  result = (*fp2)(10, 20);

  // 2) C 선호 스타일
  // 함수 - decay
  //  함수의 이름은 함수의 시작 주소로 해석됩니다.
  fp2 = add;
  result = fp2(10, 20);

  return 0;
}

// int (*fp)(int, int);
//               (*fp): fp는 포인터입니다. 포인터가 가르키는 타입은?
//     (*fp)(int, int): int인자 2개 받는 함수입니다. 함수의 반환타입은?
// int (*fp)(int, int): int 입니다.

#endif

int add(int a, int b)
{
  return a + b;
}

int sub(int a, int b)
{
  return a - b;
}

int calc(int a, int b, int (*fp)(int, int))
{
  return fp(a, b);
}

int main(void)
{
  int cmd;
  scanf("%d", &cmd);

  int result = calc(10, 20, (cmd == 0) ? add : sub);
  printf("result: %d\n", result);
}

#if 1
int main(void)
{
  int cmd;
  scanf("%d", &cmd);

  int result;
  if (cmd == 0)
  {
    result = add(10, 20);
    // call add
  }
  else
  {
    result = sub(10, 20);
    // call sub
  }

  printf("%d\n", result);

  return 0;
}
#endif