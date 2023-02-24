// Stack.cpp
#include "Stack.h"

Stack::~Stack()
{
    delete[] buff;
}

Stack::Stack(int sz) // 디폴트 파라미터 쓰면 안댐!
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