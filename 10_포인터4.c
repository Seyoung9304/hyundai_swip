// 10_포인터4.c
// => 배열과 포인터

#include <stdio.h>

// x의 타입은 무엇입니까?
#if 0
int main(void)
{
  int x[3] = {10, 20, 30};
  // [ int ][ int ][ int ]

  // int *p = &x[0];
  int *p = x;
  // *(p + 0) = 30;
  // *(p + 1) = 40;
  // *(p + 2) = 50;
  p[0] = 30;
  p[1] = 40;
  p[2] = 50;

  // 배열의 이름은 배열의 첫번째 원소의 시작 주소로
  // 해석됩니다. => Decay
  //  - 예외 2가지
  //   1) sizeof

  x[0] = 30;
  x[1] = 40;
  x[2] = 50;

  return 0;
}
#endif

int main(void)
{
  int x[3] = {10, 20, 30};
  *(x + 2) = 100;

  printf("%d\n", x[2]);

  // *(x + 1) => x[1]
  // *(1 + x) => 1[x] - 원리만 보세요!
  // printf("%d\n", 1 [x]);

  return 0;
}
