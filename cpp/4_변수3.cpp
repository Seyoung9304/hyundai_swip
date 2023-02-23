// 4_변수3.cpp
#include <iostream>
using namespace std;

// 1. 부동 소수점 타입 정수 타입으로의 암묵적인 변환이 허용됩니다.
// 2. Uniform Initialization에서는 부동 소수점에서 정수 타입으로의 암묵적인 변환이 허용되지 않습니다.
// 3. 표현 범위가 더 큰 정수를 더 작은 정수 타입으로의 암묵적인
//   변환은 허용됩니다.
//   => Uniform Initialization에서는 허용되지 않습니다.
//  "Preventing Narrow"

int main()
{
    double d = 3.14;
    int x = d;
    cout << x << endl;

    // int x2 = { d }; /* Compile Error */
    int x2 = { (int)d };
    cout << x2 << endl;

    int n = 400;
    // signed char r { n }; /* Compile Error */
    signed char r { (signed char)n };
}