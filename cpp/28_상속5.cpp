// 28_상속5.cpp
#include <iostream>
using namespace std;

// 부모 클래스가 기본 생성자를 제공하지 않을 경우,
// 자식 클래스의 생성자의 초기화 리스트를 통해,
// 부모 생성자를 명시적으로 호출해야 합니다.

class Base {
public:
    Base(int n) { cout << "Base(int)" << endl; }
    Base(int a, int b) { cout << "Base(int, int)" << endl; }
};

class Derived : public Base {
public:
    // Derived() : Base() {}

    Derived()
        // : Base(10) // -> Base::Base(int)
        : Base(10, 20) // -> Base::Base(int, int)
    {
    }
};

int main()
{
    Derived d;
}