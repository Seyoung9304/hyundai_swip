// 14_함수포인터3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy

// int temp = *a;
// *a = *b;
// *b = temp;

void swap(void *a, void *b, size_t width)
{
  void *temp = malloc(width);

  memcpy(temp, a, width); // temp = a;
  memcpy(a, b, width);    // a = b;
  memcpy(b, temp, width); // b = temp;

  free(temp);
}

struct user
{
  char name[32];
  int age;
};

int main(void)
{
  double a = 10, b = 20;
  swap(&a, &b, sizeof(double));

  printf("%lf %lf\n", a, b);

  struct user user1 = {"Tom", 42};
  struct user user2 = {"Bob", 15};

  swap(&user1, &user2, sizeof(struct user));

  printf("%s(%d), %s(%d)\n", user1.name, user1.age, user2.name, user2.age);

  return 0;
}