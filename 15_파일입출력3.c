// 15_파일입출력3.c
#include <stdio.h>

struct user
{
  char name[32];
  int age;
};

// 저장
// size_t fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream);

// 로드
// size_t fread(void *ptr, size_t size, size_t nitems, FILE *stream);

#if 0
int main(void)
{
  struct user users[3] = {
      {"Tom", 42},
      {"Bob", 16},
      {"Alice", 25},
  };

  printf("%zu\n", sizeof(users));

  FILE *fp = fopen("users.dat", "wb");
  if (fp == NULL)
  {
    perror("fopen");
    return 1;
  }

  fwrite(users, sizeof(struct user), 3, fp);

  fclose(fp);

  return 0;
}
#endif

int main(void)
{
  struct user users[3];

  FILE *fp = fopen("users.dat", "rb");
  if (fp == NULL)
  {
    perror("fopen");
    return 1;
  }

  fread(users, sizeof(struct user), 3, fp);
  fclose(fp);

  for (int i = 0; i < 3; i++)
  {
    printf("%s(%d)\n", users[i].name, users[i].age);
  }

  return 0;
}