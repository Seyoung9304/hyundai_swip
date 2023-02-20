// 10_포인터11.c
#include <stdio.h>

// 포인터의 필요성
//  : 함수를 통해 전달된 인자의 값을 변경할 수 있습니다.
#if 0
void inc(int n)
{
  ++n;
}

int main(void)
{
  int x = 10;
  inc(x);

  printf("%d\n", x);

  return 0;
}
#endif

#if 1
// 포인터
// 1. 변수는 메모리에 저장됩니다.
//   : 메모리에 저장되므로, 주소를 가집니다.
// 2. & 연산자를 통해 변수의 주소를 얻을 수 있습니다.

// 3. 포인터 변수를 통해 변수의 주소를 저장할 수 있습니다.
//   int 타입의 변수의 주소를 저장하기 위해서는 int* 타입의 변수가 필요합니다.
//   char 타입의 변수의 주소를 저장하기 위해서는 char* 타입의 변수가 필요합니다.

// 4. 주소의 크기는 64비트 컴파일러 기준에서 8바이트(64비트)입니다.
//  > 모든 포인터 변수의 크기는 8바이트 입니다.

// 5. 대상체(변수)의 주소를 가지고 있는 포인터 변수를 통해서,
//    대상체의 값을 읽거나 변경할 수 있습니다.

int main(void)
{
  int n = 10;
  printf("%p\n", &n);

  int *p = &n;
  printf("%p\n", p);

  printf("sizeof(n): %zu\n", sizeof(n));
  printf("sizeof(p): %zu\n", sizeof(p));

  printf("%d\n", *p);
  *p = 42;

  printf("%d\n", n);

  return 0;
}
#endif

void inc1(int n)
{
  ++n;
}

void inc2(int *pn)
{
  ++(*pn);
}

int main(void)
{
  int x = 10;

  inc1(x); // call by value
  printf("x: %d\n", x);

  inc2(&x); // call by reference
  printf("x: %d\n", x);

  return 0;
}