// 35_STL.cpp
#include <iostream>
using namespace std;

// STL(Standard Template Library)
// - 1979년: C++ 탄생
// - 1990년: C++ 표준 위원회 설립
// - 1998년: C++ 1차 표준안, 표준 라이브러리(STL)

// STL 구성요소
// 1) 컨테이너: 데이터를 저장하기 위한 자료구조
//    vector, list, deque, array
//    map, set, unordered_map, unordered_set

// 2) 알고리즘
//    컨테이너의 요소를 검색, 정렬 등의 일반 함수

// 3) 반복자
//    컨테이너의 요소를 열거하기 위해, 배열에서 포인터와 비슷하게
//    동작하는 객체

#include <string>
#include <complex>

int main()
{
    string s1 = "hello";
    string s2 = "hello";
    cout << s1 + s2 << endl;

    complex<int> c1(10, 20);
    complex<int> c2(30, 40);
    cout << c1 + c2 << endl;

    cout << c1.real() << endl;
    cout << c1.imag() << endl;
}
