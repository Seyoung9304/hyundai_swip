// 2_namespace3.cpp
#include <iostream>
// 1. C++ 헤더파일은 확장자를 사용하지 않는 경우가 많습니다.
// 2. 표준 라이브러리는 std 이름공간안에 존재합니다.

// #include <stdio.h>
#include <cstdio>

#if 0
namespace std {
#include <stdio.h>
}

#endif

#if 0
#include <cstdlib>
#include <cstring>

using std::printf; /* OK */
using namespace std; /* 비권장 */

int main()
{
    std::printf("Hello, C++\n");
}
#endif

// 이름없는 이름공간: Internal Linkage
namespace {
void foo()
{
    std::cout << "foo" << std::endl;
}

}

namespace hello {
void foo()
{
    std::cout << "hello foo" << std::endl;
    // foo();
    // 같은 이름 공간안의 foo를 우선 호출합니다.

    ::foo();
    // 전역 공간의 함수를 명시적으로 호출합니다.
}
}

int main()
{
    hello::foo();
    foo();
}