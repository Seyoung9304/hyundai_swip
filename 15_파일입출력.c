// 15_파일입출력.c
#include <stdio.h>

// 1. 표준 입출력
//  -  stdin: 표준 입력 장치 => 라인 버퍼링
//  - stdout: 표준 출력 장치 => 라인 버퍼링
//  - stderr: 표준 에러 장치 => 버퍼링 X

#if 0
int main(void)
{
  // printf("hello\n");
  fprintf(stderr, "hello");

  // while (1);
  for (;;)
    ;
}
#endif

// scanf
// => fscanf(stdin, ...)

// printf
// => fprintf(stdout, ...)

// 2) stdin, stderr, stdout
//   : FILE 구조체의 포인터타입입니다.
//   => FILE*

// 3) 일반 파일을 다루는 방법.
//  FILE *fopen(const char *path, const char *mode);

// 경로: path
//  1) 절대 경로
//    C:\\users\\aaa\\Documents\\c.txt - Windows
//    /home/aaa/documents/c.txt        - Linux

//  2) 상대 경로
//   : 현재 작업 디렉토리
//      . : 현재 디렉토리
//     .. : 상위 디렉토리

//  int fclose(FILE *stream);
#include <unistd.h>

int main(void)
{
  char buf[512];
  printf("%s\n", getcwd(buf, sizeof buf));

  FILE *fp = stdout;

  int n = 10;
  double d = 3.14;
  const char *s = "hello";

  fprintf(fp, "%d %lf %s\n", n, d, s);

  return 0;
}