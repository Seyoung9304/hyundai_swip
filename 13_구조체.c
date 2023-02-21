// 13_구조체.c
#include <stdio.h>

// C의 타입
// 1. 내장 타입(built in type) / 원시 타입(primitive type)
//  char, int, double, float, long ...

// 2. 사용자 정의 타입(user defined type)
//   - struct
//   - union
//   - enum

// * 복소수의 합을 구하는 함수를 만들어봅시다.
//   1 + 2i
//   3 + 4i
// ---------
//   4 + 6i
// int add(int a, int b) { return a + b; }

// 반환값은 1개만 가능합니다.
#if 0
??? add(int ar, int ai, int br, int bi)
{
}


int main(void)
{
  int ar = 1, ai = 2; // 1 + 2i
  int br = 3, bi = 4; // 3 + 4i

  return 0;
}
#endif

// => 해결방법: Out Parameter
//   정의: 함수의 결과를 반환값을 통해 전달하는 것이 아니라,
//        함수 인자를 통해 전달합니다.
//     "Call by reference"

void add(int ar, int ai, int br, int bi, int *sr, int *si)
{
  *sr = ar + br;
  *si = ai + bi;
}

int main(void)
{
  int ar = 1, ai = 2; // 1 + 2i
  int br = 3, bi = 4; // 3 + 4i

  int sr, si;
  add(ar, ai, br, bi, &sr, &si);

  printf("result: %d + %di", sr, si);

  return 0;
}