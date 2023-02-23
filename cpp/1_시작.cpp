// 1_시작.cpp

// 1. 확장자
// -   C: .c
// - C++: .cpp .cc .cxx

// 2. 컴파일러
// - MSVC, GCC, LLVM

// 3. C++ 표준
// - 98/03: 1.0
// - 11/14: 2.0, Modern C++
// - 17/20: 3.0

// 4. C++은 C언어를 지원합니다.
//  => C의 표준과 C++에서의 C의 표준은 다릅니다.

#include <stdio.h>

void foo() { }

int main()
{
    printf("Hello, C\n");
}
// main 함수의 return 구문을 생략하면,
// 컴파일러가 자동으로 return 0; 처리합니다.
