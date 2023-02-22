// 13_구조체12.c
#include <stdio.h>

// 1. union(공용체)
//   => 공용체의 크기는 멤버 데이터 타입중 가장 큰 크기를 가지는 타입에
//      의해서 결정됩니다.
//   => 공용체는 멤버 데이터가 메모리를 공유하기 때문에,
//      마지막에 사용된 값이 유효합니다.
union tag
{
  int a;
  char c;
  double d;
};

// 2. enum(열거체)
//  => 정수형 상수를 enum을 통해 정의할 수 있습니다.
#define PI 3.14

#define TASK_RUNNING 0
#define TASK_STOPPED 1

enum task_state
{
  TASK_RUNNING2 = 100,
  TASK_STOPPED2,
};

int main(void)
{
  enum task_state s = TASK_RUNNING;

  printf("%zu\n", sizeof(union tag));

  union tag data;
  data.a = 424242;
  // data.d = 3.14;

  printf("%d\n", data.a); /* OK */

  return 0;
}