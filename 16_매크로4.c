// 16_매크로4.c
#include <stdio.h>

// 미리 정의된 매크로 상수
// 1. __FILE__: 현재 파일명
// 2. __LINE__: 소스코드 라인
//------
// 3. 매크로 상수는 아니고, 컴파일러가 동적으로 처리해주는
//    기능이 있습니다.
//    __func__: c99

#define LOG(message) \
  fprintf(stderr, "[%s(%s:%d)]: %s\n", __FILE__, __func__, __LINE__, message);

int main(void)
{
  LOG("hello1");
  LOG("hello2");

  return 0;
}