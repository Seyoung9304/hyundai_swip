// 3_상수.c
#include <stdio.h>

// 1. 상수
//  => 런타임(실행 시간)에 변경할 수 없는 값

// 2. C에서 상수를 만드는 방법
//  1) #define => 매크로 상수
#define PI 3.14

//  2) enum
enum
{
  TASK_RUNNING = 100,
  TASK_STOPPED = 101,
  TASK_WAIT = 102
};

// 3) const => 상수, 런타임 상수
const int global = 1024;

int main(void)
{
  const int n;
  // 주의
  // - 초기화 이후로 값을 변경할 수 없기 때문에,
  //   반드시 초기화해야 합니다.
  // => C++은 초기화하지 않는 경우, 컴파일 오류가 발생합니다.

  // global = 1000;
  printf("%d\n", global);

  printf("%lf", PI);
  //  %f: float
  // %lf: double

  return 0;
}

// 사용자 정의 타입
// 1. struct
// 2. union
// 3. enum