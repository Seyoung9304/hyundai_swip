// 7_제어문.c
#include <stdio.h>

// 제어문(Control Statement)
// 1) 조건문
//  - if
//  - if / else
//  - if / else if / else if / else
#if 0
int main(void)
{
  int score;
  scanf("%d", &score);

  // - 조건의 범위를 좁은 범위부터 넓혀 가는 형태로 만드는게
  //   좋습니다.
  // - else를 반드시 사용하는 것이 좋습니다.
  if (score >= 90)
  {
    printf("A\n");
  }
  else if (score >= 80)
  {
    printf("B\n");
  }
  else if (score >= 70)
  {
    printf("C\n");
  }
  else if (score >= 60)
  {
    printf("D\n");
  }
  else
  {
    /* Nothing */;
  }

  return 0;
}
#endif

// 2) switch
// => 조건을 체크하는 것이 아니라, 값이 동일한지 확인합니다.
// 1) break
//  : switch 문을 빠져나갈 수 있습니다.
// 2) default
//  : 값이 매칭되지 않는 경우, 수행되는 루틴입니다.
int main(void)
{
  int score;
  scanf("%d", &score);

  switch (score)
  {
  case 1:
    printf("A\n");
    break;
  case 2:
    printf("B\n");
    break;
  case 3:
    printf("C\n");
    break;
  case 4:
    printf("D\n");
    // fallthrough
  default:
    printf("F\n");
  }

  return 0;
}