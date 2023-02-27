// 16_stack11.cpp
#include <iostream>
using namespace std;

#if 0
// => 전역 상태
//  "프로그램 내에 여러 개의 스택을 제공하기 어렵습니다."
int buff[10];
int top = 0;

void push(int n)
{
    buff[top++] = n;
}

int pop()
{
    return buff[--top];
}

int main()
{
    push(10);
    push(20);
    push(30);

    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
}
#endif

#if 0
struct Stack {
    int buff[10];
    int top;
};

void init(Stack* s)
{
    s->top = 0;
}

void push(Stack* s, int n)
{
    s->buff[(s->top)++] = n;
}

int pop(Stack* s)
{
    return s->buff[--(s->top)];
}

Stack s1;
int main()
{
    Stack s2;

    init(&s1);
    init(&s2);

    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
}
#endif

#if 0
// C++ => 캡슐화(상태 + 행위) => 객체
struct Stack {
    // 멤버 데이터(속성)
    int buff[10];
    int top;

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

    s1.init();
    s2.init();

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif

// 정보 은닉
// => 객체의 상태는 객체가 제공하는 멤버 함수를 통해
//    읽거나 수정되어야 한다.
//   "접근 지정자"
//    public: 외부에서 접근이 가능합니다.
//   private: 외부에서 접근이 불가능하고, 멤버 함수를 통해서만
//            접근 가능합니다.

//  => class: 기본 접근 지정자가 private 입니다.
//    struct: 기본 접근 지정자가 public 입니다.
#if 0
class Stack {
private:
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
    // s2.top = 100;

    s1.init();
    s2.init();

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif

// 문제점
// > 객체가 생성된 이후에 바로 사용되기 위해서는 init이 명시적으로
//   호출되어야 한다.
// => 해결 방법
//  객체가 메모리에 생성되는 시점에 호출되는 약속된 멤버 함수가 있습니다.
//   "생성자(Constructor)"
#if 0
class Stack {
private:
    int buff[10];
    int top;

    // private 메소드: public 메소드의 가독성을 높이기 위해 사용되어야 한다.
    //   "클린 코드"
    void init()
    {
        top = 0;
    }

public:
    Stack()
    {
        init();
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
    // s2.top = 100;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif

class Stack {
private:
    // int buff[10];
    int* buff;
    int top;

public:
    Stack(int sz = 10)
    {
        top = 0;
        buff = new int[sz];
    }

    // 객체가 메모리에서 사라지기 직전에 호출되는 약속된 멤버 함수
    //  => 소멸자(Destructor)
    ~Stack()
    {
        delete[] buff; // buff는 연속된 메모리(배열) -> 연속된 메모리를 delete할 때에는 뒤에 []를 붙여주어야 합니다
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

Stack s1(200);
int main()
{
    Stack s2;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}