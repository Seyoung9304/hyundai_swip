// 16_매크로.c
#include <stdio.h>

// 1) 매크로 상수
//  - 컴파일 이전에 전처리기에 의해서,
//    텍스트 치환됩니다.
#define PI 3.14
#define RADIUS 3

// int square(int x) { return x * x; }

// 2) 매크로 함수
// - 진짜 함수가 호출되는 것이 아니라,
//   인자로 받은 텍스트로 치환됩니다.
#define SQUARE(x) x *x

int main(void)
{
  printf("%d\n", SQUARE(10));

  // printf("%lf\n", PI);
  // printf("%d\n", RADIUS);

  return 0;
}