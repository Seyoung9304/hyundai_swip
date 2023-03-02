// 35_STL4.cpp
#include <iostream>
#include <cstring>
using namespace std;

// 1. C언어의 문자열에서 문자를 찾는 함수
//  문제점: 부분 문자열 검색이 불가능합니다.
#if 0
char* xstrchr(char* s, char c)
{
    while (*s != '\0' && *s != c) {
        s++;
    }

    return *s == c ? s : NULL;
}

int main()
{
    char str[] = "hello";
    char* p = xstrchr(str, 'e');
    if (p) {
        cout << *p << endl;
    }
}
#endif

// 1) 검색 구간의 일반화
//  => 반개구간: [begin, end)
//     end에 도달했다 -> 실패를 의미합니다.
//     past the end는 실패를 의미합니다.
//  => 부분 문자열을 검색할 수 있습니다.
#if 0
char* xstrchr(char* begin, char* end, char c)
{
    while (begin != end && *begin != c) {
        ++begin;
    }

    return begin;
}

int main()
{
    char str[] = "hello";
    char* p = xstrchr(str + 1, str + 4, 'l');
    if (p != str + 3) {
        cout << *p << endl;
    }
}
#endif

// 2) 검색 대상 타입의 일반화 => Template
// T* xfind(T* begin, T* end, T c)
// => 포인터만 사용할 수 있습니다.
//    스마트포인터는 사용할 수 없습니다.
//    반복자도 객체이므로 사용할 수 없습니다.
template <typename T, typename F>
T xfind(T begin, T end, F c)
{
    while (begin != end && *begin != c) {
        ++begin;
    }

    return begin;
}

// "Generic Programming"
//  => 일반적 프로그래밍

#include <vector>
#include <list>

#include <algorithm> // find

// - 멤버 함수로 제공되는 경우
// vector.find()
// list.find()
// .....find()

// - C++은 일반함수로 제공합니다.
//  vector
//  list   ------>  find()
//  ...

int main()
{
    // int x[5] = { 10, 20, 30, 40, 60 };
    list<int> x = { 10, 20, 30, 40, 60 };

    // int* p = xfind(x, x + 5, 30);
    auto p = find(begin(x), end(x), 30);

    if (p != end(x)) {
        cout << *p << endl;
    }
}