// 16_매크로2.c
#include <stdio.h>

#if 0
#define SQUARE(x) ((x) * (x))
// 1. 매크로 함수는 대문자로 표현하는 것이 일반적입니다.

// 2. 매크로 함수 문제점
//   1) 우선순위 문제
//       SQUARE(x+x)
//       => (x+x) * (x+x)
//       DBL(x) + DBL(x)
//       => ((x) + (x)) * ((x) + (x))
//    : 매크로로 치환되는 영역은 반드시 괄호로 감싸야 합니다.
#define DBL(x) ((x) + (x))

int main(void)
{
  int x = 10;
  printf("%d\n", SQUARE(x)); // 100
  printf("%d\n", SQUARE(x + x));

  printf("%d\n", DBL(x) * DBL(x));

  return 0;
}
#endif

#include <stdio.h>

#define SQUARE(x) ((x) * (x))
// 매크로 함수는 인자가 두번이상 확장되고, 그 안에서 미정의 동작이
// 발생할 위험성이 있습니다.
// => 주의해야 한다.

// 이름을 통해서 부수효과의 위험성을 알리는 것이 좋습니다./
// => Cert C
#define UNSAFE_SQUARE(x) ((x) * (x))

int main(void)
{
  int x = 2;
  printf("%d\n", SQUARE(++x));
  //              (++x) * (++x) /* 미정의 동작 */

  return 0;
}