// 21_초기화리스트.cpp
#include <iostream>
using namespace std;

// 1. 초기화와 대입의 차이를 알아야 합니다.
#if 0
int main()
{
    int a = 10; // 초기화

    int b;
    b = 10; // 대입
}
#endif

// 2. C++에서는 반드시 초기화가 필요한 것이 있습니다.
// 1) const
// 2) reference
#if 0
class Sample {
    int a;

public:
    Sample(int n)
    {
        a = n; // 대입
    }
};
#endif
// 3. 생성자에서 멤버 데이터에 대한 초기화를 수행하기 위해서는
//   "초기화 리스트" 문법이 필요합니다.
#if 1
class Sample {
    const int a_;
    int& b_;

public:
    Sample(int a, int& b)
        : a_(a)
        , b_(b)
    {
        // a = aa; /* 대입*/
        // b = ab; /* 대입*/
    }

    void Print()
    {
        cout << a_ << ", " << b_ << endl;
    }
};

int main()
{
    int n = 20;
    Sample s(10, n);

    n = 42;
    s.Print();

    // const int c;
    // int& r;
}
#endif

// 4. 멤버 데이터의 초기화 순서는 초기화리스트의 순서가 아닌 선언 순서에 의해 결정됩니다.
class Point {
    int x;
    int y;

public:
    // 5. 초기화 리스트의 순서는 멤버 데이터의 선언 순서와 동일하게
    // 사용해야 합니다.
    Point(int a, int b)
        // : y(a + b), x(y)
        : x(a + b)
        , y(x)
    {
    }
};

// 5. 초기화리스트를 반드시 사용해야 하는 경우
//  1) const 멤버 데이터
//  2) 참조 멤버 데이터

int main()
{
}