// 11_동적메모리할당2.c

#include <stdio.h>
#include <stdlib.h> // malloc, free, exit

// 1. malloc은 가용한 메모리가 없을 경우, NULL을 반환합니다.
//   => 실패 가능성이 있는 함수입니다.
//   => 초기화되지 않은 값이 반환됩니다.
//      "쓰레기값입니다."

#if 0
int main(void)
{
  // int *p = (int *)malloc(sizeof(int) * 10);
  int *p = (int *)malloc(sizeof(int[10]));
  if (p == NULL)
  {
    printf("error!\n");
    return 1;
  }

  for (int i = 0; i < 10; i++)
  {
    p[i] = i + 1;
  }

  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", p[i]);
  }
  free(p);

  return 0;
}
#endif

int main(void)
{
#if 0
  int x[3][2] = {{1, 2},
                 {3, 4},
                 {5, 6}};
#endif

  int(*x)[2] = malloc(sizeof(int[2]) * 3);
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      x[i][j] = i * 2 + j + 1;
    }
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 2; j++)
    {
      printf("%d\n", x[i][j]);
    }
  }
}