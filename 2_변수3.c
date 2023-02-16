// 2_변수3.c
#include <stdio.h>

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