// 10_포인터.c
#include <stdio.h>

// 포인터
//  왜?
//  => 함수의 호출을 통해 변수의 값을 변경하고자 할 때

#if 0
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
#endif

void inc(int *n)
{
  n += 1;
}

int main(void)
{
  int n = 0;
  inc(&n);
  // call by reference
  // : 주소를 전달해서, 변수의 값을 다른 함수를 통해 변경할 수 있습니다.

  printf("%d\n", n); // ?

  return 0;
}