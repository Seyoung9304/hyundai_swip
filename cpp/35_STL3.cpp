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

#include <list>
#include <vector>

// 2. 컨테이너에서 컨테이너의 시작 위치를 가르키는 반복자를 얻는 멤버 함수
//  => begin()
//    컨테이너의 끝 다음 위치(past the end)를 가르키는 반복자를 얻는 멤버 함수
//  => end()
#if 0
int main()
{
    //          p1             p2
    // vector<int> x = { 1, 2, 3, 4, 5 };
    list<int> x = { 1, 2, 3, 4, 5 };

    auto p1 = x.begin();
    auto p2 = x.end(); // 끝 다음 위치(past the end)
    // [begin, end): 반개구간

    while (p1 != p2) {
        cout << *p1 << endl; // *p1, 반복자가 가르키는 요소를 얻는 방법
        ++p1; // ++p1, 다음 위치로 이동
    }
}
#endif

#include <deque>

// C++11에서 begin / end 일반 함수가 도입되었습니다.
//  > 일반 함수를 사용하면, 멤버 함수가 없는 일반 배열도 컨테이너와
//    동일하게 반복자를 사용할 수 있습니다.
#if 0
int main()
{
    // vector<int> x = { 1, 2, 3, 4, 5 };
    // list<int> x = { 1, 2, 3, 4, 5 };
    deque<int> x = { 1, 2, 3, 4, 5 };
    // int x[5] = { 1, 2, 3, 4, 5 };

    auto p1 = begin(x);
    auto p2 = end(x); // 끝 다음 위치(past the end)
    // [begin, end): 반개구간

    while (p1 != p2) {
        cout << *p1 << endl; // *p1, 반복자가 가르키는 요소를 얻는 방법
        ++p1; // ++p1, 다음 위치로 이동
    }
}
#endif

int main()
{
    vector<int> x = { 1, 2, 3, 4, 5 };
    // list<int> x = { 1, 2, 3, 4, 5 };
    // deque<int> x = { 1, 2, 3, 4, 5 };
    // int x[5] = { 1, 2, 3, 4, 5 };

    auto p1 = begin(x);
    vector<int>::iterator p2 = end(x); // 끝 다음 위치(past the end)
    // [begin, end): 반개구간

    while (p1 != p2) {
        cout << *p1 << endl; // *p1, 반복자가 가르키는 요소를 얻는 방법
        ++p1; // ++p1, 다음 위치로 이동
    }
}