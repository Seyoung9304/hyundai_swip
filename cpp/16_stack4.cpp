// 16_stack4.cpp
#include <iostream>
using namespace std;

// 문제점
// > 객체를 생성하였을 때, 바로 사용할 수 없습니다.

// 해결방법
// > 객체가 메모리에 생성되었을 때, 자동으로 호출되는 약속된 멤버 함수가 있습니다.
//   생성자(Constructor) 함수
//   - 역활: 객체가 생성되었을 때, 바로 사용될 수 있도록 초기화하는 역활을
//          담당합니다.
//   - 형태
//     1. 이름은 클래스의 이름과 동일합니다.
//     2. 반환타입이 없고, 명시할수도 없습니다.

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