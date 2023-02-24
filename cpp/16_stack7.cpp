// 16_stack7.cpp
#include <iostream>
using namespace std;

#include "Stack.h"

Stack s1;
int main()
{
    cout << "main" << endl;
    Stack s2(32);

    s1.push(10);
    s1.push(20);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    s2.push(30);
    cout << s2.pop() << endl;

    cout << "main end" << endl;
}