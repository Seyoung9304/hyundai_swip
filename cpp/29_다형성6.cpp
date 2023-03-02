// 29_다형성6.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void Go() const { cout << "Animal Go" << endl; }
};

// C++11에서 final을 통해 오버라이딩이 더이상 허용되지 않게 할 수 있습니다.
class Dog : public Animal {
public:
    // Template Method Pattern
    void Go() const override final { cout << "Dog Go" << endl; }
};

class Pomeranian : public Dog {
public:
    // void Go() const override { cout << "Pomeranian Go" << endl; }
};

int main()
{
    Dog d;
    Pomeranian pd;

    Animal* p = &pd;
    p->Go();
}