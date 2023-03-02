// 35_STL3.cpp
#include <iostream>
using namespace std;

// 반복자(Iterator)
// 1. C++의 구간 표현 방법
//   시작은 포함되지만, 마지막은 포함되지 않는 반개구간을 사용합니다.
//   [begin, end)
#if 0
int main()
{
    //          p1             p2
    int x[5] = { 1, 2, 3, 4, 5 };

    int* p1 = x;
    int* p2 = x + 5; // 끝 다음 위치(past the end)
    // [begin, end): 반개구간

    while (p1 != p2) {
        cout << *p1 << endl;
        ++p1;
    }
}
#endif

#include <vector>
int main()
{
    //          p1             p2
    vector<int> x = { 1, 2, 3, 4, 5 };

    auto p1 = x.begin();
    auto p2 = x.end(); // 끝 다음 위치(past the end)
    // [begin, end): 반개구간

    while (p1 != p2) {
        cout << *p1 << endl; // *p1, 반복자가 가르키는 요소를 얻는 방법
        ++p1; // ++p1, 다음 위치로 이동
    }
}