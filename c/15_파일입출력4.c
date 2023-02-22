// 15_파일입출력4.c
#include <stdio.h>

// fseek: 파일의 오프셋을 변경하는 함수
//  fseek(FILE *stream, long offset, int whence);
//   - whence: 기준점
//    1) SEEK_SET: 시작 위치
//    2) SEEK_END: 파일의 끝 위치
//    3) SEEK_CUR: 현재 위치

// ftell: 파일의 오프셋을 확인하는 함수

int main(void)
{
  FILE *fp = fopen("abc.txt", "wt+");
  long offset = ftell(fp);
  printf("offset: %ld\n", offset);

  fprintf(fp, "hello");
  offset = ftell(fp);
  printf("offset: %ld\n", offset);

  // 핵심 코드
  fseek(fp, 0, SEEK_SET);
  offset = ftell(fp);
  printf("offset: %ld\n", offset);

  char buf[32];
  fscanf(fp, "%s", buf);

  printf("buf: %s\n", buf);

  fclose(fp);

  return 0;
}