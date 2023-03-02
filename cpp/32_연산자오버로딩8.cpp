// 32_연산자오버로딩8.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개도 제공하지 않으면, 컴파일러는 아무 일도 하지 않는
//    기본 생성자를 제공합니다.
// 2. 사용자가 복사 생성자를 제공하지 않으면, 컴파일러는 멤버 복사를 수행하는
//    기본 복사 생성자를 제공합니다.

// 3. 사용자가 대입 연산자를 제공하지 않으면, 컴파일러는 멤버 복사를 수해하는
//    기본 대입 연산자를 제공합니다.

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }

    Point(const Point& rhs)
        : x(rhs.x)
        , y(rhs.y)
    {
        cout << "Point(const Point& rhs)" << endl;
    }

    Point& operator=(const Point& rhs)
    {
        cout << "operator=" << endl;
        x = rhs.x;
        y = rhs.y;

        return *this;
    }
};

int main()
{
    int a, b;
    a = b = 10;

    Point pt1(10, 20);

    Point pt2 = pt1;
    pt2 = pt1;

    Point pt3(10, 20);
    pt3 = pt2 = pt1;

    // pt2.operator=(pt1)
}
