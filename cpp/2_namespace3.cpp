// 2_namespace3.cpp
#include <iostream>
// 1. C++ 헤더파일은 확장자를 사용하지 않는 경우가 많습니다.
// 2. 표준 라이브러리는 std 이름공간안에 존재합니다.

// #include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using std::printf; /* OK */
using namespace std; /* 비권장 */

int main()
{
    std::printf("Hello, C++\n");
}