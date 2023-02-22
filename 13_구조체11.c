// 13_구조체11.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct user
{
  char *name;
  int age;
};

void init_user(struct user *user,
               const char *name,
               int age)
{
  user->name = (char *)malloc(strlen(name) + 1);
  strcpy(user->name, name);

  user->age = age;
}

void print_user(const struct user *user)
{
  printf("%s(%d)\n", user->name, user->age);
}

void del_user(struct user *user)
{
  free(user->name);
  user->name = NULL;

  user->age = 0;
}

int main(void)
{
  struct user user1;
  init_user(&user1, "Tom", 42);

  print_user(&user1);

  del_user(&user1);

  return 0;
}