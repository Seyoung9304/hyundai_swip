// 2_변수4.c
#include <stdio.h>

// 1. 초기화 vs 대입
//   초기화: 변수를 생성하면서, 값을 지정합니다.
//    대입: 만들어진 변수의 값을 변경합니다.
#if 0
int main(void)
{
  // 초기화
  int n1 = 10;

  int n2;

  // 대입
  n2 = 10;

  printf("%d %d\n", n1, n2);

  return 0;
}
#endif

// 2. 변수
//  - 메모리에 저장됩니다.
//  - 저장된 메모리의 주소를 가집니다.

#if 1
#include <stdlib.h>

int global = 10;

// 0x100e14000
// 0x100e14004
// 0x155e06a50
// 0x16eff2f08

int main(void)
{
  int local = 10;
  static int static_local = 200;

  printf("%p\n", &main);         // 함수 - 텍스트(Read Only)
  printf("%p\n", &global);       // 전역
  printf("%p\n", &static_local); // 정적 지역

  void *p = malloc(sizeof(int));
  printf("%p\n", p); // 동적 메모리 할당

  printf("%p\n", &local); // 지역

  // %d: 10진수 정수 출력
  // %p: 주소 출력

  return 0;
}
#endif

// 3. 변수의 크기는 타입에 의해서 결정됩니다.
//  => 타입을 구하는 방법
//     '식별자'를 제외한 나머지가 타입입니다.
//  int n;       => int
//  int x[3];    => int[3]

//  => 타입과 변수의 크기를 구하고 싶다면
//     sizeof(타입)
//     sizeof 변수 / sizeof(변수)

#include <stdio.h>

int main(void)
{
  printf("%zu\n", sizeof(int));

  int n;
  printf("%zu\n", sizeof(n));
  printf("%zu\n", sizeof n);

  return 0;
}