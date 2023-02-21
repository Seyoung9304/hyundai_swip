// 13_구조체5.c
#include <stdio.h>

// 구조체 멤버의 정렬과 구조체의 정렬에 따라서,
// 구조체의 크기가 달라집니다.
// 멤버의 위치도 달라집니다.

// => 네트워크 등의 구조체 정렬을 통일할 필요가 있습니다.

#if 0
struct AAA
{
  char a;
  int b;
  double c;
};

struct BBB
{
  int b;
  double a;
  char c;
};

struct CCC
{
  char a;
  double b;
  char c;
  double d;
  int e;
};
// 40

int main(void)
{
  printf("%zu\n", sizeof(struct AAA));
  printf("%zu\n", sizeof(struct BBB));
  printf("%zu\n", sizeof(struct CCC));

  return 0;
}
#endif

#if 0
#pragma pack(push, 1)
struct AAA
{
  int age;
  double d;
};
#pragma pack(pop)

struct BBB
{
  int age;
  double d;
};

int main(void)
{
  printf("%zu\n", sizeof(struct AAA));
  printf("%zu\n", sizeof(struct BBB));

  return 0;
}
#endif

#pragma pack(1)
struct AAA
{
  char a[5];
  double b;
};

int main(void)
{
  FILE *fp = fopen("test.dat", "w");

  printf("%zu\n", sizeof(struct AAA));

  struct AAA aaa = {"hell", 0.0};
  fwrite(&aaa, sizeof(struct AAA), 1, fp);

  fclose(fp);

  return 0;
}