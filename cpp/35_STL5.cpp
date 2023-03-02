// 35_STL5.cpp
#include <iostream>
#include <vector>
#include <algorithm> // find, sort
using namespace std;

// 함수 포인터를 통해서는 인라인화가 불가능합니다.
inline int add(int a, int b) { return a + b; }

bool func(int a, int b)
{
    return a > b;
}

class Functor {
public:
    // 인라인화가 가능합니다.
    inline bool operator()(int a, int b) const
    {
        return a < b;
    }
};

int main()
{
    int result = add(10, 20);

    // C++에서 함수에 정책을 전달하는 방법
    // 1. 일반 함수
    //  => 하나의 구현으로 다양한 함수 정책을 이용할 수 있습니다.
    //     호출이 인라인화가 불가능합니다.
    vector<int> x = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
    sort(begin(x), end(x), &func);
    //                     bool (*)(int, int)

    // 2. 함수 객체
    // => 전달된 정책의 타입만큼의 코드 생성이 필요합니다.
    //   "코드 메모리 사용량 증가"
    //    정책 함수의 호출이 인라인화가 가능합니다.
    Functor f;
    sort(begin(x), end(x), f);
    //                     Functor

    // 3. C++11에서 함수 객체를 만드는 편리한 문법이 도입되었습니다.
    // => Lambda Expression
    //    람다 표현식: 실행 가능한 코드를 참조하는 기술
    //     C++ - "익명의 함수 객체를 만드는 문법"
    sort(begin(x), end(x),
        [](int a, int b) { return a > b; });

    for (auto e : x) {
        cout << e << endl;
    }
}