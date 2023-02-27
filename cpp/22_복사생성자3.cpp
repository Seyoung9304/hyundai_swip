// 22_복사생성자3.cpp
#include <iostream>
using namespace std;

class Complex {
    int re;
    int im;

public:
    Complex()
        : re(0)
        , im(0)
    {
    }

    Complex(int r, int i)
        : re(r)
        , im(i)
    {
    }

    Complex(const Complex& rhs)
        : re(rhs.re)
        , im(rhs.im)
    {
        cout << "Complex(const Complex&)" << endl;
    }

    friend Complex Add(const Complex& lhs, const Complex& rhs);
};

// 지역 객체의 참조를 반환하면 안됩니다.
// => RVO(Return Value Optimization, 반환값 최적화)
//  : 지역 객체를 값으로 반환하면, 컴파일러는 임시 객체의 생성 비용을 제거하는
//    최적화를 수행합니다.

// RVO 최적화
#if 0
Complex Add(const Complex& lhs, const Complex& rhs)
{
    return Complex(lhs.re + rhs.re, rhs.im + lhs.im);
    // 임시 객체 생성 문법 => RVO 최적화
}
#endif

// 최신 컴파일러는 NRVO를 지원합니다.
//  : NRVO(Named RVO)

#if 1
Complex Add(const Complex& lhs, const Complex& rhs)
{
    Complex result;
    result.im = lhs.im + rhs.im;
    result.re = lhs.re + rhs.re;
    return result;
}
#endif

int main()
{
    Complex c1(10, 20);
    Complex c2(20, 30);

    Add(c1, c2);
}
