// 25_static2.cpp
#include <iostream>
using namespace std;

class Car {
    static int count;

public:
    Car() { ++count; }
    ~Car() { --count; }

    // int GetCount() { return count; }
    // 멤버 함수는 객체를 통해서만 호출이 가능합니다.

    // static int GetCount() { return count; }
    static int GetCount();
    // 정적 멤버 함수
    //  : 전역 함수와 동일한데, 클래스의 접근 지정자를 사용할 수 있습니다.
};

// static
int Car::GetCount()
{
    return count;
}

int Car::count = 0;

int main()
{
    int cnt = Car::GetCount();
    cout << cnt << endl;

    Car cars[5];
    cout << Car::GetCount() << endl;
}
