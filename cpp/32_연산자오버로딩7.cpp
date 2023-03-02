// 32_연산자오버로딩7.cpp
#include <iostream>
using namespace std;

class Image {
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() { cout << "Image Draw" << endl; }
};

// 포인터의 역활을 수행하는 클래스
//  => 스마트 포인터(Smart Pointer)
//     Proxy Pattern
class Ptr {
    Image* obj;

public:
    // RAII(Resource Acquation Is Initialize)
    // : 소멸자를 통해 자원을 자동으로 정리하는 기술
    inline Ptr(Image* p = nullptr)
        : obj(p)
    {
    }
    inline ~Ptr() { delete obj; }

    inline Image& operator*() { return *obj; }
    inline Image* operator->() { return obj; }
};

int main()
{
    Ptr p = new Image;

    (*p).Draw();
    // Image& operator*()
    // (Image&).Draw();

    p->Draw();
    //  (Image*)->Draw();
}

#if 0
int main()
{
    Image* p = new Image;
    p->Draw();

    delete p;
}
#endif