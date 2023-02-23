// 5_using.cpp
#include <iostream>
using namespace std;

// using
// 1. namespace
//    using 선언
//     using std::cout;
//    using 지시어
//     using namespace std;
//
// 2. C++11, Type aliasing
//   - typedef를 대체합니다.
//    1) 직관적입니다.
//    2) 템플릿의 타입 별칭을 사용할 수 있습니다.

// typedef int (*PARR3)[3];
using PARR3 = int (*)[3];

// int (*foo())[3]
PARR3 foo()
{
    static int x[2][3] = {};
    return x; // int(*)[3]
}

int add(int a, int b) { return a + b; }

// typedef int (*FP)(int, int);
using FP = int (*)(int, int); 
/*
FP는 int()(int, int)의 별칭(alias)입니다. 
int()(int, int)는 두 개의 int형 매개변수를 받아들이고 int형 값을 반환하는 함수 포인터입니다. 
따라서, FP는 int형 매개변수 두 개를 받아들이고 int형 값을 반환하는 함수 포인터의 별칭으로 정의되는 것입니다.
*/

int (*goo())(int, int)
{
    return &add; // int(*)(int, int)
}

int main()
{
}
