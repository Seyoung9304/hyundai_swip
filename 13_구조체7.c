// 13_구조체7.c
#include <stdio.h>

// 사용자 정의 타입
// 1) 구조체
// 2) 공용체 => union
//  1) 공용체 크기는 멤버 데이터 중에 가장 큰 멤버의 크기로 결정됩니다.
//  2) 용도
//    - 멤버 데이터 중 하나의 데이터만 유효할 경우 사용하는 것이 좋습니다.
//  3) 주의사항
//    - 마지막에 접근한 멤버 데이터만 유효할 수 있습니다.

#if 0
union AAA
{
  char a;
  double b;
  int c;
};

int main(void)
{
  printf("%zu\n", sizeof(union AAA));

  union AAA aaa;
  printf("%p %p %p\n", &aaa.a, &aaa.b, &aaa.c);

  return 0;
}
#endif

#if 0
struct user
{
  char name[32];
  int age;
  union job
  {
    char company[32];
    char school[32];
  } job;
};
#endif

union data
{
  char bytes[4];
  int n; // 4바이트
};

// b   0  1  2  3
// n |--------------|
//    12 34 56 78

union data2
{
  int n;
  double f;
};

int main(void)
{
  union data2 data2;
  data2.n = 42;

  // data2.f = 3.14;
  printf("%d\n", data2.n); // 의미 없음
  printf("%f\n", data2.f);

  union data data;
  data.n = 0x12345678;

  printf("%x %x %x %x\n",
         data.bytes[0],
         data.bytes[1],
         data.bytes[2],
         data.bytes[3]);

  return 0;
}