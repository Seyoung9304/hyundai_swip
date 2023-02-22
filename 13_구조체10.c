// 13_구조체10.c
#include <stdio.h>

#if 0
struct complex
{
  int re;
  int im;
};

struct complex add(struct complex a, struct complex b)
{
  struct complex result;
  result.re = a.re + b.re;
  result.im = a.im + b.im;

  return result;
}

int main(void)
{
  struct complex a = {10, 20};
  struct complex b = {.re = 10, .im = 20}; // C99

  struct complex result = add(a, b);
  printf("%d %d\n", result.re, result.im);

  return 0;
}
#endif

struct complex
{
  int re;
  int im;
};

void add(const struct complex *a,
         const struct complex *b,
         struct complex *result)
{
  // (*result).re = (*a).re + (*b).re;
  // (*result).im = (*a).im + (*b).im;

  result->re = a->re + b->re;
  result->im = a->im + b->im;

  // return result;
}

int main(void)
{
  struct complex a = {10, 20};
  struct complex b = {.re = 10, .im = 20}; // C99

  struct complex result;
  add(&a, &b, &result);

  printf("%d %d\n", result.re, result.im);

  return 0;
}