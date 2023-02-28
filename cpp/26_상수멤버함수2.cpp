// 26_상수멤버함수2.cpp
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

    void Print() const
    {
        cout << x << ", " << y << endl;
    }

    void Set(int a, int b)
    {
        x = a;
        y = b;
    }
};

class Rect {
    Point leftTop;

public:
    Rect(int x, int y)
        : leftTop(x, y)
    {
    }

    // 1. 상수 멤버 함수는 멤버의 타입을 const로 취급합니다.
    //    leftTop: Point -> const Point
    // 2. const Point에 대한 참조는 const&를 사용해야 합니다.
    const Point& GetLeftTop() const
    {
        return leftTop;
    }

    // 3. 상수 멤버 함수와 비상수 멤버 함수를 동시에 제공할 수 있습니다.
    Point& GetLeftTop()
    {
        return leftTop;
    }
};

// 1. 상수 멤버 함수만 제공할 경우
//       Sample s;  -> 상수 멤버 함수
// const Sample s;  -> 상수 멤버 함수
// const Sample* s; -> 상수 멤버 함수
// const Sample& s; -> 상수 멤버 함수

// 2. 비상수 멤버함수와 상수 멤버 함수를 제공할 경우
//       Sample s;  -> 비상수 멤버 함수
// const Sample s;  -> 상수 멤버 함수
// const Sample* s; -> 상수 멤버 함수
// const Sample& s; -> 상수 멤버 함수

// 3. 비상수 멤버함수만 제공할 경우
//       Sample s;  -> 비상수 멤버 함수
// const Sample s;  -> X
// const Sample* s; -> X
// const Sample& s; -> X

int main()
{
    Rect rect(10, 20);

    const Point& p = rect.GetLeftTop();
    p.Print();

    Point& p2 = rect.GetLeftTop();
    p2.Print();
    p2.Set(10, 20);
}