// 33_함수객체33.cpp
#include <iostream>
using namespace std;

// 1. 함수 호출 연산자를 재정의하면, 객체를 대상으로 함수처럼 사용할 수
//   있습니다.
//    "함수 객체(Functor)"

// 2. 함수 호출 연산자는 인자와 반환 타입을 자유롭게 지정할 수 있습니다.
// 3. 함수 호출 연산자는 반드시 멤버 함수를 통해 정의되어야 합니다.

int add(int a, int b) { return a + b; }

class Sample {
public:
    int operator()(int a, int b) const { return a + b; }
};

int main()
{
    Sample s;

    cout << s(10, 20) << endl;
    cout << add(10, 20) << endl;
    // s.operator()(int, int)
}