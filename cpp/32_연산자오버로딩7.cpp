// 32_연산자오버로딩7.cpp
#include <iostream>
using namespace std;

class Image {
public:
    Image() { cout << "Image()" << endl; }
    ~Image() { cout << "~Image()" << endl; }

    void Draw() { cout << "Image Draw" << endl; }
};

class Ptr {
    Image* obj;

public:
    Ptr(Image* p = nullptr)
        : obj(p)
    {
    }

    ~Ptr() { delete obj; }

    Image& operator*() { return *obj; }
    Image* operator->() { return obj; }
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