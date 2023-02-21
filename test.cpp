#include <stdio.h>
#if 0
int main(void)
{

  
  const char *s = "hello";

  int n = 100;

  void *p = &n;
  // int*에서 void*로의 암묵적인 변환이 허용됩니다.

  int *pn = (int *)p;
  // void*에서 int*로의 암묵적인 변환이 허용되지 않습니다.

  printf("%d\n", *pn);

  return 0;
}
#endif

int main(void)
{
  int n = 10;
  const int *p = &n; // int* -> const int*

  const int c = 42;
  int *p2 = &c; // const int* -> int* /* ERROR */
}
