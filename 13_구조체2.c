// 13_구조체2.c
#include <stdio.h>

#if 0
//     <구조체 태그>
struct AAA
{
  int a;
};

struct BBB
{
  int a;
};

// 1. 동일한 사용자 정의 타입을 여러개 정의할 수 없습니다.
// 2. 구조체 태그가 다르면 다른 타입입니다.
int main(void)
{
  struct AAA a;
  struct BBB b;

  a = b; // 에러!
  b = a; // 에러!

  return 0;
}
#endif