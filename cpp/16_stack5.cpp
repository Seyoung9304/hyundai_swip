// 16_stack5.cpp
#include <iostream>
using namespace std;

// 문제점
// > 사용자가 원하는 크기의 스택을 생성하고 싶습니다.

// 해결방법
// > 생성자는 인자를 통해, 값을 전달받을 수 있습니다.
//   생성자는 오버로딩을 통해, 다양한 생성자를 제공할 수 있습니다.

//  "객체를 생성하는 다양한 방법을 제공할 수 있습니다."

class Stack {
private:
    // 멤버 데이터(속성)
    int* buff;
    int top;

public:
    // 불필요한 오버로딩을 제거할 수 있습니다.
    //  => 파라미터 기본값
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

Stack s1;
int main()
{
    Stack s2(32);

    s1.push(10);
    s1.push(20);
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;

    s2.push(30);
    cout << s2.pop() << endl;
}

#if 0
class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(int n) { cout << "Sample(int)" << endl; }
    Sample(const char* s, int n)
    {
        cout << "Sample(const char*, int)" << endl;
    }
};


int main()
{
    Sample s1; // Sample()
    Sample s2(10); // Sample(int)
    Sample s3("Tom", 42); // Sample(const char*, int)

    Sample s4 = 10;
    Sample s5 = { "Tom", 42 };
    Sample s6 { "Tom", 42 };
}
#endif
