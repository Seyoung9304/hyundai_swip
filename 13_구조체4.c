// 13_구조체4.c

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

struct complex add2(const struct complex *a,
                    const struct complex *b)
{
  struct complex result = {a->re + b->re, a->im + b->im};
  return result;
}

int main(void)
{
  struct complex a = {10, 20};
  struct complex b = {20, 30};
  struct complex result;

  result = add1(a, b);

  result = add2(&a, &b);
}