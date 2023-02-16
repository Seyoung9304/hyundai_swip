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

// float
// double

#include <stdint.h>

int main()
{
  uint32_t a;
  int8_t b;

  printf("sizeof(long): %lu\n", sizeof(long));

  return 0;
}