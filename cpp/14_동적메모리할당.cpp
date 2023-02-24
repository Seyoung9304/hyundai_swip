// 14_동적메모리할당.cpp
#include <iostream>
using namespace std;

#include <cstdlib> // malloc, free

// 1. malloc은 라이브러리 함수입니다.
//   - malloc은 인자로 메모리 크기를 전달받습니다.
//   - malloc은 void*를 반환하기 때문에, C++에서는 명시적인
//     캐스팅이 필요합니다.

// 2. new는 연산자 입니다.
//   - 타입을 전달받습니다.
//   - 전달 받은 타입의 주소 타입을 반환합니다.
//     명시적인 캐스팅이 필요하지 않습니다.

// 3. free는 함수입니다.
//   - 할당받은 메모리의 주소를 전달받습니다.
//   - NULL을 전달받은 경우, 아무일도 일어나지 않습니다.

// 4. delete는 연산자 입니다.
//   - new를 통해 할당한 메모리의 주소를 전달받습니다.
//   - NULL을 전달받은 경우, 아무일도 일어나지 않습니다.
//   - 연속된 메모리를 해지할 경우, 반드시 delete[]를 사용해야 합니다.
//    int* p = new int[10];
//    delete[] p;

int main()
{
    int* p1 = static_cast<int*>(malloc(sizeof(int)));
    free(p1);

    p1 = new int;
    delete p1;

    p1 = NULL;
    delete p1; /* OK */

    int* p2 = static_cast<int*>(malloc(sizeof(int) * 10));
    free(p2);

    p2 = new int[10];
    delete[] p2;

    // delete p2; /* 미정의 동작 */
}