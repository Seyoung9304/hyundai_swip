// 10_포인터6.c
#include <stdio.h>

void print_x1(int *x1, int n)
{
  for (int i = 0; i < n; i++)
    printf("%d\n", x1[i]);
}

void print_x2(int (*x2)[2], int n)
{
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < 2; ++j)
    {
      printf("%d\n", x2[i][j]);
    }
  }
}

int main(void)
{
  int x1[2];
  print_x1(x1, 2);

  int x2[3][2] = {
      10,
      20,
      30,
  };
  print_x2(x2, 3);

  return 0;
}