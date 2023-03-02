// 32_연산자오버로딩4.cpp
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

    friend ostream& operator<<(ostream& os, const Point& pt);
    friend istream& operator>>(istream& is, Point& pt);
};

ostream& operator<<(ostream& os, const Point& pt)
{
    return os << pt.x << ", " << pt.y;

    // return os;
}

istream& operator>>(istream& is, Point& pt)
{
    return is >> pt.x >> pt.y;
}

int main()
{
    Point pt(10, 20);

    cin >> pt;
    // cin.operator>>(Point&)
    // operator>>(cin, Point&) => 제공하면 됩니다.

    cout << pt;
    // cout.operator<<(pt);
    // operator<<(cout, pt); => 일반 함수를 만들면 됩니다.
}