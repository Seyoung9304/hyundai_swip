// 29_다형성9.cpp
#include <iostream>
using namespace std;

// <가상 함수 비용>
// 1. 가상함수는 가지는 객체의 크기는 가상 함수 테이블을 가르키는
//    포인터 크기 만큼 증가합니다.
// 2. 가상함수 테이블의 비용
//     타입 * 가상 함수 개수 * 포인터 크기

class Animal {
    int color;

public:
    virtual void Go() { cout << "Animal Go" << endl; }
    virtual void Hello() { cout << "Animal Go" << endl; }
};

class Dog : public Animal {
public:
    void Go() override { cout << "Dog Go" << endl; }
};

int main()
{
    cout << sizeof(Animal) << endl;
}

#if 0
int main()
{
    Animal a;
    Dog d;

    Animal* p = &a;
    p->Go();

    p = &d;
    p->Go();
}
#endif