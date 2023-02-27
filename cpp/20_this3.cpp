// 20_this3.cpp
#include <iostream>
using namespace std;

// private 생성자:
//  의도: 객체 생성을 제한하거나, 객체 생성의 정책을 제어할 수 있습니다.
#if 0
class Cursor {
private:
    Cursor() { }

    friend Cursor* GetInstance();
};

// Singleton: 오직 한개의 객체를 생성하고,
//            어디에서도 동일한 객체를 참조하는 설계.
Cursor* GetInstance()
{
    static Cursor cursor;
    return &cursor;
}

class Sample {
private:
    Sample() { }

    friend Sample* CreateSample();
};

Sample* CreateSample()
{
    return new Sample;
}

// Sample s1;
int main()
{
    Sample* s = CreateSample();

    // Sample s2;
}
#endif

// private 소멸자
// 의도: 객체 생성을 힙에서만 허용할 때.
//      객체 생성을 new를 통해서만 허용할 때.

class Sample {
private:
    ~Sample() { cout << "~Sample()" << endl; }

public:
    // void Destory(Sample* p)
    // {
    //     delete p;
    // }

    void Destory(/* Sample* this */)
    {
        delete this;
    }
};

// Sample s;
int main()
{
    // Sample s;

    Sample* p = new Sample;
    // delete p;

    // p->Destory(p);
    p->Destory();
}