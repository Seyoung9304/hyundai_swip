// 2_변수.c

#include <stdio.h>

#if 0


int global = 100;

void foo(void)
{
  int local = 10;
  printf("local: %d, global: %d\n", local, global);
}

int main(void)
{
  foo();
  printf("global: %d\n", global);
}
#endif

#if 0
int add(int a, int b)
{
  return a + b;
}

int main(void)
{
  int result = add(10, 20);
  printf("result: %d\n", result);

  return 0;
}
#endif

// godbolt.org
// 변수(variable)
// - 메모리에 저장되는 실행 시간에 변경 가능한 값

// 메모리 종류
// 1. 스택 - 지역 변수
//  : 함수가 시작될 때 초기화되고, 함수가 끝날 때 사라집니다.
//    스택 영역에서 관리됩니다.
//  => 생성과 해지의 비용이 없다.
//  => 초기화하지 않으면, 쓰레기값을 가집니다.

// 2. 전역 변수
//  : 모든 함수에서 접근이 가능합니다.
//    프로그램이 시작할 때 초기화되고, 프로그램이 종료될 때 사라집니다.
//    초기화하지 않으면, 자동으로 0으로 초기화해줍니다.

//  => 함수의 복잡도를 낮추는데 도움이 되지만, 모듈화를 떨어뜨립니다.
//  => 초기화된 전역 변수는 실행 파일의 용량에 영향을 줍니다.

// 3. 힙 변수
//  : 동적 메모리 할당 - malloc / free
//    프로그래머가 원하는 시점에 생성하고, 프로그래머가 원하는 시점에
//    파괴할 수 있습니다.
//  => 메모리 누수의 위험성이 있다.
//  => 할당과 해지의 비용이 크다.
//  => 초기화하지 않으면, 쓰레기값을 가집니다.

// int global = 100;

// 전역 변수가 없을 때
// => 33426

// int global[10000] = {10};
// => 82994

int global[10000];
// => 33458

int main(void)
{
  int local;
  printf("%d\n", local);

  return 0;
}