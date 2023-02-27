#include <iostream>
using namespace std;

class Sample{
    int data;
public:
    Sample(){
        data = 100;
    }

    void f1(){
        cout<<"f1"<<endl;
    }

    int f2(){
        cout<<"f2"<<endl;
        return 10;
    }

    int f3(){
        cout<<"f3"<<endl;
        return data;
    }
};

int main(){
    Sample* p = nullptr;
    p->f1(); // 잘 작동함. f1(p)와 같은 형태로 호출되는데, f1함수에는 p에 직접 접근하는 연산이 없기 때문에
    p->f2(); // 잘 작동함
    p->f3(); // null참조 일어남 -> Segmentation fault
}

