
#include <stdio.h>

// ftell: 현재 오프셋
// fseek: 오프셋 이동

// int main(void)

// $ a.exe 10 20 30
//  argc: 4
//  argv[0]: a.exe
//  argv[1]: 10
//  argv[2]: 20
//  argv[3]: 30
#if 0
int main(int argc, char *argv[])
{
  for (int i = 0; i < argc; i++)
  {
    printf("%s\n", argv[i]);
  }

  return 0;
}
#endif

int main(int argc, char **argv)
{
  if (argc != 2)
  {
    printf("잘못된 사용: ./a.out <파일 경로>\n");
    return 1;
  }

  FILE *fp = fopen(argv[1], "r");
  if (fp == NULL)
  {
    printf("없는 파일입니다.\n");
    return 1;
  }

  //-----
  fseek(fp, 0, SEEK_END);
  long fileSize = ftell(fp);

  printf("파일 크기: %ld\n", fileSize);

  return 0;
}