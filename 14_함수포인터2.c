// 14_함수포인터2.c
#include <stdio.h>

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

// 변하는 것과 변하지 않는 것을 분리해야 합니다.
//  "변하지 않는 전체 알고리즘에서 변해야 하는 정책은 분리되어야 한다."
//  => 정책을 분리하는 방법
//    : 함수 포인터 인자를 통해 분리할 수 있습니다.
#if 0
void sort(int *x, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (x[i] > x[j])
      {
        swap(&x[i], &x[j]);
      }
    }
  }
}

int main(void)
{
  int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  sort(x, 10);

  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", x[i]);
  }

  return 0;
}
#endif

// OCP: Open Close Principle
//  => 개방 폐쇄 원칙
//  "확장에는 열려 있고, 수정에는 닫혀 있어야 한다."
//  "새로운 기능이 추가되어도 기존 코드는 수정되면 안된다."
void sort(int *x, int n, int (*cmp)(int, int))
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      // if (x[i] < x[j])
      if (cmp(x[i], x[j]) > 0)
      {
        swap(&x[i], &x[j]);
      }
    }
  }
}
//------------------------------------

int cmp1(int a, int b)
{
  return a - b;
}

int cmp2(int a, int b)
{
  return b - a;
}

int main(void)
{
  int x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  sort(x, 10, cmp2);

  for (int i = 0; i < 10; i++)
  {
    printf("%d\n", x[i]);
  }

  return 0;
}