// 10_포인터12.c
#include <stdio.h>

// 1. 배열은 일반 변수와 함수 인자 전달방식이 다릅니다.
// 2. 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석됩니다.
//    => Decay
//     예외
//     1) sizeof
//     2) &

// 3. 함수가 배열의 시작 주소를 전달받는 경우, 함수 안에서는 배열의 길이를 정확히
//    알 수 없습니다.
//    => 함수에 배열의 길이를 추가적인 인자로 전달받아야 합니다.

// void foo(int x[10], int n)
#if 0
void foo(int *x, int n)
{
  printf("%zu\n", sizeof(x));
  for (int i = 0; i < n; ++i)
  {
    x[i] = 10 * i;
  }
}

int main(void)
{
  int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  foo(x, 10);
  // foo(&x[0], 10);

  // x? => int[10]

  for (int i = 0; i < 10; ++i)
  {
    printf("%d\n", x[i]);
  }

  return 0;
}
#endif

// 4. 정수 0은 포인터 타입으로의 암묵적인 변환을 허용합니다.
//   => NULL은 0이지만, 포인터 타입에 대해서 사용합니다.

// 5. 포인터를 사용할 때, 유효한 포인터인지 확인하고 사용하는 것이 좋습니다.
#if 0
int main(void)
{
  // int *p = 0;
  int *p = NULL;
  printf("%p\n", p);

  // if (p != NULL)
  if (p)
  {
    *p = 42;
  }

  return 0;
}
#endif

// 6.

void foo(int *px)
{
  for (int i = 0; i < 5; i++)
  {
    printf("%d\n", px[i]);
  }
}

// 6. 포인터 + 정수
//   : 포인터 + 정수 * sizeof(대상체 크기)
#if 0
int main(void)
{
  char *px = NULL;

  printf("%p\n", px + 0);
  printf("%p\n", px + 1);
  printf("%p\n", px + 2);
  printf("%p\n", px + 3);
}
#endif

//      px   px+1  px+2  px+3  px+4
// x: { 1,    2,    3,    4,    5 };

// x[0] => *(x + 0)
// x[1] => *(x + 1)

// x => &x[0] => &*(x + 0) => x + 0 => x
//               &*: 상쇄

#if 0
int main(void)
{
  int x[5] = {1, 2, 3, 4, 5};

  // foo(x); // px = x;, px = &x[0]
  int *px = x; // &x[0]

  printf("%d\n", px[0]);
  printf("%d\n", px[1]);
  printf("%d\n", px[2]);

  printf("%d\n", *(px + 0));
  printf("%d\n", *(px + 1));
  printf("%d\n", *(px + 2));

  return 0;
}
#endif

#if 0
int main(void)
{
  //            px
  int x[5] = {1, 2, 3, 4, 5};

  // int *px = &x[1]; // &*(x + 1)
  int *px = x + 1;
  printf("%d\n", *(px - 1));
  printf("%d\n", *(px + -1));
  printf("%d\n", px[-1]);

  return 0;
}
#endif

// Big Endian
//  - [0x12 0x34 0x56 0x78] => Network

// Little Endian
//  - [0x78 0x56 0x34 0x12]

#if 0
int main(void)
{
  int n = 0x12345678;
  char *p = (char *)&n;

  printf("%x\n", p[0]);
  printf("%x\n", p[1]);
  printf("%x\n", p[2]);
  printf("%x\n", p[3]);

  return 0;
}
#endif

#if 0
int main(void)
{
  int n = 10;
  double *p = (double *)&n;

  *p = 3.14; /* 미정의 동작 */

  return 0;
}
#endif

#if 0
int main(void)
{
  int x[3] = {10, 20, 30};

  printf("%p\n", x);  // &x[0] -> int*
  printf("%p\n", &x); // int(*)[3]

  int *p1 = NULL;
  int(*p2)[3] = NULL;

  printf("%p\n", p1 + 1); // 4
  printf("%p\n", p2 + 1); // 12

  p1 = x;                         // &x[0]
  printf("%zu\n", sizeof(&x[0])); // ?
  printf("%zu\n", sizeof(x));

  return 0;
}
#endif

#if 0
int main(void)
{
  int x[2][3];
  // [ int[3] ][ int[3] ]
  // p        p+1

  int(*p)[3];
  p = x;

  return 0;
}
#endif

#if 0
int main(void)
{
  int a, b;

  // int* p1, p2;
  // p1: int*
  // p2: int

  // int *p1, *p2;
  // p1: int*
  // p2: int*
  int *p1;
  int *p2;

  printf("%zu\n", sizeof(p1));
  printf("%zu\n", sizeof(p2));

  return 0;
}
#endif

#if 0
void print_x(int *x, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", x[i]);
  }
}
#endif

void print_x(int (*x)[3], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      printf("%d\n", x[i][j]);
    }
  }
}

int main(void)
{
  int x[2][3] = {1, 2, 3, 4, 5, 6};
  // print_x((int *)x, 6);
  print_x(x, 2);

  return 0;
}