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

#if 0
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

#endif

#if 0
int main(void)
{
  char str[64] = "hello hello hello ";

  char *p = strtok(str, " ");
  printf("%s\n", p);

  p = strtok(NULL, " ");
  printf("%s\n", p);

  p = strtok(NULL, " ");
  printf("%s\n", p);

  p = strtok(NULL, " ");
  printf("%s\n", p);

  return 0;
}
#endif

// strtok는 내부에 정적 변수(전역 변수, 정적 지역 변수)를 통해
// 상태를 가지고 있기 때문에, 하나의 연산이 완료되기 전에, strtok가
// 사용되면, 결과가 제대로 처리되지 않습니다.
//  => 재진입이 불가능한 함수입니다.

#if 0
void foo(void)
{
  char *last = NULL;
  char str2[] = "world world world";
  char *p = strtok_r(str2, " ", &last);
  printf("foo: %s\n", p);
}
// strtok: 함수가 상태를 가지고 있기 때문에,
//         하나의 문자열에 대한 파싱이 종료되기 이전에, 다른 함수가
//         호출되면, 미정의 동작이 발생합니다.

int main(void)
{
  char str1[] = "hello hello hello";

  char *last = NULL;
  char *p = strtok_r(str1, " ", &last);
  printf("%s\n", p);

  foo();

  p = strtok_r(NULL, " ", &last);
  printf("%s\n", p);

  return 0;
}
#endif

#if 0
int n;
int *foo(void)
{
  // static int n;
  return &n;
}

int main(void)
{
  int *p1 = foo();
  *p1 = 100;

  int *p2 = foo();
  *p2 = 42;

  printf("%p %p\n", p1, p2);
  printf("%d %d\n", *p1, *p2);

  return 0;
}
#endif

// 함수에서 포인터를 반환할 때
//  1) 정적 변수(전역 변수, 정적 지역 변수)의 주소를 반환합니다.
//   => 재진입이 불가능합니다.

//  2) 동적 메모리 할당
//    - 동적 메모리 할당에 대한 문제점
//       "오버헤드" / "free"

#include <stdlib.h>

// int n;
#if 0
int *foo(void)
{
  static int n;
  return &n;
}

int *goo(void)
{
  return (int *)malloc(sizeof(int));
}

int main(void)
{
  printf("%p %p\n", foo(), foo());
  printf("%p %p\n", goo(), goo());

  int *p = goo();
  free(p);

  return 0;
}
#endif

#if 0
int main(void)
{
  const char *s = "hello world";

  // char *p = (char *)malloc(strlen(s) + 1);
  // strcpt(p, s);
  char *p = strdup(s);
  free(p);

  return 0;
}
#endif

void foo(int *result)
{
  *result = 142;
}

void goo(int *x, int n)
{
  // ...
}

int main(void)
{
  // 호출자가 메모리를 직접 할당해서 결과를 받는 형태로
  // 함수를 설계하는 것이 좋습니다.
  int result;
  foo(&result);

  int x[10];
  goo(x, 10);

  return 0;
}