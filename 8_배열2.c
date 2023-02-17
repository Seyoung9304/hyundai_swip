
// 8_배열2.c
#include <stdio.h>

// MSVC        => 배열의 크기는 컴파일 시간에 결정되어야 합니다.
// GCC / clang => 런타임에 배열의 크기를 결정할 수 있습니다.
#if 0
int main(void)
{
  int n;
  scanf("%d", &n);

  int arr[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &arr[i]);
  }

  for (int i = 0; i < n; i++)
  {
    printf("%d\n", arr[i]);
  }

  return 0;
}
#endif