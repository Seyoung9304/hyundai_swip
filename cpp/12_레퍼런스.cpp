// 12_레퍼런스.cpp
#include <iostream>
using namespace std;

// C++ 에서는 레퍼런스 타입이 존재합니다.
// => 기존 메모리에 새로운 이름(별명)을 부여합니다.
#if 0
int main()
{
    int n = 100;

    int& r = n;

    r = 200;
    cout << n << endl;

    n = 100;
    cout << r << endl;

    int x = 10;
    int& rx = x;

    // int& rx; /* 에러! 반드시 초기화가 필요합니다. */
}
#endif

#if 0
int main()
{
    int n = 100;

    int* p = &n;

    *p = 200;
    cout << n << endl;

    n = 100;
    cout << *p << endl;
}
#endif