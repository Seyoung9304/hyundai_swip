
#include <stdio.h>

// TEXT: 문자열도 저장이 됩니다.
//       수정이 불가능한 영역입니다.

// C/C++에서 문자열을 사용할 때
//  : char 배열 또는 const char*를 통해 문자열을 사용할 수
//  있습니다.

int main(void)
{
  char str1[] = "hello";
  const char *str2 = "hello";

  str1[0] = 'x';
  // str2[0] = 'x'; /* 미정의 동작 */

  printf("%s\n", str1);
  printf("%s\n", str2);

  return 0;
}