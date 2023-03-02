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
#if 0
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

#endif

#if 0
int main()
{
    Image* p = new Image;
    p->Draw();

    delete p;
}
#endif

template <typename TYPE>
class Ptr {
    TYPE* obj;

public:
    // RAII(Resource Acquation Is Initialize)
    // : 소멸자를 통해 자원을 자동으로 정리하는 기술
    inline explicit Ptr(TYPE* p = nullptr)
        : obj(p)
    {
    }
    inline ~Ptr() { delete obj; }

    inline TYPE& operator*() { return *obj; }
    inline TYPE* operator->() { return obj; }
};

// C++ 에는 이미 스마트 포인터가 제공되고 있습니다.
#include <memory> // unique_ptr, shared_ptr

int main()
{
    shared_ptr<Image> p1(new Image);
    // shared_ptr<Image> p2 = make_shared<Image>();

    auto p2 = make_shared<Image>();

    unique_ptr<Image> p3(new Image);
    auto p4 = make_unique<Image>();
}

#if 0
int main()
{
    // Ptr<Image> p = new Image;
    // Ptr p = new Image; // C++17, 생성자 인자를 통해 추론합니다.
    Ptr p(new Image);

    (*p).Draw();
    // Image& operator*()
    // (Image&).Draw();

    p->Draw();
    //  (Image*)->Draw();
}
#endif

#if 0
class Sample {
public:
    // 변환 생성자로 인한 암묵적인 캐스팅은 위험합니다.
    explicit Sample(int n) { }
};

void foo(Sample s) { }

int main()
{
    Sample s1(3);
    Sample s2 { 3 };

    // Sample s = 3;
    // foo(42);
}
#endif