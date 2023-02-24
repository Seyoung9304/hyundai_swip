// 4_변수5.cpp

#include <iostream>
using namespace std;

// auto는 타입을 추론합니다.
//  => Type deduction(타입 연역)
int main()
{
    int n = 10; // n: int
    const int c = 20; // c: const int

    auto an = n; // an: int
    // auto ac = c; // ac: int

    const auto ac = c; // ac: const int
    // ac = 42; /* compile error */

    int& r = n; // int&
    r = 100;
    cout << n << endl;

    // auto r2 = r; // auto -> int
    auto& r2 = r;
    r2 = 200;
    cout << n << endl;
}