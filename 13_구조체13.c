// 13_구조체13.c

#include <stdio.h>

// 비트 필드 구조체
union AAA
{
  struct
  {
    unsigned char a0 : 1;
    unsigned char a1 : 1;
    unsigned char a2 : 1;
    unsigned char a3 : 1;
    unsigned char a4 : 1;
    unsigned char a5 : 1;
    unsigned char a6 : 1;
    unsigned char a7 : 1;
  } bits;

  unsigned char u8;
};

// 0001 0010 => 0x12
int main(void)
{
  union AAA data;
  data.bits.a1 = 1;
  data.bits.a4 = 1;

  printf("%x\n", data.u8);

  return 0;
}