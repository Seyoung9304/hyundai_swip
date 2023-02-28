// 22_복사생성자5.cpp
#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // Point() {}
    // Point(const Point& rhs) : x(rhs.x), y(rhs.y) {}
};

// 1. 컴파일러는 사용자가 생성자를 1개도 정의하고 있지 않다면,
//    아무일도 하지 않는 기본 생성자를 만들어줍니다.
// 2. 컴파일러는 사용자가 복사 생성자를 정의하지 않는다면,
//    멤버를 복사하는 복사 생성자를 만들어줍니다.

int main()
{
    Point pt;

    // 복사 생성자가 호출되는 형태
    Point pt2 = pt;
    Point pt3(pt);
    Point p4 = { pt };
    Point p5 { pt };
}