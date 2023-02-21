// 13_구조체5.c
#include <stdio.h>

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

int main(void)
{
  printf("%zu\n", sizeof(struct AAA));
  printf("%zu\n", sizeof(struct BBB));

  return 0;
}