// Stack.hpp
#ifndef STACK_HPP
#define STACK_HPP

template <typename TYPE>
class Stack {
private:
    TYPE* buff;
    int top;

public:
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

    Stack(int sz = 10)
    {
        cout << "Stack()" << endl;

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