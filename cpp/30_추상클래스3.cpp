// 30_추상클래스3.cpp
#include <iostream>
using namespace std;

// 1. 문제의 원인
//  Car ------<> Camera
//  => Car 타입은 Camera의 구체적인 타입에 의존합니다.
//    "강한 결합"
// 2. 해결 방법
//    "느슨한 결합 / 약한 결합"

// 3. 약한 결합

// 1. 카메라의 제작자와 자동차의 제작자는 인터페이스(프로토콜)를 약속합니다.
//   : C++에서는 인터페이스를 위한 별도 키워드가 존재하지 않습니다.
#if 0
class BlackBox {
public:
    virtual ~BlackBox() { }

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};
#endif
struct BlackBox {
    virtual ~BlackBox() { }

    virtual void StartRecording() = 0;
    virtual void StopRecording() = 0;
};

// 2. 자동차의 제작자는 인터페이스를 이용해서 코드를 작성합니다.
class Car {
    BlackBox* camera;

public:
    Car(BlackBox* p)
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

// 3. 모든 카메라의 제작자는 BlackBox 인터페이스를 기반으로 제작되어야 합니다.
//   "인터페이스를 상속한다." 라고 하지 않고,
//   class Camera extends BlackBox {}
//   "인터페이스를 구현한다." 라고 합니다.
//   class Camera implements BlackBox {}

class Camera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "Camera Recording Start" << endl;
    }
    void StopRecording() override
    {
        cout << "Camera Recording Stop" << endl;
    }
};

class UHDCamera : public BlackBox {
public:
    void StartRecording() override
    {
        cout << "UHDCamera Recording Start" << endl;
    }
    void StopRecording() override
    {
        cout << "UHDCamera Recording Stop" << endl;
    }
};

int main()
{
    UHDCamera camera;
    Car car(&camera);

    car.Go();
}