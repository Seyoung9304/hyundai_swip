// 35_STL4.cpp
#include <iostream>
#include <cstring>
using namespace std;

// C언어의 문자열에서 문자를 찾는 함수
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