// 9_함수3.cpp

// 함수 오버로딩 주의사항
// > 기본 파라미터의 문법과 같이 사용할 경우,
//   문제가 발생할 가능성에 대해서 조심해야 합니다.

#include <iostream>
using namespace std;

void foo(int n = 100) { cout << n << endl; }
void foo() { cout << "v" << endl; }

int main()
{
    // foo(); - 모호성 오류!
    //    컴파일러는 기본값을 가지는 버전과, 인자가 없는 버전에서
    //    어떤 것을 호출할지 모호합니다.
}