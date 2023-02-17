// 10_포인터.c
#include <stdio.h>

// 포인터
//  왜?
//  => 함수의 호출을 통해 변수의 값을 변경하고자 할 때

void inc(int n)
{
  n += 1;
}

int main(void)
{
  int n = 0;
  inc(n);
  // call by value
  // : 값에 의한 호출

  printf("%d\n", n); // ?

  return 0;
}