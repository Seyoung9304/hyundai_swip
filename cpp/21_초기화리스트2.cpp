// 21_초기화리스트2.cpp
#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    Point(int a, int b)
        : x(a)
        , y(b)
    {
    }
};

// 초기화리스트를 통해 초기화해야 하는 경우
// 3. 클래스의 멤버 데이터 객체가 기본 생성자를 제공하지 않는 경우
// => 명시적으로 생성자를 호출하는 코드를
//    초기화리스트를 통해 제공해야 합니다.

class Rect {
    Point leftTop;
    Point rightBottom;

public:
    Rect(int x1, int y1, int x2, int y2)
        : leftTop(x1, y1)
        , rightBottom(x2, y2)
    {
    }

    Rect()
        : leftTop(0, 0)
        , rightBottom(100, 200)
    {
    }

// 컴파일러는 멤버 데이터의 기본 생성자를 호출하는 코드를
// 생성합니다.
#if 0
    Rect()
        : leftTop()
        , rightBottom()
    {
    }
#endif
};

int main()
{
    Rect r;
}