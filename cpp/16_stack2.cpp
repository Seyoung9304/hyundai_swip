// 16_stack2.cpp
#include <iostream>
using namespace std;

// 2. 사용자 정의 타입을 설계합니다.
//   => struct
//   => 데이터 캡슐화

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
    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
}