// 18_생성자.cpp
#include <iostream>
using namespace std;

// 1. 사용자가 생성자를 1개로 제공하지 않으면,
//    컴파일러가 아무일도 수행하지 않는 인자 없는 생성자를 만들어줍니다.
//    => 기본 생성자(Default Constructor)
#if 0
class Point {
    int x;
    int y;

    // 컴파일러가 만들어주는 기본 생성자 형태
    // public:
    //     Point() { }
};

int main()
{
    Point p1; // Point::Point() => OK
    // Point p2(10, 20); // Point::Point(int,int) => NO
}
#endif

// 2. 사용자가 생성자를 1개라도 제공하면,
//    컴파일러는 기본 생성자를 제공하지 않습니다.

// 3. 기본 생성자는 오버로딩을 통해 제공하는 것이 좋을 때가 많습니다.

// 4. 생성자는 인자 정보에 따른 오버로딩이 가능합니다.
//  "객체를 생성하는 다양한 방법을 제공할 수 있습니다."

class Point {
    int x;
    int y;

public:
    // Point()
    // {
    //     x = 0;
    //     y = 0;
    // }

    Point(int a, int b)
    {
        x = a;
        y = b;
    }
};

int main()
{
    // Point p1; // Point::Point() => NO!
    Point p2(10, 20); // Point::Point(int,int)
}