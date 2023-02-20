// 10_포인터15.c
#include <stdio.h>

// 1. 포인터 + 정수
//    포인터 - 정수
//      : 주소값 + 정수 * sizeof(대상체 타입)
//      : 주소값 - 정수 * sizeof(대상체 타입)

//  int* p = NULL;
//  p + 1  => 4

//  double* p = NULL;
//  p + 1  => 8

// 2. 포인터 + 포인터 => 불가능한 연산입니다.
// 3. 포인터 - 포인터
//    : 같은 배열 안에서만 의미있는 결과입니다.
//   => offset을 구하는 연산입니다.

int main(void)
{
  int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int *p1 = x + 5;
  int *p2 = x;

  printf("%ld\n", p1 - p2); // 5
  printf("%ld\n", p2 - p1); // -5

  return 0;
}