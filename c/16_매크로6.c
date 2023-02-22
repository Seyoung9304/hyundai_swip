// 16_매크로6.c
#include <stdio.h>

// 가변인자 함수
//  : printf, scanf

// 가변인자 매크로 함수: ... -> __VA_ARGS__
#define LOG(...) printf(__VA_ARGS__)

int main(void)
{
    LOG("hello\n");
    LOG("hello: %d\n", 10);
    LOG("hello: %d %d\n", 10, 10);
    LOG("hello: %d %d %d\n", 10, 10, 10);

    return 0;
}