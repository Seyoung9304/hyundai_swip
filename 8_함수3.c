// 8_함수3.c
#include <stdio.h>

// 재귀 함수(Recursive Function)
//  정의: 자기 자신을 다시 호출하는 함수

//  재귀 함수는 재귀적인 호출이 무한정되지 않도록
//  종료 조건을 설정하는 것이 중요합니다.
#if 0
void foo(void)
{
  foo();
}

int main(void)
{
  foo();
  return 0;
}
#endif

#if 0
void print_hello(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("hello\n");
  }
}
#endif
#if 0
void print_hello(int n)
{
  if (n <= 0)
  {
    return;
  }

  printf("hello\n");
  print_hello(n - 1);
}

// print_hello(3)
//   "hello"
//   print_hello(2)
//     "hello"
//     print_hello(1)
//        "hello"
//        print_hello(0)

int main(void)
{
  print_hello(3);

  return 0;
}
#endif

// 점화식
//  => 피보나치 수열
/*
f(0) = 0
f(1) = 1
f(n) = f(n-1) + f(n-2)
*/

// 재귀 함수의 장점
// => 알고리즘에 직관적인 코드를 만들 수 있습니다.
//  : 가독성

// 재귀 함수의 단점
// => 함수 호출의 오버헤드가 중첩되는 현상이 있습니다.
//   스택의 제한된 크기안에서 함수의 중첩이 무한정
//   수행될 수 없습니다.

int fib(int n)
{
  if (n == 0)
    return 0;

  if (n == 1)
    return 1;

  return fib(n - 1) + fib(n - 2);
}

int main(void)
{
  int result = fib(10);
  printf("%d\n", result);

  return 0;
}