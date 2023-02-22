// 13_구조체8.c

// 열거체(enum)

// 매크로 상수
// #define TASK_RUNNING 0
// #define TASK_STOPPED 1

#include <stdio.h>

enum task_state
{
  TASK_RUNNING = 100, // 0
  TASK_STOPPED        // 1
};

int main(void)
{
  int x = TASK_RUNNING;
  enum task_state state = TASK_RUNNING;

  state = 1024; /* 컴파일 오류가 발생하지 않음. */

  printf("%d\n", TASK_RUNNING);
  printf("%d\n", TASK_STOPPED);

  return 0;
}