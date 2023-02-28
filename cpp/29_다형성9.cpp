// 29_다형성9.cpp
#include <iostream>
#include <vector>
using namespace std;

// 1. 각 도형의 클래스를 설계합니다.
#if 0
class Rect {
public:
    void Draw() const { cout << "Rect Draw" << endl; }
};

class Circle {
public:
    void Draw() const { cout << "Circle Draw" << endl; }
};

int main()
{
    vector<Rect*> rects;
    vector<Circle*> circles;
}
#endif

// 2. 부모 클래스를 도입합니다.
//  => 하나의 컨테이너에 모든 도형을 보관할 수 있습니다.
//  "연관된 클래스를 묶어서 관리할 수 있습니다."
//   : 동종을 보관하는 컨테이너

// 3. 자식 클래스의 공통의 기능을 부모의 포인터(참조)를 통해 이용하기 위해서는
//    반드시 해당 기능이 부모를 통해서 제공되어야 합니다.
//    그래야지만 해당 기능을 부모의 포인터를 통해서 이용할 수 있습니다.

// 4. 자식이 오버라이딩(재정의)하는 모든 함수는 반드시 가상이어야 한다.
// 5. 부모 클래스의 소멸자는 반드시 가상이어야 합니다.

class Shape {
public:
    virtual ~Shape() { } // !!!
    virtual void Draw() const { cout << "Shape Draw" << endl; }
};

class Rect : public Shape {
public:
    void Draw() const override { cout << "Rect Draw" << endl; }
};

class Circle : public Shape {
public:
    void Draw() const override { cout << "Circle Draw" << endl; }
};

int main()
{
    vector<Shape*> shapes;

    while (1) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            shapes.push_back(new Rect);
        } else if (cmd == 2) {
            shapes.push_back(new Circle);
        } else if (cmd == 9) {

            for (Shape* e : shapes) {
                e->Draw();
            }
        } else if (cmd == 0) {
            break;
        }
    }

    for (Shape* e : shapes) {
        delete e;
    }
}