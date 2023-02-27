// 22_복사생성자2.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

// 복사 생성자가 호출되는 경우

// 1. 객체가 함수로 call by value로 전달될 때
#if 0
void foo(Sample s)

// void foo(const Sample& s)
{
}

int main()
{
    Sample s;
    cout << "----" << endl;
    foo(s); // !!!
    cout << "----" << endl;
}
#endif

// 2. 객체가 함수에서 값으로 반환할 때
//  => 함수에서 객체를 값으로 반환하면, 값으로 반환하기 위한 임시 객체가 생성됩니다.

Sample s;
Sample foo()
{
    return s;
}

int main()
{
    cout << "----" << endl;
    foo();
    cout << "----" << endl;
}

#if 0
int main()
{
    Sample s; // Sample::Sample()

    // 복사 생성자가 호출되는 경우
    Sample s1(s);
    Sample s2 = s;
    Sample s3 { s };
    Sample s4 = { s };
}
#endif