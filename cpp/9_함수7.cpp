// 9_함수7.cpp
#include <iostream>
using namespace std;

// int add(int a, int b) { return a + b; }

// C++11: 함수를 만드는 새로운 문법
//  "Trailing Return Type"
auto add(int a, int b) -> int { return a + b; }

// int (*foo())[3]
auto foo() -> int (*)[3]
{
    static int x[3];
    return &x; // int(*)[3]
}

// int (*(*goo())())[3]
auto goo() -> int (*(*)())[3]
{
    return &foo; // int (*(*)())[3]
}

// decltype(a+b) add2(int a, int b) { return a + b; } /* 에러 */
auto add2(int a, int b) -> decltype(a + b) /* OK */
{
    return a + b;
}

// 반환타입을 명시하지 않아도 됩니다. => 반환타입 추론
auto add3(int a, int b)
{
    return a + b;
}

int main()
{
    cout << add3(10, 20) << endl;
    cout << add(10, 20) << endl;
}