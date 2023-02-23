// 9_함수6.cpp
#include <iostream>
using namespace std;

// 최대 공약수
//  => 아래 함수는 정수를 대상으로하는 함수입니다.
int gcd(int a, int b)
{
    return b != 0 ? gcd(b, a % b) : a;
}

// double gcd(double a, double b);
// 1. 구현을 하지 않고, 선언만 제공합니다.
//  => 링크 오류 유도
/*
Undefined symbols for architecture arm64:
  "gcd(double, double)", referenced from:
      _main in 9_함수6-8963d5.o
*/

// 2. C++ - 함수 금지(Delete Function)
//  => 삭제한 함수를 호출하는 경우, 컴파일 오류가 발생합니다.
double gcd(double a, double b) = delete;

int main()
{
    cout << gcd(15, 30) << endl;
    // cout << gcd(3.14, 2.5) << endl; /* 컴파일 오류 */
}