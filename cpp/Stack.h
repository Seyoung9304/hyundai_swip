// Stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* buff;
    int top;

public:
    ~Stack();
    Stack(int sz = 10);

    void push(int n);
    int pop();
};

#endif