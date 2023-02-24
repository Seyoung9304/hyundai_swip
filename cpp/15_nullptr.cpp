// 15_nullptr.c
#include <iostream>
using namespace std;

void foo(int n) { cout << "int" << endl; }
void foo(int* n) { cout << "int*" << endl; }

// C++11에서 NULL을 대체하는 nullptr이 도입되었습니다.

int main()
{
    int* p1 = nullptr;

    foo(0);
    foo(nullptr);

    // nullptr_t: bool타입(false)로의 암묵적인 변환이 허용됩니다.
    // if (p1 != nullptr) {
    if (p1) {
    }

    // C++에서는 bool 타입이 도입되었습니다.
    bool b = true;
    b = false;
}

#if 0
int main()
{
    // 1. 정수 0은 포인터 타입으로의 암묵적인 변환이 허용됩니다.
    // int* p1 = 0;
    int* p1 = NULL;

    foo(0);
    foo(NULL);
    // 2. NULL은 정수와 포인터 타입간의 모호성 오류의 원인이
    //   될 수 있습니다.
    //  => 타입 안전성이 없다.
}
#endif