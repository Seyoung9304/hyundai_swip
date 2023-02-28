// 22_복사생성자6.cpp

#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { }
    Sample(const Sample& rhs)
    {
        cout << "Sample(const Sample&)" << endl;
    }
    ~Sample() { cout << "~Sample()" << endl; }
};

// void foo(Sample s)
void foo(const Sample& s)
{
}

Sample s;
Sample& goo()
{
    return s;
    // 반환용 임시 객체가 복사 생성자를 통해 생성됩니다.
}

// 지역 객체는 무조건 값으로 반환해야 합니다.
// - 컴파일러는 지역 객체를 값으로 반환할 때, 임시 객체의 생성을
//   최적화합니다.
//   RVO / NRVO
Sample hoo()
{
    // RVO: 임시 객체를 반환합니다.
    return Sample();

    // NRVO
    // Sample result; // 지역 객체
    // return result;
}

int main()
{
    // Sample s;
    foo(s); // 복사 생성자 호출

    // goo();
    hoo();
}