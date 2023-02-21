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

int main(void)
{

  return 0;
}