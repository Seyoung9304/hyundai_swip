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

#define TRUE 1
#define FALSE 0
typedef int BOOL;

// c99 => bool 타입이 도입되었습니다.

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