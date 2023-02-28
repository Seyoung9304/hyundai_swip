// 30_추상클래스.cpp
#include <iostream>
using namespace std;

// 순수 가상 함수를 1개라도 가지는 클래스는
// 객체를 생성할 수 없습니다.
//  "추상 클래스(abstract class)"
class Shape {
public:
    virtual ~Shape() { }

    // 부모의 입장에서 구현을 제공할 필요가 없고,
    // 자식 클래스 입장에서는 반드시 구현해야 합니다.
    //  : 순수 가상 함수(pure virtual function)
    virtual void Draw() const = 0;
    virtual Shape* Clone() = 0;
};

// 자식 클래스가 부모가 제공하는 순수 가상 함수를 오버라이딩 하지 않는다면,
// 자식 클래스도 추상 클래스가 됩니다.
class Rect : public Shape {
public:
    void Draw() const override { }
    Shape* Clone() override { return new Rect(*this); }
};

int main()
{
    // Shape s;
    Rect r;
}