// 13_구조체9.c
#include <stdio.h>

// 1. C언어 타입
//   - built-in type(내장 타입)
//    int, char, double, float ...

//   - user defined type(사용자 정의 타입)
//    1) struct(구조체)
//    2) union(공용체)
//    3) enum(열거체)

// 2. struct
/* 구조체 태그 */
struct complex
{
  // 멤버 데이터 변수
  int re; /* 실수부 */
  int im; /* 허수부 */
};

int main(void)
{
  struct complex c1;

  // . 연사자를 통해 멤버 데이터에 접근할수 있습니다.
  c1.re = 10;
  c1.im = 24;

  printf("%d %d\n", c1.re, c1.im);

  return 0;
}
