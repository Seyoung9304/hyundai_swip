// 16_매크로2.c
#include <stdio.h>

#define SQUARE(x) (x) * (x)
// 1. 매크로 함수는 대문자로 표현하는 것이 일반적입니다.

// 2. 매크로 함수 문제점
//   1) 우선순위 문제
//       SQUARE(x+x)
//       => (x+x) * (x+x)

int main(void)
{
  int x = 10;
  printf("%d\n", SQUARE(x)); // 100
  printf("%d\n", SQUARE(x + x));

  return 0;
}