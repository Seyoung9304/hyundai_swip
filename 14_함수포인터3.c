// 14_함수포인터3.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memcpy

// int temp = *a;
// *a = *b;
// *b = temp;

#if 0
void swap(void *a, void *b, size_t width)
{
  void *temp = malloc(width);

  memcpy(temp, a, width); // temp = a;
  memcpy(a, b, width);    // a = b;
  memcpy(b, temp, width); // b = temp;

  free(temp);
}
#endif

// p     q
// |---| |---|

#if 0
void swap(void *a, void *b, size_t width)
{
  unsigned char *p = a;
  unsigned char *q = b;
  unsigned char temp;

  for (int i = 0; i < width; i++)
  {
    temp = p[i];
    p[i] = q[i];
    q[i] = temp;
  }
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
#endif

void swap(void *a, void *b, size_t width)
{
  unsigned char *p = a;
  unsigned char *q = b;
  unsigned char temp;

  for (int i = 0; i < width; i++)
  {
    temp = p[i];
    p[i] = q[i];
    q[i] = temp;
  }
}

void sort(void *x, int n, size_t width,
          int (*cmp)(const void *, const void *))
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      // &x[i]: ((unsigned char*)x + i * width)
      // &x[j]: ((unsigned char*)x + j * width)
      void *a = (unsigned char *)x + i * width;
      void *b = (unsigned char *)x + j * width;

      if (cmp(a, b) > 0)
      {
        swap(a, b, width);
      }
    }
  }
}
//----------

int cmp(const void *a, const void *b)
{
  double ia = *(const double *)a;
  double ib = *(const double *)b;
  // return ia - ib;
  return ia < ib ? -1 : 1;
}

#include <stdlib.h> // qsort

int main(void)
{
  double x[10] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
  qsort(x, 10, sizeof(double), cmp);

  for (int i = 0; i < 10; i++)
    printf("%lf\n", x[i]);

  return 0;
}