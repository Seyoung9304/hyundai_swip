// 22_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }
};

// 지역 객체의 참조를 반환하면 안됩니다.
// => RVO(Return Value Optimization, 반환값 최적화)
//  : 지역 객체를 값으로 반환하면, 컴파일러는 임시 객체의 생성 비용을 제거하는
//    최적화를 수행합니다.

Sample foo()
{
    Sample s;
    return s;
}

int main()
{
    foo();
}