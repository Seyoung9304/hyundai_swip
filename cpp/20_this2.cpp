// 20_this2.cpp
#include <iostream>
using namespace std;
#if 0
class Sample {
    int data;

public:
    Sample() { data = 100; }

    // C++ 에서는 this가 null 이라고 가정하는 코드는
    // 미정의 동작입니다.
    // => 아래 기법은 오래전에는 많이 사용되었지만,
    //    clang 도입 이후로 많이 변경되었습니다.
    int call_f3() // call_f3(Sample* this)
    {
        return this ? f3() : 0;
        //            this->f3()
    }

    static int safe_f3(Sample* self)
    {
        return self ? self->f3() : 0;
    }

    int f3()
    {
        return data;
    }
};
#endif


class Sample {
    int data;

public:
    Sample() { data = 100; }

    // void f1(Sample* this)
    void f1()
    {
        cout << this << endl;
        cout << "f1" << endl;
    }

    int f2()
    {
        cout << this << endl;
        cout << "f2" << endl;
        return 100;
    }

    int f3()
    {
        cout << this << endl;
        cout << "f3" << endl;
        return data;
        //     this->data;
        //     (*this).data
    }
};

int main()
{
    // Sample* p = new Sample;
    Sample* p = nullptr;

    p->f1(); // 잘 작동함. f1(p)와 같은 형태로 호출되는데, f1함수에는 p에 직접 접근하는 연산이 없기 때문에
    p->f2(); // 잘 작동함
    p->f3(); // null참조 일어남 -> Segmentation fault

    delete p;
}

int main(){
    Sample* p = nullptr;

}