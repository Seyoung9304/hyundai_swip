// 5_연산자.c
#include <stdio.h>

// 1. ++, --
//  prefix / postfix의 동작을 구분해서 이해하는 것이 중요합니다.
#if 0
int main(void)
{
  int a = 0;
  int b = 0;

  int c = ++a + b++;
  printf("%d %d %d\n", a, b, c);

  ++a;
  ++b;

  return 0;
}
#endif

#if 0
int main(void)
{
  int a = 0;
  int result = ++a + ++a; /* 미정의 동작 */

  printf("result: %d\n", result);

  return 0;
}
#endif

#if 0
#include <stdio.h>

int main(void)
{
  int a = 0; // ??/
  ++a;

  printf("%d\n", a);
  return 0;
}
#endif

// 2. 논리 연산자
//   결과
//   - 0: 거짓
//   - 1: 참

//   판단
//   - 0: 거짓
//   - 0이 아닌값: 참
#if 0
#define TRUE 1
#define FALSE 0
typedef int BOOL;

// c99 => bool 타입이 도입되었습니다.
//     => 내장 타입이 아닌 typedef를 통해 제공되고 있습니다.
#include <stdbool.h>

int main(void)
{
  bool b = true;

  int a = 10;
  int b = 20;

  printf("%d\n", a > b);
  printf("%d\n", b > a);

  if (10 == a)
  {
    printf("hello\n");
  }

  return 0;
}
#endif

// 3. 논리 연산자
//   &&
//   ||
//  1) 단일 회로 성질
//   expr1 && expr2
//    : expr1이 거짓이면, expr2를 수행하지 않습니다.
//   expr1 || expr2
//    : expr1이 참이면, expr2를 수행하지 않습니다.

#if 0
int main(void)
{
  int a = 0;
  int b = 0;

  int c = ++a && b++;
  printf("%d %d %d\n", a, b, c);

  a = b = c = 0;
  c = a++ && ++b;
  printf("%d %d %d\n", a, b, c);

  a = b = c = 0;
  c = ++a || b++;
  printf("%d %d %d\n", a, b, c);

  return 0;
}
#endif

// 2) 연산자 우선순위
//  => &&, ||는 연산자 우선순위가 &&가 높습니다.
//   : 반드시 괄호를 사용해야 합니다.

//  => 연산자 우선순위는 결합을 결정합니다.
int main(void)
{
  int a, b, c;
  a = b = c = 0;

  int d = ++a || (b++ && ++c);
  printf("%d %d %d %d\n", a, b, c, d);
  // 1 0 0 1

  a = (b = (c = (d = 0)));

  d = --a && ++b || c++;
  printf("%d %d %d %d\n", a, b, c, d);
  // -1 1 0 1

  return 0;
}