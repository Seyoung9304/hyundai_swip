// 7_제어문3.c
#include <stdio.h>

// do-while
// : 무조건 1번은 실행해야 할 때...

#if 0
int main(void)
{
  int n;
  scanf("%d", &n);

  while (n < 10)
  {
    scanf("%d", &n);
  }

  printf("%d\n", n);

  return 0;
}
#endif

int main(void)
{
  int n;

  do
  {
    scanf("%d", &n);
  } while (n < 10);

  printf("%d\n", n);

  return 0;
}