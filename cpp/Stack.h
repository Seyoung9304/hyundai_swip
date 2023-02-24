// Stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* buff;
    int top;

public:
    inline ~Stack();
    inline Stack(int sz = 10);

    inline void push(int n);
    inline int pop();
};

// 인라인 함수의 구현은 헤더 파일을 통해 제공되어야
// 합니다.
Stack::~Stack()
{
    delete[] buff;
}

Stack::Stack(int sz)
{
    top = 0;
    buff = new int[sz];
}

void Stack::push(int n)
{
    buff[top++] = n;
}

int Stack::pop()
{
    return buff[--top];
}

#endif