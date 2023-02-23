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

#if 0
#include <stdio.h>

void foo() { }

int main()
{
    printf("Hello, C\n");
}
// main 함수의 return 구문을 생략하면,
// 컴파일러가 자동으로 return 0; 처리합니다.
#endif

// 5. C++은 표준 입출력 라이브러리가 있습니다.
#include <iostream>
// C++의 표준 입출력 헤더파일 입니다.
//  Input Output Stream

// 표준 출력: std::cout -> stdout
// 표준 입력: std::cin  -> stdin
#if 0
int main()
{
    // std::cout << "Hello, C++" << std::endl;

    int n = 42;
    double d = 3.14;
    char c = 'A';

    printf("%d %lf %c\n", n, d, c);

    // - 서식을 지정하지 않아도 타입에 따라서 원하는 형태로
    //   처리됩니다.
    std::cout << n << ", "
              << d << ", " << c << std::endl;
}
#endif

int main()
{
    double n;
    // scanf("%d", &n);
    // printf("%d\n", n);

    std::cin >> n;
    std::cout << n << std::endl;
}