// 12_레퍼런스3.cpp
#include <iostream>
using namespace std;

// 1. 반드시 초기화가 필요합니다.
//  => 레퍼런스는 널 레퍼런스가 존재하지 않습니다.
#if 0
int main()
{

    // int& r;
    int* p = NULL;
}
#endif

struct Complex {
    int re;
    int im;
};

void printComplex(const Complex& r)
{
    // r.re = 100; /* 컴파일 에러 */
    cout << r.re << ", " << r.im << endl;
}

void printComplex(const Complex* p)
{
    if (!p) {
        return;
    }

    cout << p->re << ", " << p->im << endl;
}

int main()
{
    printComplex(NULL);
}

#if 0
void printComplex(Complex c)
{
}
#endif