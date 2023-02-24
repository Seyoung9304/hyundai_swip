// Stack.cpp
#include "Stack.h"

Stack::~Stack()
{
    delete[] buff;
}

Stack::Stack(int sz = 10)
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