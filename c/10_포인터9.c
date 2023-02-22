// 10_포인터9.c
#include <stdio.h>

// 포인터 연산
// int* p;
// 1) p + 정수
//  => p + (sizeof(int) * 정수)

// 2) p[2] == *(p+2)

// int x[3];
// 3) x == &x[0] == &*(x + 0)
//    &* => 상쇄됩니다.

// 4) 포인터 - 정수
//  => p - (sizeof(int) * 정수)
#if 0
int main(void)
{
  //                   p
  int x[5] = {10, 20, 30, 40, 50};
  // x[-1]; /* 미정의 동작: 유효한 메모리에 대한 접근이 아닙니다. */

  // int* p = &x[2];
  //       &*(x + 2)
  int *p = x + 2;
  // printf("%d\n", *(p - 1));
  //              *(p + -1) => p[-1]
  printf("%d\n", p[-1]);

  return 0;
}
#endif

// 5) 포인터 - 포인터
//  => 같은 배열안에서의 포인터끼리만 가능합니다.
//    (p1 - p2) / sizeof(대상체 타입)
//  => 같은 배열안에서 상대적 위치를 구할 수 있습니다.

int main(void)
{
  //           p2                      p1
  int x[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

  int *p1 = x + 5;
  int *p2 = x;

  // %ld: long 타입
  printf("%ld\n", p1 - p2); // 5
  printf("%ld\n", p2 - p1); // -5

  return 0;
}