// 10_포인터5.c
#include <stdio.h>

#if 0
int main(void)
{
  int x[3] = {10, 20, 30};

  for (int i = 0; i < 3; i++)
  {
    printf("%d\n", x[i]);
  }

  return 0;
}
#endif

#if 0
// 함수에서는 배열의 길이를 알 수 없습니다.
// 배열을 전달하는 함수를 설계할 때, 배열의 길이 정보를
// 추가적으로 전달해야 합니다.
void print_array(int *p, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", p[i]);
  }
}

int main(void)
{
  int x[10] = {10, 20, 30};

  print_array(x, 10);

  return 0;
}
#endif

#if 0
int main(void)
{
  int a[3];
  // [ int ][ int ][ int ]

  int *pa = a;

  int x[3][5];
  // 길이는? 3
  // [ int[5] ][ int[5] ][ int[5] ]

  // int (*p)[5];

  // int *p[5]; => 포인터 배열
  //  [int*][int*][int*][int*][int*]

  int(*p)[5]; // => 배열 포인터
  p = x;

  // p -----> int[5]

  return 0;
}
#endif

void foo(void) {}
// foo의 타입은 무엇인가요?
//  => void foo(void);

// - 배열 포인터
// int(*p)[5]
//       (*p): p는 포인터 타입입니다. 가르키는 대상체의 타입은?
//    (*p)[5]: 5개짜리 배열입니다. 배열의 원소타입은?
// int(*p)[5]: int 입니다.

// - 포인터 배열
// int *p[5];
//      p[5]: p는 5개짜리 배열입니다. 배열의 원소타입은?
//     *p[5]: 포인터 타입입니다. 가르키는 대상체의 타입은?
// int *p[5]: int 입니다.

// Decay: 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석된다.
// 예외
//  1) sizeof
//  2) &

void foo(void) {}
// void(void)

#if 0
int main(void)
{
  int a;
  int *pa = &a;

  char c;
  char *pc = &c;

  typedef int ARR3[3];
  int x[3];
  int(*px)[3] = &x;

  ARR3 x2;
  ARR3 *px2 = &x2;

  void (*fp)(void) = &foo;

  return 0;
}
#endif

// p ---> [[][][][]]
// px -----> [ [ 10 ][ 20 ][ 30 ] ]
int main(void)
{
  int n = 100;
  int *p = &n;
  *p = 20;

  int x[3] = {10, 20, 30};
  int(*px)[3] = &x;

  (*px)[1] = 100;

  return 0;
}