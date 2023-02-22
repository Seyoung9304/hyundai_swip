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

// - 경로: path
//  1) 절대 경로
//    C:\\users\\aaa\\Documents\\c.txt - Windows
//    /home/aaa/documents/c.txt        - Linux

//  2) 상대 경로
//   : 현재 작업 디렉토리
//      . : 현재 디렉토리
//     .. : 상위 디렉토리
//    .\\documents\\a.txt
//    ./documents/a.txt

// - 모드: mode
//     읽기 모드: "r"
//      : 파일이 존재하지 않으면, 오류
//     쓰기 모드: "w"
//      : 파일이 존재하지 않으면, 새로운 파일을 생성하고,
//        파일이 존재하면, 파일의 크기를 0으로 바꿉니다.
///    추가 모드: "a"
//      : 파일이 존재하지 않으면, 새로운 파일을 생성하고,
//        파일이 존재하면, 파일의 마지막에 새로운 내용이 추가됩니다.

//     읽기 모드 + 쓰기 허용: "r+"
//     쓰기 모드 + 읽기 허용: "w+"

//   Windows는 모드 한정자가 필요합니다.
//    "t": TEXT 모드
//    "b": 바이너리 모드

//  int fclose(FILE *stream);
#if 0
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
#endif

#if 0
// int errno;
// => 연산이 실패했을 경우, 오류의 원인으로 변경됩니다.
// extern int errno;

#include <errno.h>
#include <string.h> // strerror

int main(void)
{
  printf("errno: %d\n", errno);

  // FILE *fp = fopen("aaa.txt", "r");
  // => 읽기 모드로 열 경우, 파일이 존재하지 않으면 실패합니다.

  FILE *fp = fopen("aaa.txt", "w");
  // => 쓰기 모드로 열 경우, 파일이 존재하지 않으면, 새로운 파일을
  //    생성합니다.
  //    파일이 존재할 경우, 파일의 크기를 0으로 바꿉니다.

  if (fp == NULL)
  {
    // printf("file open error: %d\n", errno);
    // fprintf(stderr, "fopen: %s\n", strerror(errno));
    perror("fopen");
    return 1;
  }

  return 0;
}
#endif

//  stdout: 라인 버퍼링
// 일반 파일: 풀 버퍼링
#if 0
int main(void)
{
  FILE *fp = fopen("a.txt", "wt"); // !
  if (fp == NULL)
  {
    perror("fopen");
    return 1;
  }

  for (int i = 0; i < 10; i++)
  {
    fprintf(fp, "hello\n");
    // fflush(fp); // 버퍼를 비웁니다.
  }

  fclose(fp); // 버퍼를 비우고 파일을 닫습니다.

  // while (1)
  //   ;

  return 0;
}
#endif

int main(void)
{
  printf("hello");
  fflush(stdout);

  while (1)
    ;

  return 0;
}