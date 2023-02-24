// 16_stack3.cpp

#include <iostream>
using namespace std;

// 3. C++은 구조체 안에 멤버 데이터와
//    멤버 데이터를 조작하는 함수를 묶을 수 있습니다.
//   "상태와 행위를 하나의 타입으로 설계할 수 있습니다."
//   => 캡슐화

//   "상태와 행위를 가지고 있는 변수"
//   => 객체(object)

struct Stack {
    int buff[10];
    int top;

    void init()
    {
        top = 0;
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
    Stack s2;

    s1.init();
    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}