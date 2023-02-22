

// 12_문자열3.c
#include <stdio.h>

// 문자열 연산 함수
// => string.h
#include <string.h>

// 1. 문자열 길이
#if 0
int foo(char *str)
{
  int len = 0;
  while (*str)
  {
    len++;
    str++;
  }

  return len;
}
#endif

#if 0
int foo(char *str)
{
  char *p = str;
  while (*p)
    p++;

  return p - str;
}
#endif

size_t foo(const char *s)
{
  const char *sc;

  for (sc = s; *sc != '\0'; ++sc)
    /* nothing */;

  return sc - s;
}

#if 0
int main(void)
{
  char str[64] = "hello world show me the money";
  printf("%zu\n", sizeof(str));

  int len = strlen(str);
  printf("%d\n", len);

  return 0;
}
#endif

#if 0
int main(void)
{
  const char *str1 = "hello";
  const char *str2 = "hello";

  if (str1 == str2)
  {
    printf("동일 문자열입니다..\n");
  }

  return 0;
}
#endif

// 2. 문자열 비교 함수: strcmp
#if 0
//  int strcmp(const char *s1, const char *s2);
//  - 반환값
//    1) 같을 경우: 0
//    2) s1이 s2보다 사전적으로 앞에 위치한다면, 음수(-1)
//                          뒤에 위치한다면, 양수(1) 을 반환합니다.

int main(void)
{
  printf("%d\n", strcmp("abc", "bcd")); // -1
  printf("%d\n", strcmp("bcd", "abc")); // 1

  char str1[32] = "hello";
  const char *str2 = "hello";

  // if (str1 == str2)
  if (strcmp(str1, str2) == 0)
  {
    printf("동일 문자열입니다..\n");
  }

  return 0;
}
#endif

// 3. 문자열 복사: strcpy
//  char * stpcpy(char *dst, const char *src);

//  주의할점
//   : 복사되는 메모리에 충분히 메모리가 확보되어야 합니다.

#if 0
int main(void)
{
  char str[32]; // 초기화
  // str = "hello"; // 대입은 허용되지 않습니다.

  strcpy(str, "hello");
  printf("%s\n", str);

  return 0;
}
#endif

// 4. 문자열 연결: strcat
//  => 주의: 메모리 공간 충분히 확보해야 합니다.
#if 0
int main(void)
{
  const char *str1 = "hello";
  const char *str2 = "world";

  char buf[64];
  strcpy(buf, str1); // "hello"

  strcat(buf, str2); // "helloworld"

  printf("%s\n", buf);

  return 0;
}
#endif

#if 0
int main(void)
{
  int n = 10;
  const int *p = &n; // int* -> const int*

  const int c = 42;
  int *p2 = &c; // const int* -> int*

  return 0;
}
#endif

#if 0
int main(void)
{
  const char str[32] = "hello";
  // str: char[32]
  // str -> char*

  // char *strcpy(char *dst, const char *src)

  const int x = 10;
}
#endif