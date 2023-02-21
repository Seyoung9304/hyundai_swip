// 13_구조체2.c
#include <stdio.h>

#if 0
//     <구조체 태그>
struct AAA
{
  int a;
};

struct BBB
{
  int a;
};

// 1. 동일한 사용자 정의 타입을 여러개 정의할 수 없습니다.
// 2. 구조체 태그가 다르면 다른 타입입니다.
int main(void)
{
  struct AAA a;
  struct BBB b;

  a = b; // 에러!
  b = a; // 에러!

  return 0;
}
#endif

// 1.
struct point1
{
  int x;
  int y;
};
typedef struct point1 POINT1;

// 2.
typedef struct point2
{
  int x;
  int y;
} POINT2;

// 3. 태그를 생략 가능합니다.
typedef struct
{
  int x;
  int y;
} POINT3;

int main(void)
{
  struct point2 pt3;
  POINT2 pt4;

  struct point1 pt1;
  POINT1 pt2;

  return 0;
}