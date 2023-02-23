// 9_함수2.cpp
#include <iostream>
using namespace std;

// C++은 동일한 이름의 함수를 여러개 제공할 수 있습니다.
//  > 함수의 이름은 동일하지만, 인자 정보가 다른 경우에만 가능합니다.
//   => 함수 오버로딩(중복 적재)
//   => 컴파일러가 함수의 이름을 인자 타입과 개수를 통해 다른 이름으로
//      번역합니다.
//       "네임 맹글링(name mangling)"

//  > extern "C"
//   C++의 키워드입니다.
//   함수를 C의 형태로 만듭니다.
// C++:              void foo(int a)   ==> __Z3fooi
//      extern "C"   void foo(int a)   ==> _foo
//   : 네임 맹글링을 하지 않기 때문에, C에서 호출이 가능합니다.
//     C++에서 C에서 호출되는 함수를 제공할 수 있습니다.
//     - 오버로딩은 불가능합니다.

int square(int x) { return x * x; }
double square(double x) { return x * x; }

int main()
{
    cout << square(10) << endl;
    cout << square(3.14) << endl;
}

// C에서는 동일한 이름의 함수를 여러개 제공할 수 없습니다.
// 타입에 따라 다른 이름을 사용해야 합니다.
#if 0
int squarei(int x) { return x * x; }
double squared(double x) { return x * x; }

int main()
{
    cout << squarei(10) << endl;
    cout << squared(3.14) << endl;
}
#endif