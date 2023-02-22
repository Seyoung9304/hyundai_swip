// 16_매크로3.c
#include <stdio.h>

// 1) \ 를 통해서 여러줄의 확장도 가능합니다.
// 2) 매크로 함수를 만들때, 두줄을 이상을 사용할 때는?
//   => do-while(0)
#if 0
#define LOG(x)                       \
  fprintf(stderr, "file1: %s\n", x); \
  fprintf(stderr, "file2: %s\n", x)
#endif

#define LOG(x)                         \
  do                                   \
  {                                    \
    fprintf(stderr, "file1: %s\n", x); \
    fprintf(stderr, "file2: %s\n", x); \
  } while (0)

int main(void)
{
  int n;
  scanf("%d", &n);

  if (n == 10)
    LOG("OK");

  // LOG("hello");

  return 0;
}