// 12_레퍼런스4.cpp
#include <iostream>
using namespace std;

// 레퍼런스
// 1. & - lvalue reference
// => lvalue만 참조 가능합니다.

// 2. const & - const lvalue reference
// => lvalue도 참조 가능하고,
//    rvalue도 참조 가능합니다.
//    const lvalue도 참조할 수 있습니다.

// 3. C++11, rvalue reference
// => rvalue만 참조 가능합니다.

// lvalue, rvalue
// lvalue: 왼쪽, 오른쪽
// rvalue: 오른쪽
// a = 3;
// b = a; /* OK */
// 3 = b; /* NO */

void foo(const int& r)
{
    cout << "const&" << endl;
}

void foo(int& r)
{
    cout << "lvalue" << endl;
}

void foo(int&& r)
{
    cout << "rvalue" << endl;
}

#if 1
int main()
{
    int n = 10;
    foo(10);
    foo(n);
}
#endif

#if 0
int main()
{
    int n = 10;
    int& r1 = n;
    // int& r2 = 10; /* 불가능 */

    int&& r2 = 10; /* rvalue reference, rvalue 참조 가능 */

    const int& cr1 = n; /* 가능 */
    const int& cr2 = 10; /* 가능 */
}
#endif