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
#if 0
int main(void)
{
  int x[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  int *p1 = x + 5;
  int *p2 = x;

  printf("%ld\n", p1 - p2); // 5
  printf("%ld\n", p2 - p1); // -5

  return 0;
}
#endif

void print_arr(int *arr)
{
  // 1.
  for (int i = 0; arr[i] != 0; i++)
  {
    printf("%d\n", arr[i]);
  }

  // 2
  int *p = arr;
  while (*p != 0)
  {
    printf("%d\n", *p);
    ++p;
  }

  // 3.
  p = arr;
  while (*p)
  {
    printf("%d\n", *p++); // 은근히 많이 쓰는 표현. 오른쪽 ++ 부터 먼저 결합하기 때문에 잘 작동한다. 
  }
}

int main(void)
{
  int x[3] = {1, 2, 3};

  // x++;
  // x += 1;

  int *p = x;
  ++p;

  // 배열 요소의 값이 0인 경우, 끝이라고 가정합니다.
  int arr[5] = {1, 2, 3, 4, 0};
  print_arr(arr);
}