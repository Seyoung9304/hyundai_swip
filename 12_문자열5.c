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

#if 0
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
#endif

// 함수가 포인터를 반환한다.
// 1) 지역 변수의 메모리를 반환하는 것은 안됩니다.
#if 0
int *foo(void)
{
  int result = 42;
  return &result;
}

int goo(void)
{
  int result = 100;
  return result;
}

int main(void)
{
  int *result = foo();
  goo();
  printf("%d\n", *result);

  return 0;
}
#endif

#if 0
// 해결방법 1. 정적 메모리(전역 변수, 정적 지역 변수)의 주소를 반환
//  => 재진입성, 스레드 안정성에 대한 고려가 필요합니다.
int result = 42;

int *foo(void)
{
  // static int result = 42;
  return &result;
}

#include <stdlib.h>
// 해결방법 2. 동적 메모리 할당(malloc, free)
//  => 누수 위험성, 동적 메모리 할당의 오버헤드

int *alloc_goo(void)
{
  int *result = malloc(sizeof(int));
  *result = 100;
  return result;
}

int main(void)
{
  int *result = foo();
  printf("%d\n", *result);

  printf("%p %p %p\n", foo(), foo(), foo());

  result = alloc_goo();
  printf("%d\n", *result);
  free(result);

  return 0;
}
#endif

// 해결방법 3. out parameter
//  => 메모리를 함수를 통해서 할당해서 반환하는 것이 아니라,
//     호출자가 메모리를 제공하는 형태로 사용하는 것이 일반적입니다.
void foo(int *result)
{
  *result = 100;
}

int main(void)
{
  int *result = malloc(sizeof(int));

  foo(result);
  free(result);
}