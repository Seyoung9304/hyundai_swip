// 16_stack5.cpp
#include <iostream>
using namespace std;

// 문제점

class Stack {
private:
    // 멤버 데이터(속성)
    int buff[10];
    int top;

public:
    // 생성자 함수
    Stack()
    {
        cout << "Stack()" << endl;
        top = 0;
    }

    // 멤버 함수(메소드)
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
    Stack s2;

    s1.push(10);
    s1.push(20);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    s2.push(30);
    cout << s2.pop() << endl;
}

#if 0
Stack s2;
int main()
{
    cout << "main" << endl;
    Stack s;
}
#endif