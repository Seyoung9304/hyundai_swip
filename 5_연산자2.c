// 5_연산자2.c

#include <stdio.h>

// 2
// 0000 0010

// 3
// 0000 0011

// %(나머지), /(몫)
// => 나누는 수의 부호에 의해, 결과값의 부호가 결정됩니다.
//  ex) 3 % 2 ==>  1
//     -3 % 2 ==> -1

// => n & 1 == 1
//   우선순위에 의해 잘못 결합되는 문제가 발생할 수 있습니다.

int is_odd(int n)
{
  // return n % 2 == 1;

  // return n & 1 == 1;
  return n & 1 == 1;
}
// 문제점?

int main(void)
{
  printf("%d\n", is_odd(-1));
  printf("%d\n", is_odd(-3));

  return 0;
}