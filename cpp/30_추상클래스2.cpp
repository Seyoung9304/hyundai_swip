// 30_추상클래스2.cpp
#include <iostream>
using namespace std;

// SRP(Single Responsibility Principle, 단일 책임 원칙)
//  : 모든 클래스는 단 하나의 책임을 가져야 한다.
class Camera {
public:
    void StartRecording() { cout << "Camera Recording Start" << endl; }
    void StopRecording() { cout << "Camera Recording Stop" << endl; }
};

// OCP(Open Close Principle, 개방 폐쇄 원칙)
// => 새로운 기능이 추가되어도, 기존 코드는 수정되면 안된다.
class FHDCamera {
public:
    void StartRecording() { cout << "FHDCamera Recording Start" << endl; }
    void StopRecording() { cout << "FHDCamera Recording Stop" << endl; }
};

class Car {
    FHDCamera* camera;

public:
    Car(FHDCamera* p)
        : camera(p)
    {
    }

    void Go()
    {
        camera->StartRecording();
        // ...
        camera->StopRecording();
    }
};

int main()
{
    FHDCamera fcamera;
    Camera camera;
    Car car(&fcamera); /* 에러 */

    car.Go();
}