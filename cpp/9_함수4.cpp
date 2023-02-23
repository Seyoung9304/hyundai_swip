// 9_함수4.cpp
#include <iostream>
using namespace std;

#if 0
// 인라인 함수 => 컴파일러에 의한 기계어 치환
inline int square(int x) { return x * x; }

// 매크로 함수 => 전처리기에 의한 텍스트 치환
#define SQUARE(x) ((x) * (x))

int main()
{
    int n = 5;
    cout << square(++n) << endl; /* OK */

    // cout << SQUARE(++n) << endl; /* 미정의 동작 */
}
#endif

// 1. 함수 호출의 오버헤드를 제거하기 위해, 매크로 함수를 사용하기보다는
//    인라인 함수를 사용해야 합니다.
//  => 미정의 동작 등의 문제가 없습니다.

// 2. 컴파일러가 인라인 여부를 결정합니다.

// 3. 인라인 함수 문제점
//  => 코드(텍스트) 메모리 사용량이 증가할 수 있습니다.
//  => 작은 코드를 가진 함수에서 인라인 함수가 유용합니다.
//     - 코드 메모리 사용량을 최적화할 수 있습니다.

// 4. C도 인라인 함수 문법이 존재합니다. - c99

// add.h
extern int add1(int a, int b);

// - 인라인 함수는 컴파일 타임에 기계어 치환이 수행되어야 하므로,
//   함수의 구현이 헤더파일을 통해서 제공되어야 합니다.
// - 인라인 함수는 내부 연결을 갖습니다.
inline int add2(int a, int b)
{
    return a + b;
}

// add.c
int add1(int a, int b)
{
    return a + b;
}

int main(void)
{
    add1(10, 20); // call

    add2(10, 20); // 기계어 치환
}