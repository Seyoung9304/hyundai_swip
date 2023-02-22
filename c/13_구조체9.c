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
#if 0
struct complex
{
  // 멤버 데이터 변수
  int re; /* 실수부 */
  int im; /* 허수부 */
};

int main(void)
{
  // 1) 구조체 변수를 만드는 방법
  struct complex c1;

  // 2) 구조체 멤버 데이터에 접근하는 방법 
  // . 연사자를 통해 멤버 데이터에 접근할수 있습니다.
  c1.re = 10;
  c1.im = 24;

  printf("%d %d\n", c1.re, c1.im);

  return 0;
}
#endif

// 3) 구조체 타입을 정의하는 방법.
struct complex1
{
  int re;
  int im;
};
typedef struct complex1 COMPLEX1;
typedef struct complex1 *PCOMPLEX1;

typedef struct complex2
{
  int re;
  int im;
} COMPLEX2;

typedef struct complex3
{
  int re;
  int im;
} COMPLEX3, *PCOMPLEX3;

typedef struct
{
  int re;
  int im;
} COMPLEX4, *PCOMPLEX4;

int main(void)
{
  typedef int a, *b;
  // a: int
  // b: int*

  struct complex1 c1;
  COMPLEX1 c2;

  return 0;
}
