// 4_변수2.cpp
#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
};

#if 0
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = 42;
    int x1[3] = { 1, 2, 3 };
    Point p1 = { 10, 20 };

    // Direct Initialization(직접 초기화)
    int n2(42);
    int x2[3] { 1, 2, 3 };
    Point p2 { 10, 20 };
}
#endif

// C++11 Uniform Initialization(일관된 초기화)
int main()
{
    // Copy Initialization(복사 초기화)
    int n1 = { 42 };

    int x1[3] = { 1, 2, 3 };
    Point p1 = { 10, 20 };

    // Direct Initialization(직접 초기화)
    int n2 { 42 };

    int x2[3] { 1, 2, 3 };
    Point p2 { 10, 20 };
}