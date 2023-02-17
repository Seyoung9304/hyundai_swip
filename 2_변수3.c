// 2_변수3.c
#include <stdio.h>

#if 0
int n1 = 10;
// external linkage: 외부 연결
// => 다른 파일에서 접근이 가능합니다.

static int n1 = 10;
static void goo(void) {}
// internal linkage: 내부 연결
// => 다른 파일에서 접근이 불가능합니다.

void foo(void)
{
  // int count = 0;
  // 자동 변수(지역 변수): auto int count = 0;

  static int count = 0;
  // 정적 지역 변수: 데이터 영역에 저장됩니다.
  // => 기억 부류 지정자: auto(스택) / static(데이터)

  // count += 1;
  // count = count + 1;

  ++count;
  printf("%d\n", count);
}

int main(void)
{
  // printf("%d\n", count); // error!

  foo();
  foo();
  foo();

  return 0;
}

#endif

void foo(void)
{
  static int count = 10;
  // 정적 지역 변수는 데이터 영역에 생성됩니다.
  // > 초기화되지 않은 경우 0으로 초기화됩니다.
  // > 초기화한 경우, 함수가 최초에 실행되는 시점에 한번만 초기화됩니다.

  printf("%d\n", count++);
}

int main(void)
{
  foo();
  foo();
  foo();

  return 0;
}