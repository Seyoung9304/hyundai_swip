// 16_stack3.cpp

#include <iostream>
using namespace std;

// 3. C++은 구조체 안에 멤버 데이터와
//    멤버 데이터를 조작하는 함수를 묶을 수 있습니다.
//   "상태와 행위를 하나의 타입으로 설계할 수 있습니다."
//   => 캡슐화

//   "상태와 행위를 가지고 있는 변수"
//   => 객체(object)
//    - 객체의 상태는 멤버 함수(메소드)를 통해서만 읽거나 변경되어야 한다.
//      "정보 은닉(Information Hiding)"
//       : 접근 지정자
//         public: 외부에서 접근을 허용한다.
//         private: 외부에서 접근이 불가능하다. 오직 멤버 함수를
//                  통해서 접근이 가능합니다.

//  => class: struct와 동일한데, 기본 접근지정 레벨이 private 입니다.
//   "객체를 만드는 타입 - class"

class Stack {
private:
    // 멤버 데이터(속성)
    int buff[10];
    int top;

public:
    // 멤버 함수(메소드)
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

    // s1.top = 0; => private 멤버, 외부 접근 불가능합니다.

    s1.init();
    s1.push(10);
    s1.push(20);

    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}