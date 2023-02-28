// 29_다형성.cpp
#include <iostream>
using namespace std;

class Animal {
};

class Dog : public Animal {
};

// 1. Upcasting: 부모 클래스의 포인터(참조) 타입을 통해 자식 객체를
//               참조할 수 있습니다.
//  Animal
//    ^
//    |
//   Dog

// 2. is-a 관계
//    <자식 클래스> is a <부모 클래스>

int main()
{
    Animal a;
    Dog d;

    Animal* p1 = &a;

    // 자식 클래스의 주소(참조) 타입이 부모 클래스의 주소(참조) 타입으로의
    // 암묵적인 변환이 허용됩니다.
    Animal* p2 = &d;
    Animal& r = d;
}