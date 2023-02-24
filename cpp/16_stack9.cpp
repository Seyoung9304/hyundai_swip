#include <iostream>
#include <string>
using namespace std;

#include "Stack.hpp"

int main()
{
    Stack<string> s3;
    s3.push("hello");

    cout << s3.pop() << endl;

    // 클래스 템플릿은 명시적으로 타입을 지정해야 합니다.
    Stack<int> s1;
    Stack<double> s2;

    s1.push(10);
    s1.push(20);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    s2.push(3.14);
    s2.push(5.5);
    cout << s2.pop() << endl;
    cout << s2.pop() << endl;
}