#include <stdio.h>

// 1. 모든 변수는 메모리에 저장되고,
//    주소를 가집니다.
// 2. 포인터 변수는 주소를 저장할 수 있는 변수입니다.
// 3. 포인터 변수의 크기는 8바이트 입니다.
// 4. 포인터 변수는 변수의 주소를 저장함으로써
//    가르키는 변수(대상체)의 값을 읽거나 변경할 수 있습니다.

// 5. 배열의 이름은 배열의 첫번째 원소의 시작주소로 해석됩니다.
//   => Decay
//    예외) sizeof, &

// 6. 배열의 길이 정보를 알 수 없기 때문에, 배열의 길이를 추가적으로
//    전달해야 합니다.

// void foo(int x[3])
// void foo(int x[])
#if 0
void foo(int *x)
{
  printf("%zu\n", sizeof(x));
}

int main(void)
{
  int x[3]; // x: int[3]           : 실제 타입
  //           x -> decay -> &x[0] : Decay 경우

  foo(x);
  printf("%zu\n", sizeof(x));

  return 0;
}
#endif

// p -----> int[3]
#if 0
void foo(int (*p)[3])
{
  printf("%zu\n", sizeof(p));                   // 8
  printf("%d\n", sizeof(*p) / sizeof((*p)[0])); // 3
}

int main(void)
{
  int x[3];
  foo(&x); // &int[3]

  return 0;
}
#endif

void foo1(int *x, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d\n", x[i]);
}

void foo2(int (*x)[3])
{
  for (int i = 0; i < 3; i++)
    printf("%d\n", (*x)[i]);
}

int main(void)
{
  int x[3] = {10, 20, 30};
  foo1(x, 3);
  foo2(&x);

  return 0;
}