// 32_연산자오버로딩5.cpp
#include <iostream>

namespace xstd {
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(char c)
    {
        printf("%c", c);
        return *this;
    }

    ostream& operator<<(double d)
    {
        printf("%lf", d);
        return *this;
    }

    // endl을 위한 operator<< 멤버 함수
    ostream& operator<<(ostream& (*f)(ostream& os))
    {
        return f(*this);
    }
};
ostream cout;

// ostream& (*f)(ostream& os)
ostream& endl(ostream& os)
{
    return os << '\n';
}

}

using namespace std;

// 1. endl은 함수입니다. => IO 조정자
// 2. cout << endl;
//   > cout.operator<<(endl)
//     cout.operator<<(ostream& (*f)(ostream&))

// 3. 다양한 사용자 정의 IO 조정자 함수를 정의할 수 있습니다.
ostream& menu(ostream& os)
{
    os << "1. 짜장면" << endl;
    os << "2. 짬뽕" << endl;

    return os;
}

int main()
{
    cout << menu;

    int n = 42;
    cout << n;

    endl(cout);
    cout << endl;

    // cout << endl;
}