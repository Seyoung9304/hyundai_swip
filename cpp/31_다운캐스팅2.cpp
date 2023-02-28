// 31_다운캐스팅2.cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual ~Animal() { }

    virtual void Go() = 0;
};

class Dog : public Animal {
public:
    void Go() override { cout << "Dog Go" << endl; }
};

int main()
{
    Dog d;
    Animal* p = &d;

    // 다운 캐스팅
    // 1) static_cast
    // - 실패 가능성이 없는 다운 캐스트는 static_cast가 좋습니다.
    Dog* pDog2 = static_cast<Dog*>(p);
    pDog2->Go();

    // 2) dynamic_cast
    // - 실패 가능성이 있는 다운 캐스트는 dynamic_cast를 사용해야 합니다.
    Dog* pDog = dynamic_cast<Dog*>(p);
    if (pDog) {
        pDog->Go();
    }
}
