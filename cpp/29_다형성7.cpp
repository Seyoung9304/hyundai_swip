// 29_다형성7.cpp
#include <iostream>
using namespace std;

// 가상 소멸자
//  1. 부모 클래스의 소멸자가 가상이면, 자식 소멸자도 가상입니다.
//  2. 부모 클래스의 소멸자는 반드시 가상이어야 합니다.
//  => C++은 상속을 금지하는 키워드가 없습니다.
//     하지만 일반적으로 부모 클래스의 소멸자가 가상 소멸자가 아니면
//     상속을 위해 설계된 클래스가 아닙니다.

class Animal {
public:
    Animal() { cout << "Animal()" << endl; }
    virtual ~Animal() { cout << "~Animal()" << endl; }
};

class Dog : public Animal {
public:
    Dog() { cout << "Dog()" << endl; }
    ~Dog() override { cout << "~Dog()" << endl; }
    // 부모 소멸자가 가상인지 아닌지 확인할 수 있습니다.
};

int main()
{
    Animal* p = new Dog;
    // Dog::Dog()

    delete p;
    // Animal::~Animal() <- 정적 바이딩
}

#if 0
int main()
{
    Dog d;
}
#endif