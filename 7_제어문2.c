// 7_제어문2.c
#include <stdio.h>

// 반복문
// 1. while
// 2. for
// 3. do-while

// 1. while
//  while(조건) { 조건이 참일 때; }
// > 조건이 거짓이 되는 시점이 명확하지 않을 때

// 2. for
//  for (초기화; 조건; 실행구문2) { 실행구문1 }
// > 조건의 구간이 명확할 때

// 초기화 -> 조건 -> 실행구문1 -> 실행구문2 -> 조건 -> 실행구문1 -> 실행구문2 ...

// 1) 10 이상을 입력 받아야 합니다.
#if 0
int main(void)
{
  int n = 0;
  while (n < 10)
  {
    scanf("%d", &n);
  }

  printf("n: %d\n", n);

  return 0;
}
#endif

#if 0
// 2) 특정한 문장을 10번 출력해라.
int main(void)
{
  for (int i = 0; i < 10; i++)
  {
    printf("hello\n");
  }

  return 0;
}
#endif

// 3. break, continue
//  -    break: 반복문을 탈출할 때 사용합니다.
//  - continue: 반복문의 실행 구문을 더이상 수행하지 않고, 조건으로 넘어갑니다.

int main(void)
{

  int n;
  while (1)
  {
    scanf("%d", &n);
    if (n < 0)
      break;
  }

  for (;;) // for의 무한반복문
  {
    scanf("%d", &n);
    if (n < 0)
      break;
  }

  return 0;
}
