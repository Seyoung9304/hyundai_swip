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
class Sample {
    const int a;
    int& b;

public:
    Sample(int aa, int& ab)
        : a(aa)
        , b(ab)
    {
    }

    void Print()
    {
        cout << a << ", " << b << endl;
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