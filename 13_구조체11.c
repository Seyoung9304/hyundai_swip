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

void copy_user(struct user *dest, const struct user *src)
{
  if (dest->name)
  {
    free(dest->name);
  }

  if (src->name)
  {
    dest->name = (char *)malloc(strlen(src->name) + 1);
    strcpy(dest->name, src->name);
  }
  else
  {
    dest->name = NULL;
  }

  dest->age = src->age;
}

int main(void)
{
  struct user user1;
  init_user(&user1, "Tom", 42);

  // struct user user2 = user1;
  // 얕은 복사(Shallow Copy) 문제
  // > 구조체의 멤버 데이터 중 포인터 멤버가 존재할 경우,
  //   메모리 복사를 사용할 때 발생합니다.
  //  - 깊은 복사(Deep Copy)

  struct user user2 = {0};
  init_user(&user2, "Bob", 10);

  copy_user(&user2, &user1); // 깊은 복사

  print_user(&user1);
  print_user(&user2);

  del_user(&user1);
  del_user(&user2);

  return 0;
}