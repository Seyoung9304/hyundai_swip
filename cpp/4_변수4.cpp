// 4_변수4.cpp
#include <iostream>
using namespace std;

// auto - C++11
//  1. '컴파일 타임'에 변수의 타입을 우항의 타입과 동일한 타입으로 타입을 결정합니다.
//  2. C의 auto라는 키워드를 다른 의미로 사용합니다.

int add(int a, int b) { return a + b; }

int main()
{
    int x2[3][2] = { 10, 20, 30 };
    // int (*px)[2] = x2;
    auto px = x2;
    printf("%d\n", px[0][1]);

    // int (*f)(int, int) = &add;
    auto f = &add;
    cout << f(10, 20) << endl;

    int x[3] = { 10, 20, 30 };

    auto p = x; // p -> int*
    auto e = *x; // e -> int

    // auto n;
    // 주의: 반드시 초기화가 필요합니다.
    //  "우항의 타입을 통해 타입을 추론하기 때문입니다."
}

#if 0
int main()
{
    int x[3] = { 10, 20, 30 };

    int* p = x;
    int e = *x;
}
#endif