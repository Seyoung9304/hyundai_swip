// 10_포인터2.c

#include <stdio.h>

// 1. 변수는 메모리에 저장됩니다.
//  => 변수는 메모리의 주소를 가집니다.

int main(void)
{
  int a = 100;

  // int 변수의 주소를 저장할 수 있는 타입은
  // int*
  int *p = &a;
  // p를 통해서 a의 값을 읽거나 변경할 수 있습니다.

  printf("%p\n", &a);
  printf("%p\n", p);

  printf("%d\n", *p);
  *p = 200; // 참조

  printf("%d\n", *p);
  printf("%d\n", a);

  return 0;
}