// 7_제어문.c
#include <stdio.h>

// 제어문(Control Statement)
// 1) 조건문
//  - if
//  - if / else
//  - if / else if / else if / else
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