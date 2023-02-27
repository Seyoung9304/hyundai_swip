// 20_this.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

    // m_x, m_y
    // _x, _y
    // x_, y_   => C++ 표준 형식
    // mX, mY

public:
    // 멤버함수는 this가 암묵적으로 전달됩니다.
    // => this는 객체의 주소입니다.
    void foo() // foo(Point* const this)
    {
    }

    // void Set(Point* const this, int a, int b)
    void Set(int a, int b)
    {
        foo();
        // this->foo();
        // foo(this);

        cout << this << endl;
        x = a;
        // this->x = a;
        y = b;
        // this->y = b;
    }

    void SetX(int x)
    {
        // this 이름을 명시적으로 지정해야합니다.
        this->x = x;
    }
};

#if 0
int n = 100;
void foo()
{
    int n = 200;
    ::n = 10;

    cout << n << endl;
}

int main()
{
    foo();
    cout << n << endl;
}
#endif

#if 0
int main()
{
    Point p1, p2;
    cout << "main: " << &p1 << endl;
    p1.Set(10, 20); // Point::Set(&p1, 10, 20);
    cout << "main: " << &p2 << endl;
    p2.Set(30, 40); // Point::Set(&p2, 30, 40);
}
#endif