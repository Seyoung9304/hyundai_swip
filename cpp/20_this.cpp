// 20_this.cpp
#include <iostream>
using namespace std;

class Point {
    int x;
    int y;

public:
    // void Set(Point* const this, int a, int b)
    void Set(int a, int b)
    {
        cout << this << endl;
        x = a;
        // this->x = a;
        y = b;
        // this->y = b;
    }
};

int main()
{
    Point p1, p2;
    cout << "main: " << &p1 << endl;
    p1.Set(10, 20); // Point::Set(&p1, 10, 20);
    cout << "main: " << &p2 << endl;
    p2.Set(30, 40); // Point::Set(&p2, 30, 40);
}