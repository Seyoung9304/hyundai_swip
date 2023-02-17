// 4_typedef.c
#include <stdio.h>

// 1. typedef
// => 기존 타입에 별명을 부여합니다.
//  : 변수를 만드는 방법과 동일하게, 타입의 별칭을 만들 수
//    있습니다.

#if 0
int main(void)
{
  typedef int AAA;
  AAA a;

  typedef int X[3]; // int[3]
  X x;              // int x[3];

  return 0;
}
#endif

// 2. typedef
//  1) 가독성
//  => 타입의 목적을 표현하기 유용합니다.
#if 1
typedef signed char int8_t;
typedef short int16_t;

typedef int BOOL;
#define YES 1
#define NO 0

int main(void)
{
  int8_t a;

  BOOL b = YES;

  return 0;
}
#endif

// 2) 복잡한 표현식을 간단하게 표현할 수 있습니다.
// void (*signal(int sig, void (*func)(int)))(int);

typedef void (*func_t)(int);
func_t signal(int sig, func_t func);