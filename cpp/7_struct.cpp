// 7_struct.cpp
#include <iostream>
using namespace std;

struct AAA {
    int x;
    int y;
    long z;
};

int main()
{
    AAA aaa = { 10, 20 };

    int x = aaa.x;
    int y = aaa.y;
    cout << x << ", " << y << endl;

    // Structured Binding 선언: C++17
    // 1) auto를 반드시 사용해야 합니다.
    // 2) 멤버 데이터 개수와 동일하게 지정되어야 합니다.
    auto [x2, y2, z2] = aaa;
    cout << x2 << ", " << y2 << endl;

    // 3) 배열에서도 사용할 수 있습니다.
    int arr[3] = { 10, 20, 30 };
    auto [a, b, c] = arr;

    cout << a << ", " << b << ", " << c << endl;
}
