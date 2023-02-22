// 16_매크로5.c
// #define NDEBUG

#include <stdio.h>
#include <stdlib.h> // abort
#include <assert.h> // assert

// abort: 프로세스를 비정상 종료 시킵니다.

// n은 양수이어야 한다.
#if 0
void foo(int n)
{
  if (n < 0)
  {
    fprintf(stderr, "잘못된 값이 전달되었습니다.\n");
    abort();
  }
}
#endif

#if 0
void foo(int n)
{
  assert(n >= 0);
}

int main(void)
{
  foo(-1);
  return 0;
}
#endif

// 전처리기 기능
//  #: 토큰을 문자열로 변경해줍니다.
// ##: 두개의 토큰을 하나의 토큰으로 만들어줍니다.
//  => 매크로 함수를 이중으로 사용해야 합니다.
//     이유: 매크로 치환과 같이 사용할 수 있습니다.
#if 0
#define CONCAT_IMPL(a, b) a##b
#define TO_STR_IMPL(x) #x

#define CONCAT(a, b) CONCAT_IMPL(a, b)
#define TO_STR(x) TO_STR_IMPL(x)

#define MAKE_VARIABLE(name) int CONCAT(name, __LINE__)

MAKE_VARIABLE(hello); // int hello45;

#define HELLO hello

int main(void)
{
  printf("%s\n", TO_STR(hello));
  //             #hello -> "hello"

  printf("%s\n", TO_STR(HELLO));
  //             TO_STR(HELLO) => "HELLO"
  //             TO_STR(HELLO) => TO_STR_IMPL(hello) => "hello"

  return 0;
}
#endif

// assert를 직접 만들어봅시다.
// #define NDEBUG

#ifndef NDEBUG
// Assertion failed: (n >= 0), function main, file 16_매크로5.c, line 74.
#define xassert(expr)                                                               \
    do {                                                                            \
        if (!(expr)) {                                                              \
            fprintf(stderr, "Assert failed: (%s), function %s, file %s, line %d\n", \
                #expr, __func__, __FILE__, __LINE__);                               \
            abort();                                                                \
        }                                                                           \
    } while (0)
#else
#define xassert(expr) (void)0
#endif
#if 0
int main(void) {
  int n = -10;
  xassert(n >= 0);
}
#endif

#pragma pack(1)
struct packet {
    char c;
    int a;
};

// #define STATIC_ASSERT(expr) typedef int arr[(expr) ? 1 : -1]
// C11
#define CONCAT_IMPL(a, b) a##b
#define CONCAT(a, b) CONCAT_IMPL(a, b)

#define STATIC_ASSERT(expr) \
    typedef int CONCAT(static_assertion_failed, __LINE__)[(expr) ? 1 : -1]

int main(void)
{
    printf("program start\n");
    // assert(sizeof(struct packet) == 5);

    // STATIC_ASSERT(sizeof(struct packet) == 8);
    // 컴파일 타임에 조건을 확인할 수 있는 방법입니다.

    static_assert(sizeof(struct packet) == 5, "패킷 사이즈 확인");
    _Static_assert(sizeof(struct packet) == 5, "패킷 사이즈");

    return 0;
}