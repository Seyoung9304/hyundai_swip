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
//    => LSP(Liskov Substitution Principle, 리스코프 치환 원칙)
//       - 자식 클래스는 부모 클래스로 대체할 수 있어야 한다.
//        : "자식의 공통된 기능은 부모로부터 비롯되어야 한다." => 다형성

// 4. 자식이 오버라이딩(재정의)하는 모든 함수는 반드시 가상이어야 한다.
// 5. 부모 클래스의 소멸자는 반드시 가상이어야 합니다.

// 6. 다형성은 OCP를 만족합니다.
//    OCP(Open Close Principle, 개방 폐쇄 원칙)
//   - 확장에는 열려 있어야 하고,
//     수정에는 닫혀 있어야 한다.
//   => 새로운 기능이 추가되어도 기존 코드는 수정되면 안된다.
//   => 상속은 재사용이 아닌, 다형성을 목적으로 사용해야 합니다.
//     "상속" "Upcasting" "오버라이딩" "가상함수"

// 7. 객체지향 5대 원칙(SOLID)
//    SRP(단일 책임 원칙)
//    OCP(개방 폐쇄 원칙) - *
//    LSP(리스코프 치환 원칙) - *
//    ISP(인터페이스 분리 원칙)
//    DIP(의존 관계 역전 원칙)

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

class Triangle : public Shape {
public:
    void Draw() const override { cout << "Triangle Draw" << endl; }
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
        } else if (cmd == 3) {
            shapes.push_back(new Triangle);
        }

        else if (cmd == 9) {

            for (Shape* e : shapes) {
                e->Draw();
                // 다형성(Polymorphism)
            }

        } else if (cmd == 0) {
            break;
        }
    }

    for (Shape* e : shapes) {
        delete e;
    }
}

// UNIX(Linux)
//   모든 것은 파일입니다.
//     => 파일의 인터페이스를 통해 일반 파일, 장치, ...
//     Open -> 일반 파일 Open
//             디바이스 파일 Open
//             소켓 파일 Open
//      : VFS(Virtual File System)