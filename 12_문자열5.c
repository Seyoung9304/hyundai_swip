// 12_문자열5.c
#include <stdio.h>
#include <string.h>
// strlen, strcpy, strcmp, strcat
// strtok
// 1) 정적 메모리를 통해 기존 처리되는 문자열의 주소를 저장해놓습니다.
//  > 재진입이 불가능한 함수
// 2) 원본 문자열을 수정하는 형태로 동작합니다.

#if 0
int main(void)
{
  char str[32] = "hello@hello";
  printf("%s\n", str);

  char *p = strtok(str, "@");
  printf("%s\n", p);

  p = strtok(NULL, "@");
  printf("%s\n", p);

  printf("%s\n", str);

  return 0;
}
#endif

int main(void)
{
  const char *s = "hello@hello";
  char str[32];
  strcpy(str, s); // !!!

  printf("%s\n", str);

  char *p = strtok(str, "@");
  printf("%s\n", p);

  p = strtok(NULL, "@");
  printf("%s\n", p);

  printf("%s\n", str);

  return 0;
}