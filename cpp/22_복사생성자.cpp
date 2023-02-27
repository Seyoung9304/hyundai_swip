// 22_복사생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개로 제공하지 않으면,
//    컴파일러는 아무일도 수행하지 않는 기본 생성자를 제공합니다.
//    (단, 복사생성자가 생성되어 있다면 기본 생성자는 제공하지 않음)

// 2. 사용자가 자신과 동일한 타입을 인자를 받는 생성자(복사 생성자)를
//    제공하지 않으면, 컴파일러는 자동으로 멤버 데이터를 복사하는
//    복사 생성자를 제공합니다. 

#if 0
class Point {
    int x;
    int y;

public:
    // 복사 생성자 형태
    Point(const Point& rhs)
        : x(rhs.x)
        , y(rhs.y)
    {
        cout << "Point(const Point&)" << endl;
    }

    Point(int a, int b)
        : x { a }
        , y { b }
    {
        cout << "Point(int, int)" << endl;
    }

    void Print()
    {
        cout << x << ", " << y << endl;
    }
};

int main()
{
    Point pt { 10, 20 };
    pt.Print();

    Point pt2 = pt; // Point(const Point&)
    pt2.Print();

    Point pt3(pt);
    Point pt4 { pt };
    Point pt5 = { pt };
}
#endif

class Sample1 {
};
// 기본생성자, 복사생성자

class Sample2 {
public:
    Sample2(const Sample2&) { }
}
// 복사생성자(사용자), 기본 생성자는 제공되지 않습니다.
// => 3. 사용자가 복사 생성자를 제공하면, 기본 생성자는 제공되지 않습니다.
//   "복사생성자"도 생성자이기 때문입니다.
