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

void PrintComplex1(Complex c)
{
    cout << c.re << ", " << c.im << endl;
}

// C Style
void PrintComplex2(const Complex* p)
{
    if (p) {
        cout << p->re << ", " << p->im << endl;
    }

    // p->im = 100;
}

// C++ Style
void PrintComplex3(const Complex& c)
{
    cout << c.re << ", " << c.im << endl;

    // c.re = 100;
}

int& foo()
{
    int n = 100;
    // return &n;

    return n;
}

int main()
{
    int& r = foo();
    r = 200; /* 이미 사라진 메모리에 대한 접근이 발생입니다. */
    // 미정의 동작

    Complex c1 { 10, 20 };

    PrintComplex1(c1);
    PrintComplex2(&c1);
}
