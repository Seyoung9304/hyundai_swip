// 8_함수.c
#include <stdio.h>

// 함수: 입력을 받아서 주어진 연산을 수행한 후 결과를 반환하는
//      코드의 집합입니다.

// 반환타입 함수이름(입력 타입....)
int print_n(int n)
{
  printf("%d\n", n);
  return 0;
}

int main(void)
{
  int n = 10;

  // printf("%d\n", n);
  // printf("%d\n", n);
  // printf("%d\n", n);
  // printf("%d\n", n);
  // printf("%d\n", n);

  print_n(n);
  print_n(n);
  print_n(n);
  print_n(n);
  print_n(n);

  return 0;
}