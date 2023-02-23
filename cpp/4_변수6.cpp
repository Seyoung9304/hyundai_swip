// 4_변수6.cpp
#include <iostream>
using namespace std;

// auto
// => 우항의 표현식을 통해 타입을 추론합니다.

// decltype
// => 지정된 타입과 동일한 타입으로 변수를 생성할 수 있습니다.

// auto, decltype: C++11
int main()
{
    const int c = 42;
    auto n = c; // n: int

    // c와 동일한 타입을 만들고 싶다.
    decltype(c) c2 = c; // c2: const int
    // c2 = 42;

    double d = 3.14;
    decltype(d) d2; // 초기화가 필요하지 않습니다.
}