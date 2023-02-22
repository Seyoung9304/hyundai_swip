// 5_연산자3.c
#include <stdio.h>

// &, |, ^, ~(1의 보수), >>, <<

// C / C++: 2의 보수

// 142
//   128 + 8 + 4 + 2
//   2^7  2^3 2^2  2^1
//   : 0000 0000 1000 1110

// -142
//   : 1111 1111 0111 0001 + 1
//     1111 1111 0111 0010

#include <stdint.h>

// >>
//  -   signed: Arithmetic Shift(부호 비트)
//  - unsigned: Logical Shift(0)

int main(void)
{
  // 0111 1011
  int8_t n = 0x7b;

  // 0011 1101
  printf("%X\n", n >> 1);

  // 1010 1011
  // 1101 0101
  int8_t n2 = 0xab;
  printf("%X\n", n2 >> 1);

  return 0;
}