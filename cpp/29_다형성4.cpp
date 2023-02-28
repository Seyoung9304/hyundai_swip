// 29_다형성4.cpp
// => 중요합니다.
#include <iostream>
using namespace std;

// 1. 부모가 제공하는 함수를 자식 클래스가 동일한 함수를 재정의할 수 있습니다.
//  => 함수 오버라이딩(Overriding)
class Animal {
public:
    virtual void Go() const { cout << "Animal Go" << endl; }
};

class Dog : public Animal {
public:
    virtual void Go() const { cout << "Dog Go" << endl; }
};

// 함수 바인딩(Binding): 어떤 함수를 호출할지 결정하는 것
//    p->Go();

// 1. 정적 바인딩(static binding)
//  => 어떤 함수를 호출할지 컴파일러가 결정하는 것
//     p의 타입을 통해 결정합니다.

// 2. 동적 바인딩(dynamic binding)
//  => 어떤 함수를 호출할지 런타임에 결정하는 것
//     실행시간에 p가 참조하는 객체의 타입을 조사해서, 결정합니다.
// virtual: 멤버 함수의 호출 방식을 동적 바인딩으로 변경합니다.

int main()
{
    Animal a;
    Dog d;

    Animal* p = &a;
    p->Go();

    p = &d;
    p->Go();
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