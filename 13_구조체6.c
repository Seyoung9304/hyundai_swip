// 13_구조체6.c
#include <stdio.h>
#include <string.h> // strlen
#include <stdlib.h> // malloc, free

struct user
{
  char *name;
  int age;
};

// 얕은 복사 문제
//  : 구조체 멤버 변수 중에 포인터 변수가 있다면
//    구조체 복사시 발생하는 문제입니다.
// "일반적인 해결 방법"
//  => 깊은 복사
#if 0
int main(void)
{
  struct user user1;
  user1.name = (char *)malloc(strlen("Tom") + 1);
  strcpy(user1.name, "Tom");
  user1.age = 42;

  printf("%s(%d)\n", user1.name, user1.age);

  struct user user2 = user1;
  printf("%s(%d)\n", user2.name, user2.age);

  free(user1.name);
  free(user2.name);

  return 0;
}
#endif

// 깊은 복사 함수
void copy_user(struct user *dest, const struct user *src)
{
  // 1. 포인터가 아닌 멤버 데이터는 그냥 복사합니다.
  dest->age = src->age;

  // 2. 포인터 멤버에 대한 복사
  if (src->name != NULL)
  {
    dest->name = (char *)malloc(strlen(src->name) + 1);
    strcpy(dest->name, src->name);
  }
  else
  {
    dest->name = NULL;
  }
}

int main(void)
{
  struct user user1;
  user1.name = (char *)malloc(strlen("Tom") + 1);
  strcpy(user1.name, "Tom");
  user1.age = 42;

  printf("%s(%d)\n", user1.name, user1.age);

  struct user user2 = user1;
  printf("%s(%d)\n", user2.name, user2.age);

  free(user1.name);
  free(user2.name);

  return 0;
}