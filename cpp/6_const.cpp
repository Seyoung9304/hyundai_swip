// 6_const.cpp
#include <iostream>
using namespace std;

// 1. const 반드시 초기화되어야 합니다.
// 2. C에서는 실행 시간에 값을 변경할 수 없는 런타임 상수로만
//    해석되지만, C++은 컴파일 타임에 값이 결정될 경우,
//    컴파일 상수로 사용될 수 있습니다.

// 컴파일 상수
//  - 값이 컴파일 타임에 결정됩니다.
//    상수에 대한 접근은 메모리에 대한 접근이 아닙니다.

// 런타임 상수
//  - 상수의 값이 컴파일 타임에 결정될 수 없을 경우, 런타임 상수가
//    됩니다.
//  - 값을 변경할 수 없지만, 값을 읽을 때, 메모리에서 읽어야 합니다.

// C++11: constexpr
//   - C++11, 컴파일 상수에서만 사용할 수 있습니다.

int main()
{
    // 컴파일 상수
    constexpr int c1 = 42; // const int

    // 런타임 상수
    int n;
    cin >> n;
    const int c2 = n;
    // constexpr int c2 = n; /* 컴파일 오류 */

    printf("%d\n", c1);
    printf("%d\n", c2);
}