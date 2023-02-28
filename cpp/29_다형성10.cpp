// 29_다형성9.cpp
#include <iostream>
#include <vector>
using namespace std;

// Refactoring
//  => Replace type code with polymorphism

class Shape {
public:
    // int type = 0;
    virtual ~Shape() { }
    virtual void Draw() const { cout << "Shape Draw" << endl; }

    virtual Shape* Clone() { return new Shape(*this); }
};

class Rect : public Shape {
public:
    // int type = 1;
    void Draw() const override { cout << "Rect Draw" << endl; }

    Shape* Clone() override { return new Rect(*this); }
};

class Circle : public Shape {
public:
    // int type = 2;
    void Draw() const override { cout << "Circle Draw" << endl; }

    Shape* Clone() override { return new Circle(*this); }
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
            // 복제 기능
            int index;
            cout << "몇번째 index 복제? ";
            cin >> index;

            // shapes[index] => Rect? Circle?
            /*
            if (shapes[index]->type == 1) {
                // Rect 복제
            } else if (shapes[index]->type == 2) {
                // Circle 복제
            }
            */

            // Prototype Pattern
            Shape* copy = shapes[index]->Clone();
            shapes.push_back(copy);
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