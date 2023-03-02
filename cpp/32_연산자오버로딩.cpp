// 32_연산자오버로딩.cpp
#include <iostream>
using namespace std;

#if 0
class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }

    Point Add(const Point& rhs)
    {
        return Point(x + rhs.x, y + rhs.y);
    }

    void Print() const
    {
        cout << x << ", " << y << endl;
    }

    friend Point Add(const Point& lhs, const Point& rhs);
};

Point Add(const Point& lhs, const Point& rhs)
{
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

int main()
{
    Point pt1(10, 20);
    Point pt2(30, 40);

    // 1. 멤버 함수
    Point result1 = pt1.Add(pt2);
    result1.Print();

    // 2. 일반 함수
    Point result2 = Add(pt1, pt2);
    result2.Print();
}
#endif

class Point {
    int x;
    int y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }

#if 0
    // 1. 멤버 함수
    Point operator+(const Point& rhs)
    {
        return Point(x + rhs.x, y + rhs.y);
    }
#endif

    void Print() const
    {
        cout << x << ", " << y << endl;
    }

    friend Point operator+(const Point& lhs, const Point& rhs);
    friend Point operator+(const Point& lhs, int n);
};

Point operator+(const Point& lhs, const Point& rhs)
{
    return Point(lhs.x + rhs.x, lhs.y + rhs.y);
}

// 연산자 오버로딩
// 정의: 객체를 대상으로 연산자를 사용할 경우,
//      약속된 이름의 멤버 함수 또는 일반 함수가 호출됩니다.

// 1. 연산자 우선순위는 변경되지 않습니다.
// 2. 피연산자의 개수도 변경되지 않습니다.
// 3. 새로운 연산자도 제공할 수 없습니다.
// 4. 연산자 오버로딩이 허용되지 않는 연산자도 있습니다.
//   ::(범위 연산자), .(접근 연산자), .*(멤버 함수 포인터 접근 연산자)
//   ?:(3항 연산자)

// 5. 반드시 피 연산자 중 하나는 사용자 정의 타입이어야 합니다.
// int operator+(int a, int b) { return a + b; } => 불가능
Point operator+(const Point& lhs, int n)
{
    return Point(lhs.x + n, lhs.y + n);
}

// 6. 반드시 멤버 함수를 통해서만 제공해야하는 연산자가 있습니다.
// => 클래스의 제작자만 제공할 수 있는 연산자 재정의 함수입니다.
//  1) 대입 연산자
//     a = b;
//  2) 호출 연산자
//     a();
//  3) 임의 접근 연산자
//     a[0] = 10;
//  4) 객체 포인터 연산자
//     a->member = 20;
//  5) 포인터 접근 연산자
//     *a = 10;

int main()
{
    Point pt1(10, 20);
    Point pt2(30, 40);

    Point pt3 = pt1 + 10;
    pt3.Print();

    Point result1 = pt1 + pt2;
    // 1. 멤버 함수
    // Point result1 = pt1.operator+(pt2);

    // 2. 일반 함수
    // Point result1 = operator+(pt1, pt2);

    result1.Print();
}