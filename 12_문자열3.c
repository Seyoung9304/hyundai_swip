

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
