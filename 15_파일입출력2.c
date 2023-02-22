// 15_파일입출력2.c
#include <stdio.h>

#if 0
int main(void)
{
  int num;
  int sum = 0;

  while (scanf("%d", &num) == 1)
  {
    sum += num;
  }

  printf("sum: %d\n", sum);

  return 0;
}
#endif

int main(void)
{
  FILE *fp = fopen("b.txt", "rt");
  if (fp == NULL)
  {
    return 1;
  }

  int num;
  int sum = 0;

  while (fscanf(fp, "%d", &num) == 1)
  {
    sum += num;
  }

  printf("sum: %d\n", sum);
  fclose(fp);

  return 0;
}