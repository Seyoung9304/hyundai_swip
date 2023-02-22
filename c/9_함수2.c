// 8_함수2.c

#include <stdio.h>

#if 0
// 함수 정의
void foo(void)
{
}

// 함수 정의
void goo(void)
{
}

int main(void)
{
  foo();
  goo();
}
#endif

#if 0
// 함수 선언 / 함수 프로토타입 선언
// => 헤더파일을 통해 제공되는 경우가 많습니다.
void foo(void);
void goo(void);

int main(void)
{
  foo();
  goo();
}

// 함수 정의
void foo(void)
{
}

// 함수 정의
void goo(void)
{
}

#endif

int add(int a, int b); // 1 <-- 권장합니다.
int add(int, int);     // 2

int main(void)
{
}

int add(int a, int b)
{
  return a + b;
}
