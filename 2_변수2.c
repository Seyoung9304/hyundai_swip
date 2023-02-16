// 2_변수2.c

#include <stdio.h>

// C언어 타입
// - 문자 타입
// char

// - 정수 타입
// signed char / unsigned char => -128 - 127
// short / unsigned short      => -32768 - 32767
// int / unsigned int          => -21억 - 21억
// long / unsigned long
// long long / unsigned long long

#if 0
#include <stdint.h>

int main()
{
  uint32_t a;
  int8_t b;

  printf("sizeof(long): %zu\n", sizeof(long));

  return 0;
}
#endif

// - 부동 소수점 타입
// float(4)
// double(8)
// long double(8)
//
// => 연산에 오차가 존재한다.
// => 부동 소수점의 동등성 판단은 오차범위 이내에 들어오는지 여부를
//    통해 판단합니다.

#include <math.h>

int main(void)
{
  printf("sizeof(long double): %zu\n", sizeof(long double));

  double a = 0.7;
  double b = 0.1 * 7;

  // if (a == b)
  if (fabs(a - b) < 0.0000001)
  {
    printf("같다...\n");
  }

  return 0;
}