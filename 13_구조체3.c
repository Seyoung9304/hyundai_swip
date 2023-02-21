// 13_구조체3.c
#include <stdio.h>
#if 0

struct point
{
  // 멤버 데이터 변수
  int x;
  int y;
  int z[3];
};

int main(void)
{
  // int a[3] = {1, 2, 3}; // int[3]
  // int b[3] = {1, 2, 3}; // int[3]
  // a=b; /* ERROR */

  // . 연산자를 이용해서 각 멤버 변수에 접근할 수 있습니다.
  struct point pt1 = {10, 20};
  printf("%d %d\n", pt1.x, pt1.y);
  printf("%zu %zu\n", sizeof(pt1), sizeof(struct point));

  struct point pt2;
  pt2 = pt1; /* OK */
  printf("%d %d\n", pt2.x, pt2.y);

  return 0;
}
#endif

// 1. 구조체 변수를 함수의 인자로 전달하면, call by value로
//    동작합니다.
// 2. 구조체 변수의 크기가 클 경우, 복사의 비용이 발생합니다.

struct point
{
  int x;
  int y;
  int z[1024];
};

void print_point1(struct point pt)
{
  printf("%d, %d\n", pt.x, pt.y);
  pt.x = 100;
  pt.y = 200;
}

// 주소를 전달하는데, 읽기 전용으로만 사용하겠다.
void print_point2(const struct point *pt)
{
  printf("%d, %d\n", (*pt).x, (*pt).y);
  // (*pt).x  ==  pt->x
  printf("%d, %d\n", pt->x, pt->y);
}

int main(void)
{
  printf("%zu\n", sizeof(struct point));

  struct point pt = {10, 20};
  print_point1(pt);  // call by value
  print_point2(&pt); // call by reference

  printf("%d, %d\n", pt.x, pt.y);

  return 0;
}