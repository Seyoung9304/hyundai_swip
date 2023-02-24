// Stack.cpp
#include "Stack.h"

#if 0
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