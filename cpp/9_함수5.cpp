
#include <iostream>
using namespace std;

#if 0
#define SQUARE(x) ((x) * (x))

int main()
{
    cout << SQUARE(10) << endl; // 100
    cout << SQUARE(3.14) << endl;
}
#endif

// C++ Template
#if 0
inline int sqaure(int x)
{
    return x * x;
}

inline double square(double x)
{
    return x * x;
}

inline long long square(long long x)
{
    return x * x;
}

int main()
{
    cout << square(10) << endl; // 100
    cout << square(3.14) << endl;
}
#endif

// 타입만 다르고 알고리즘이 동일할 때
//  => 함수의 오버로딩을 직접 작성하지 않아도, C++의 템플릿을 이용해
//     자동으로 생성할 수 있습니다.
//  => C++의 템플릿은 컴파일러가 함수 호출 구문을 통해, TYPE을 결정해서
//     코드를 자동으로 생성합니다.

//  템플릿 문제점
//  - 사용자가 전달한 함수의 인자 타입에 따라 코드를 생성하기 때문에
//    코드 메모리 사용량이 증가할 수 있습니다.
//   > 인라인 최적화를 통해 메모리 사용량을 최적화할 수 있습니다.
//
//  - 컴파일 속도가 느려집니다.

template <typename TYPE>
inline TYPE square(TYPE x)
{
    return x * x;
}

int main()
{
    // 명시적인 타입 지정
    cout << square<long>(10) << endl; // square<long>(10);

    // 암묵적인 타입 추론
    cout << square(3.14) << endl; // square<double>(3.14);

    cout << square(100L) << endl; // square<long>(100L);
}