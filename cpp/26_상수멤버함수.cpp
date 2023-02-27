// 26_상수멤버함수.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }

    // 상수 멤버 함수
    //  - 멤버 함수 내에서 멤버 데이터를 수정하지 않는다.
    //  - 멤버 데이터를 상수 취급합니다.
    //    x -> int -> const int
    //    y -> int -> const int
    // 결론: 멤버 함수 내에서 멤버의 값을 변경하지 않는다면,
    //      반드시 상수 멤버 함수로 만들어야 합니다.
    void Print() const
    {
        // x = 100;
        // y = 100;
        cout << x << ", " << y << endl;
    }
};

// void foo(Point p)
void foo(const Point& p)
{
    p.Print();
}

int main()
{
    Point p(10, 20);
    // foo(p);

    // 1. const&
    const Point& r1 = p;
    r1.Print(); // 상수 멤버 함수만 호출 가능합니다.

    // 2. 상수 객체
    const Point p2(10, 20);
    p2.Print(); // 상수 멤버 함수만 호출 가능합니다.
}