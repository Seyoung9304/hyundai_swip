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

int cmp_name(const void *a, const void *b)
{
  USER ia = *(const USER *)a;
  USER ib = *(const USER *)b;

  char* namea = ia.name;
  char* nameb = ib.name;
  
  for (int i=0;i<32;i++){
    if (namea[i]<nameb[i]){
      return -1;
    }else if (namea[i]>nameb[i]){
      return 1;
    }else{
      continue;
    }
  }
}

int cmp_age(const void *a, const void *b)
{
  double ia = *(const double *)a;
  double ib = *(const double *)b;
  // return ia - ib;
  return ia < ib ? -1 : 1;
}

#include <stdlib.h>

int main(void)
{
  USER users[5] = {
      {"Tom", 42},
      {"Bob", 16},
      {"Alice", 30},
      {"David", 55},
      {"Yuna", 24}};

  // 1) qsort를 이용해서, 사전 이름 순서대로 정렬해보세요.
  qsort(users, 5, sizeof(USER), cmp_name);
  
  for (int i = 0; i < 5; i++)
  {
    printf("%s(%d)\n", users[i].name, users[i].age);
  }

  // 2) qsort를 이용해서, 내림차순 나이 순서대로 정렬해보세요.
  qsort(users, 5, sizeof(USER), cmp_age);

  for (int i = 0; i < 5; i++)
  {
    printf("%s(%d)\n", users[i].name, users[i].age);
  }
}