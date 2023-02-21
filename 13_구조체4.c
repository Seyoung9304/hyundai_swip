// 13_구조체4.c
#include <stdio.h>
#include <stdlib.h>
// 복소수 덧셈

struct complex
{
  int re;
  int im;
};

struct complex add1(struct complex a, struct complex b)
{
  struct complex result = {a.re + b.re, a.im + b.im};
  return result;
}

// 반환도 복사입니다.
struct complex add2(const struct complex *a,
                    const struct complex *b)
{
  struct complex result = {a->re + b->re, a->im + b->im};
  return result;
}

#if 0
struct complex *add3(const struct complex *a,
                     const struct complex *b)
{
  // 1. 정적 메모리 주소 반환
  //  => 재진입이 불가능하다.
  // static struct complex result;
  // result.re = a->re + b->re;
  // result.im = a->im + b->im;

  // 2. 동적 메모리 할당
  // => 메모리 누수 위험성
  struct complex *result = (struct complex *)malloc(sizeof(struct complex));
  return result;
}
#endif

// Out Parameter
void add3(const struct complex *a,
          const struct complex *b, struct complex *result)
{
  result->re = a->re + b->re;
  result->im = a->im + b->im;
}

int main(void)
{
  struct complex a = {10, 20};
  struct complex b = {20, 30};
  struct complex result;

  result = add1(a, b);
  result = add2(&a, &b);

  add3(&a, &b, &result);
}