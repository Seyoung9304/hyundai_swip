// 10_포인터14.c

#include <stdio.h>

#if 0
int main(void)
{
  const int n = 10;
  int x = 100;

  int *p = &n;
  *p = 100; /* 미정의 동작 */

  return 0;
}
#endif

// > 포인터 변수에 대한 const는

//   const int *p1;
//   int const *p2;
//  > 포인터 변수가 가르키는 대상체를 수정하지 않겠다.
//  p  ----> <n>

//  int *const p3;
//  > 포인터 변수를 다른 주소로 변경할 수 없습니다.
// <p> ---->  n

// const int *const p4;
// int const *const p5;
// <p> ----> <n>
int main(void)
{
  int n = 100;
  int x = 100;

  const int *p1 = &n;
  int const *p2 = &n;
  // *p1 = 200; /* 에러 */
  // *p2 = 200; /* 에러 */
  p1 = &x; /* OK */
  p2 = &x; /* OK */

  int *const p3 = &n;
  *p3 = 10000; /* OK */
  // p3 = &x;     /* 에러 */

  const int *const p4;
  int const *const p5;

  return 0;
}