// 8_배열.c
#include <stdio.h>

// 배열: 동일한 타입의 메모리를 연속적으로 할당합니다.
//      각각의 메모리를 인덱스를 통해서 접근할 수 있습니다.
#if 0
int main(void)
{
  int n; // 4 byte

  int x[5]; // 20 byte

  printf("sizeof(n): %zu\n", sizeof(n));
  printf("sizeof(x): %zu\n", sizeof(x));

  return 0;
}
#endif

#if 0
// 배열의 길이를 구하는 방법
int main(void)
{
  int x[5];

  // int len = sizeof(x) / sizeof(int); // 1
  // > x의 타입이 변경될 경우, 코드도 수정되어야 합니다.

  int len = sizeof(x) / sizeof(x[0]); // 2
  printf("%d\n", len);

  return 0;
}
#endif

#if 0
int main(void)
{
  // int x[3] = {10, 20, 30}; // 10, 20, 30
  // int x[3] = {}; // 0, 0, 0
  // int x[3] = {10}; // 10, 0, 0

  // int x[3] = {0};
  int x[3] = {1, 2, 3};

  // index: 0, 1, 2
  printf("%d %d %d\n", x[0], x[1], x[2]);

  // 배열의 범위를 넘어서서 데이터를 읽거나 쓸수 없습니다.
  x[3] = 10;            /* 미정의 동작 */
  printf("%d\n", x[3]); /* 미정의 동작 */

  return 0;
}
#endif

int main(void)
{
  int x[3][5] = {
      {0},
      {0},
      {0},
  };
  //        x[3]: x는 3개 크기의 배열입니다. 하나의 원소타입은?
  //     x[3][5]: 5개 크기의 배열입니다. 하나의 원소 타입은?
  // int x[3][5]: int 입니다.
  // [ int[5] ][ int[5] ][ int[5] ]

  // 위 배열은 몇개짜리 배열인가요?
  //  => 3개 크기의 배열입니다.

  int len = sizeof(x) / sizeof(x[0]);
  printf("len: %d\n", len);

  return 0;
}