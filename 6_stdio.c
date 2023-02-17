// 6_stdio.c
#include <stdio.h>

// 입력
// - scanf
// 1) 주소를 전달해야 합니다.
// 2) 입력의 성공 여부를 판단하는 것이 중요합니다.

#if 0
int main(void)
{
  int n;
  char ch;

  // scanf("%d", &n);
  // printf("%d\n", n);

  scanf("%c", &ch);
  printf("%c\n", ch);

  return 0;
}
#endif

// 표준 입출력
//  => UNIX
//    "모든 것은 파일이다."
//    파일의 인터페이스를 통해서 장치를 다룰 수 있습니다.

// => 키보드에서 EOF을 날리는 방법
//    Windows: Ctrl + Z
//  Linux/Mac: Ctrl + D
#if 0
int main(void)
{
  int n;
  // FILE *fp = fopen("a.txt", "r");

  while (1)
  {
    // int ret = fscanf(fp, "%d", &n);
    int ret = scanf("%d", &n);
    if (ret != 1)
      break;

    printf("n: %d\n", n);
  }

  printf("OK!\n");

  return 0;
}
#endif

int main(void)
{
  int a;
  int b;
  int ret;

#if 0
  while (1)
  {
    ret = scanf("%d %d", &a, &b);
    if (ret != 2)
      break;

    printf("result: %d\n", a + b);
  }
#endif

  while (scanf("%d %d", &a, &b) == 2)
  {
    printf("result: %d\n", a + b);
  }

  printf("program end...\n");

  return 0;
}