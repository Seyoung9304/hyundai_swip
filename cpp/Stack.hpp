// Stack.hpp
#ifndef STACK_HPP
#define STACK_HPP

//       Stack -> 클래스 템플릿
// Stack<TYPE> -> 클래스

template <typename TYPE>
class Stack {
private:
    TYPE* buff;
    int top;

public:
    ~Stack();
    Stack(int sz = 10);

    void push(TYPE n);
    TYPE pop();
};

template <typename TYPE>
Stack<TYPE>::~Stack()
{
    delete[] buff;
}

template <typename TYPE>
Stack<TYPE>::Stack(int sz)
{
    top = 0;
    buff = new TYPE[sz];
}

template <typename TYPE>
void Stack<TYPE>::push(TYPE n)
{
    buff[top++] = n;
}

template <typename TYPE>
TYPE Stack<TYPE>::pop()
{
    return buff[--top];
}

#if 0
template <typename TYPE>
class Stack {
private:
    TYPE* buff;
    int top;

public:
    ~Stack()
    {
        delete[] buff;
    }

    Stack(int sz = 10)
    {
        top = 0;
        buff = new TYPE[sz];
    }

    void push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE pop()
    {
        return buff[--top];
    }
};
#endif

#endif
