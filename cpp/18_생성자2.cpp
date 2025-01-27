// 18_생성자2.cpp
#include <iostream>
using namespace std;

#include <cstdlib>

// 1. malloc을 통해서 객체를 생성하면,
//    생성자가 호출되지 않습니다.
// 2. new를 통해서 객체를 생성하면, 생성자가 호출됩니다.
// 3. free를 통해 객체를 해지하면, 소멸자가 호출되지 않습니다.
// 4. delete를 통해 객체를 해지하면, 소멸자가 호출됩니다.

// new
// 1) 동적 메모리 할당
// 2) 생성자 호출

// delete
// 1) 소멸자 호출
// 2) 동적 메모리 해지

class Point {
public:
    Point() { cout << "Point()" << endl; }
    Point(int a, int b) { cout << "Point(int, int)" << endl; }

    ~Point() { cout << "~Point()" << endl; }
};

int main()
{
    // Point* p1 = new Point; // Point::Point();
    // Point* p2 = new Point(); // Point::Point();

    // Point* p3 = new Point(10, 20); // Point::Point(int, int)
    // Point* p4 = new Point { 10, 20 }; // Point::Point(int, int)

    // Point* p5 = new Point[3];
    Point* p5 = new Point[3] {
        { 10, 20 },
        {},
        { 20, 30 },
    };
}

#if 0
int main()
{
    Point* p1 = static_cast<Point*>(malloc(sizeof(Point)));
    free(p1);

    Point* p2 = new Point;
    delete p2;
}
#endif