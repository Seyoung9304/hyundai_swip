// 32_연산자오버로딩6.cpp
#include <iostream>
using namespace std;

class Integer {
    int value;

public:
    Integer(int n = 0)
        : value(n)
    {
    }

    // ++i
    Integer& operator++()
    {
        ++value;
        return *this;
    }

    // i++
    Integer operator++(int)
    {
        Integer temp = *this; // 현재 값을 반환합니다.
        ++value;

        return temp;
    }

    // 일반 함수 입니다.
    friend ostream& operator<<(ostream& os, const Integer& i)
    {
        return os << i.value;
    }
};

int main()
{
    int n1 = 100;
    ++ ++n1;
    n1++;
    cout << n1 << endl;

    Integer n2 = 100; // Integer(int)
    ++ ++n2;
    // operator++()

    n2++;
    // operator++(int) : 구분을 위해서, 더미 타입 인자가 있습니다.

    cout << n2 << endl;
}
