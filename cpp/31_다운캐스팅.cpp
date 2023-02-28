// 31_다운캐스팅.cpp
#include <iostream>
using namespace std;

// 1. 부모 포인터(참조) 타입을 자식 포인터(참조) 타입으로의 암묵적인
//    변환은 허용되지 않습니다.
//    => 명시적인 캐스팅이 필요합니다.
//      1) static_cast
//      2) reinterpret_cast
//      3) const_cast
//      4) dynamic_cast

class Animal {
public:
    virtual ~Animal() { } // 가상 소멸자
};

class Dog : public Animal {
    int color = 42;

public:
    int GetColor() const { return color; }
};

int main()
{
    Dog d;
    Animal a;
    Animal* p = &a;
    // Animal* p = &d;

    // 해결방법 1.
    //  p의 대상체 타입이 Dog 타입인지 확인해서, 캐스팅을 수행해야 합니다.
    //   : RTTI(Run Time Type Information)
    // 1) type_info 구조체
    //   - 가상 함수 테이블에 존재합니다.
    // 2) typeid 연산자
    //    typeid(클래스) => 클래스의 type_info 구조체
    //    typeid(객체)  => 객체의 type_info 구조체
    if (typeid(*p) == typeid(Dog)) /* Dog 타입 */
    {
        Dog* pDog = static_cast<Dog*>(p);
        cout << pDog->GetColor() << endl;
    } else {
        cout << "Dog 타입이 아닙니다." << endl;
    }

    // 해결방법 2. dynamic_cast
    //  : 다운 캐스팅 전용 캐스트 연산자
    //   잘못된 타입이 전달된 경우, 캐스팅의 결과로 nullptr을 반환합니다.
    Dog* pDog = dynamic_cast<Dog*>(p);
    if (pDog) {
        cout << pDog->GetColor() << endl;
    } else {
        cout << "Dog 타입이 아닙니다." << endl;
    }
}