// Stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
private:
    // 멤버 데이터(속성)
    int* buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff;
    }

    Stack(int sz = 10)
    {
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

#endif