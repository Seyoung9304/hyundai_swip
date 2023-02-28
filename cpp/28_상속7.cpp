// 28_상속7.cpp
#include <iostream>
using namespace std;

// 1. private 생성자
//  - 자식 클래스도 객체를 생성할 수 없습니다.

// 2. protected 생성자
//  => Animal 객체는 생성할 수 없지만,
//     Animal 자식 객체는 생성할수 있습니다.

// 추상적인 개념으로 사용하겠다.
class Animal {
protected:
    Animal() { }
};

class Dog : public Animal {
public:
    Dog()
        : Animal()
    {
    }
};

int main()
{
    // Animal a; // 에러!
    Dog d;
}