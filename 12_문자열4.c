// 12_문자열4.c
#include <stdio.h>
#include <string.h> // strtok

#if 0
int main(void)
{
  char str[64] = "hello world show me the money";

#if 0
  char *p;
  p = strtok(str, " ");

  while (p != NULL)
  {
    printf("%s\n", p);

    p = strtok(NULL, " ");
  }
#endif

  for (char *p = strtok(str, " ");
       p != NULL;
       p = strtok(NULL, " "))
  {
    printf("%s\n", p);
  }

  return 0;
}

#endif

void foo(void)
{
  char str2[] = "world world world";
  char *p = strtok(str2, " ");
  printf("foo: %s\n", p);
}
// strtok: 함수가 상태를 가지고 있기 때문에,
//         하나의 문자열에 대한 파싱이 종료되기 이전에, 다른 함수가
//         호출되면, 미정의 동작이 발생합니다.

int main(void)
{
  char str1[] = "hello hello hello";

  char *p = strtok(str1, " ");
  printf("%s\n", p);

  foo();

  p = strtok(NULL, " ");
  printf("%s\n", p);

  return 0;
}