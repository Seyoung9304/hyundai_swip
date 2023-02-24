// 16_stack8.cpp
#include <iostream>
using namespace std;

// 클래스도 템플릿으로 만들 수 있습니다.

// 클래스 템플릿
template <typename TYPE>
class Stack {
private:
    TYPE* buff;
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
        buff = new TYPE[sz];
    }

    void push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE pop()
    {
        return buff[--top];
    }
};

int main()
{
    // 클래스 템플릿은 명시적으로 타입을 지정해야 합니다.
    Stack<int> s1;
    Stack<double> s2;

    s1.push(10);
    s1.push(20);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    s2.push(3.14);
    s2.push(5.5);
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
}