// 13_캐스팅.cpp
#include <iostream>
using namespace std;

#include <cstdlib> // malloc, free

void foo(char* s)
{
    printf("%s\n", s);
}

#if 0
int main()
{
    // void*는 다른 포인터 타입으로의 암묵적인 변환이 C++에서는
    // 허용되지 않습니다.
    // => 명시적인 캐스팅이 필요합니다.
    int* p = (int*)malloc(sizeof(int) * 10);
    p[0] = 10;
    free(p);

    // 호환성 있는 타입간의 변환에서 암묵적인 변환이 허용되지만,
    // Uniform Initialization을 통해서는 허용되지 않습니다.
    // => 명시적인 캐스팅이 필요합니다.
    double d = 3.14;
    int n { (int)d };

    long long ll = 100LL;
    int n2 { (int)ll };

    // 포인터 타입간의 변화, 메모리를 원하는 크기로 해석
    // => 명시적인 변환이 필요합니다.
    int n3 = 0x12345678;
    char* pn = (char*)&n3;
    printf("%x %x %x %x\n", pn[0], pn[1], pn[2], pn[3]);

    // 메모리를 재해석하는 것은 위험성이 있습니다.
    double* pd = (double*)&n3;
    // *pd = 3.14; /* 미정의 동작 */

    char str1[] = "hello";
    foo(str1);

    // const char* -> char*
    //  : 값을 수정하기 위함이 아니라, 타입의 불일치 문제를
    //    해결하기 위해서, 명시적인 캐스팅이 필요합니다.
    const char* str2 = "hello";
    foo((char*)str2); // const char* ---> char*
}
#endif

// C 캐스팅 문제점
// > 목적을 파악하기 위해서는, 코드를 분석해야 합니다.
// C++ 캐스팅
// > 캐스팅의 용도와 목적에 따라 4개의 캐스팅 연산자를 제공합니다.

// 1. static_cast
//   : 가장 기본적인 C++의 캐스팅 연산자.
//   "연관성 있는 타입간의 안전한 캐스팅에서 사용할 수 있습니다."
//    double -> int
//    long long -> int
//    void* -> TYPE*
//  => 컴파일 타임에 캐스팅을 수행하기 때문에, static_cast 라고
//     부릅니다.

// 2. reinterpret_cast
//   : 메모리 재해석 용도로 사용합니다.
//   "위험한 캐스팅에서 사용하는 캐스팅 연산자입니다."

int main()
{
    // int* p = (int*)malloc(sizeof(int) * 10);
    int* p = static_cast<int*>(malloc(sizeof(int) * 10));
    p[0] = 10;
    free(p);

    double d = 3.14;
    int n { static_cast<int>(d) };

    long long ll = 3LL;
    int n2 { static_cast<int>(ll) };

    //-----
    int x = 0x12345678;
    // char* p2 = static_cast<char*>(&x); // int* -> char*
    // double* p3 = static_cast<double*>(&x);

    char* p2 = reinterpret_cast<char*>(&x); // int* -> char*
    printf("%x\n", p2[2]);

    double* p3 = reinterpret_cast<double*>(&x);
    // *p3 = 3.14; /* 미정의 동작 */
}

// 3. const_cast
// 4. dynamic_cast
