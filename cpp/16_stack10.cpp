// 16_stack10.cpp
#include <iostream>
using namespace std;

// 이미 C++의 표준 라이브러리에 스택이 있습니다.
//  : STL(Standard Template Library)
#include <stack>

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // 현재 스택의 데이터를 확인하는 연산과,    - top
    // 현재 스택의 마지막 요소를 제거하는 연산이 - pop
    // 분리되어 있습니다.
    // => 값을 반환하면, 복사 생성 비용이 있기 때문에
    //    값을 참조하는 연산과 제거하는 연산을 분리한 형태로
    //    설계되었습니다.

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
