// 16_stack6.cpp
#include <iostream>
using namespace std;

// 문제점
// - 객체 내부에서 new한 메모리는 객체가 파괴되기 전에, delete 되어야
//   합니다.

// 해결 방법
// > 객체가 메모리에서 해지되기 전에 호출되는 약속된 멤버 함수가 있습니다.
// => 소멸자(Destructor) 함수
//  - 객체 내부에서 해지해야 하는 자원(메모리, 파일 ..)이 존재하는 경우,
//    소멸자를 통해 반드시 정리해야 합니다.

// 소멸자
//  - ~클래스 이름입니다.
//  - 반환 타입도 없고, 반환값도 없습니다.
//  - 인자도 없습니다. 오버로딩도 불가능하고, 오직 1개만 제공할 수 있습니다.

class Stack {
private:
    // 멤버 데이터(속성)
    int* buff;
    int top;

public:
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

    Stack(int sz = 10)
    {
        cout << "Stack()" << endl;

        top = 0;
        buff = new int[sz];
    }

    void push(int n)
    {
        buff[top++] = n;
    }

    int pop()
    {
        return buff[--top];
    }
};

Stack s1;
int main()
{
    cout << "main" << endl;
    Stack s2(32);

    s1.push(10);
    s1.push(20);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    s2.push(30);
    cout << s2.pop() << endl;

    cout << "main end" << endl;
}

#if 0
class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(int n) { cout << "Sample(int)" << endl; }
    Sample(const char* s, int n)
    {
        cout << "Sample(const char*, int)" << endl;
    }
};


int main()
{
    Sample s1; // Sample()
    Sample s2(10); // Sample(int)
    Sample s3("Tom", 42); // Sample(const char*, int)

    Sample s4 = 10;
    Sample s5 = { "Tom", 42 };
    Sample s6 { "Tom", 42 };
}
#endif
