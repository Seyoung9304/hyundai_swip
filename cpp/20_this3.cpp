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

#if 1
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
#endif

class Cursor {
private:
    Cursor() { cout << "Cursor()" << endl; }
    friend Cursor* GetInstance();
};

// Singleton: 오직 한개의 객체를 생성하고,
//            어디에서도 동일한 객체를 참조하는 설계.
Cursor* GetInstance()
{
    static Cursor cursor;
    // 정적 지역 객체는 함수가 처음 호출되는 시점에,
    // 생성자가 호출되고, 함수가 더 이상 호출되지 않는 시점에
    // 소멸자가 호출된다.

    return &cursor;
}

int main()
{
    cout << "main" << endl;
    Cursor* p1 = GetInstance();
    cout << p1 << endl;

    Cursor* p2 = GetInstance();
    cout << p2 << endl;

    Cursor* p3 = GetInstance();
    cout << p3 << endl;
}

//--> C++ 전역 객체의 초기화 순서가 정해져 있지 않습니다.
//        전역 객체의 파괴 순서가 정해져 있지 않습니다.
// a.cpp
// C a;

// b.cpp
// C b;