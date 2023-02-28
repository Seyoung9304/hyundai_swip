// 28_상속4.cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base()" << endl; } // 3
    ~Base() { cout << "~Base()" << endl; } // <4>
};

class Derived : public Base {
public:
    // 컴파일러는 생성자의 초기화리스트에서
    // 부모 클래스의 기본 생성자를 호출하는 코드를 삽입합니다.
    Derived()
    // : Base() - 2
    {
        cout << "Derived()" << endl; // 4
    }
    ~Derived()
    {
        cout << "~Derived()" << endl; // <2>

        // 컴파일러는 자식 소멸자의 마지막에 부모의 소멸자를
        // 호출하는 코드를 삽입합니다.
        // Base::~Base() <3>
    }
};

int main()
{
    Derived d;
    // Derived::Derived() - 1
}
// Derived::~Derived() - <1>