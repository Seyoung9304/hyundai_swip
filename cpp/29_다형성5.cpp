// 29_다형성5.cpp
#include <iostream>
using namespace std;

// 1. 자식이 오버라이딩한 부모의 멤버 함수가 가상함수이면,
//    자식의 함수도 가상함수 입니다.

// 2. virtual 문제점
//   규칙: 자식이 재정의(오버라이딩)하는 함수는 반드시 가상함수이어야 합니다.
//        "부모가 제공하는 가상함수만 오버라이딩 해야 합니다."

// 3. C++11에서 새로운 키워드가 도입되었습니다.
//  => override
//  1) 자식이 재정의한 멤버 함수가 부모에서 존재하는지 확인할 수 있습니다.
//  2) 부모가 제공하는 멤버 함수가 가상함수가 아니면 허용되지 않습니다.

class Animal {
public:
    virtual void Hello() const { cout << "Animal Go" << endl; }
};

class Dog : public Animal {
public:
    // virtual void Hello() const { cout << "Dog Go" << endl; }

    // virtual void Hello() const override { cout << "Dog Go" << endl; }

    void Hello() const override { cout << "Dog Go" << endl; }
};

int main()
{
    Dog d;
    Animal* p = &d;

    p->Hello();
}

#if 0
int main()
{
    Animal a;
    a.Go();

    Dog d;
    d.Go();
}
#endif