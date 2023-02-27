// 16_stack12.cpp
#include <iostream>
using namespace std;

template <typename TYPE>
class Stack {
private:
    TYPE* buff_;
    int top_;

public:
    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff_;
    }

    Stack(int sz = 10)
    {
        cout << "Stack()" << endl;

        top_ = 0;
        buff_ = new TYPE[sz];
    }

    // TYPE pop()
    // {
    //     return buff_[--top_];
    // }

    TYPE& top() { return buff_[top_ - 1]; }
    void pop() { --top_; }

    void push(const TYPE& n)
    {
        buff_[top_++] = n;
    }
};

#include <string>

int main()
{
    Stack<int> s1;

    s1.push(10);
    s1.push(20);

    cout << s1.top() << endl;
    s1.pop();

    cout << s1.top() << endl;
    s1.pop();
}