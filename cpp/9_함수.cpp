// 9_함수.cpp
#include <iostream>
using namespace std;

// 기본 파라미터(default parameter)
//  정의: 함수의 파라미터의 기본값을 지정할 수 있습니다.
//       함수에 전달된 인자가 없는 경우, 파라미터의 기본값을 컴파일러가
//       자동으로 처리합니다.
//    1) 뒤에서 부터 지정해야 합니다.
//    2) 함수의 선언부만 써야된다.

// int add(int a, int b, int c = 0, int d = 0)
// {
//     return a + b + c + d;
// }

// 함수 선언부 => 헤더 파일
int add(int a, int b, int c = 0, int d = 0);

int main()
{
    cout << add(10, 20) << endl; // add(10, 20, 0, 0)
    cout << add(10, 20, 30) << endl; // add(10, 20, 30, 0)
    cout << add(10, 20, 30, 40) << endl;

    // cout << add(10, 20, 0, 0) << endl;
    // cout << add(10, 20, 30, 0) << endl;
    // cout << add(10, 20, 30, 40) << endl;
}

// 함수 정의부 => 소스 파일
int add(int a, int b, int c /* = 0 */, int d /* = 0 */)
{
    return a + b + c + d;
}