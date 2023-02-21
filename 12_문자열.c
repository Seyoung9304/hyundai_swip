// 12_문자열.c
#include <stdio.h>

// char: 문자 타입 => ASCII
//   A: 65
//   a: 97
//   0: 48

// C의 문자열
//  : char 배열인데, 널문자로 종료되어야 합니다.
#if 0
int main(void)
{
  char c = 'A';
  // c = 66;
  printf("%c\n", c);

  printf("%d\n", c); // 65

  return 0;
}
#endif

#if 0
int main(void)
{
  // char str[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
  char str[10] = "hello";

  printf("%s", str);

  return 0;
}
#endif

#if 0
int main(void)
{
  char str[5] = "hello"; /* 미정의 동작 */
  // => 문자열의 마지막은 널문자로 종료되어야 합니다.
  //    문자열을 배열에 저장할 때, 널문자(1) 크기만큼이 더 필요합니다.

  char buf[1024];
  printf("%s\n", buf); /* 미정의 동작 가능성 */

  return 0;
}
#endif

#if 0
int main(void)
{
  char str[32];

  // scanf는 버퍼의 크기 정보를 무시하고 입력 받기 때문에, 위험합니다.
  // - scanf("%s", str);
  // - gets(str);

  // fgets(str, sizeof(str), stdin); // 표준에서 안전한 문자열 입력 방법

  printf("str: %s\n", str);

  return 0;
}
#endif

// 입력 받은 문자열을 소문자면 대문자로 변경하고, 대문자면 소문자로 변경하는
// 프로그램을 만들어봅시다.

#if 0
int main(void)
{
  char buf[1024];

  // 'a': 97 , 'z': 122
  // 'A': 65 , 'Z': 90

  int ret;
  while ((ret = scanf("%s", buf)) == 1)
  {
    char *p = buf;
    while (*p) /* *p != '\0' */
    {
      if (*p >= 'A' && *p <= 'Z')
      {
        printf("대문자\n");
        *p = *p + ('a' - 'A');
      }
      else if (*p >= 'a' && *p <= 'z')
      {
        printf("소문자\n");
        *p = *p - ('a' - 'A');
      }
      else if (*p >= '0' && *p <= '9')
      {
        printf("숫자\n");
      }

      p++;
    }

    printf("%s\n", buf);
  }

  printf("Program end..\n");

  return 0;
}
#endif

#if 1
#include <ctype.h>

int main(void)
{
  char buf[1024];

  // 'a': 97 , 'z': 122
  // 'A': 65 , 'Z': 90

  int ret;
  while ((ret = scanf("%s", buf)) == 1)
  {
    char *p = buf;
    while (*p) /* *p != '\0' */
    {
      if (isupper(*p))
      {
        printf("대문자\n");
        *p = tolower(*p);
      }
      else if (islower(*p))
      {
        printf("소문자\n");
        *p = toupper(*p);
      }
      else if (isdigit(*p))
      {
        printf("숫자\n");
      }

      p++;
    }

    printf("%s\n", buf);
  }

  printf("Program end..\n");

  return 0;
}
#endif