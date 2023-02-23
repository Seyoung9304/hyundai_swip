// 8_string.cpp
#include <iostream>
using namespace std;

// #include <string.h>
#include <cstring>

// 1. C 문자열
// : '\0'문자로 종료되는 char 배열
#if 0
int main()
{
    char str1[] = "hello";
    const char* str2 = "hello";

    printf("len: %zu\n", strlen(str1));
    if (strcmp(str1, str2) == 0) {
        cout << "동일한 문자열..." << endl;
    }

    char str3[32];
    strcpy(str3, str1);
    cout << str3 << endl;

    strcat(str3, "world");
    cout << str3 << endl;
}
#endif

#include <string> // std::string

// 2. C++ 문자열 타입 - std::string
//  1) 문자열 함수가 아닌, 연산자를 통해 문자열의 비교, 복사, 연결 등의
//     작업을 수행할 수 있습니다. => 직관적이다.
//  2) 메모리 관리가 자동으로 수행됩니다.

int main()
{
    std::string s1 = "hello";
    std::string s2 = "hello";

    if (s1 == s2) {
        cout << "같은 문자열입니다." << endl;
    }

    string s3 = s1;
    cout << s3 << endl;

    s3 += " world";
    // s3 = s3 + " world";
    cout << s3 << endl;
}