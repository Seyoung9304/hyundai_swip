// 14_함수포인터4.c
#include <stdio.h>
#include <stdlib.h> // qsort

#if 1
void qsort(void *base, size_t nel, size_t width,
           int (*compar)(const void *, const void *));
#endif

typedef struct user
{
  char name[32];
  int age;
} USER;

int main(void)
{
  USER users[5] = {
      {"Tom", 42},
      {"Bob", 16},
      {"Alice", 30},
      {"David", 55},
      {"Yuna", 24}};

  // 1) qsort를 이용해서, 사전 이름 순서대로 정렬해보세요.

  // 2) qsort를 이용해서, 내림차순 나이 순서대로 정렬해보세요.

  for (int i = 0; i < 5; i++)
  {
    printf("%s(%d)\n", users[i].name, users[i].age);
  }
}