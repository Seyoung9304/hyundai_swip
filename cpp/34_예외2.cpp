// 34_예외2.cpp
#include <iostream>
using namespace std;

// 반환값을 통한 오류 처리의 문제점
// 1) 반환값이 오류인지 유효한 값인지 구분하기 어려울 수 있습니다.
//   atoi()
//   => 오류는 throw 하고,
//      결과는 return 합니다.

// 2) 오류 처리를 강제할 수 없습니다.
//   => throw 한 예외를 처리하지 않으면, 프로그램이 비정상종료 합니다.
//   => try-catch 구문을 통해 오류를 처리해야 합니다.
int OpenFile(const char* filename)
{
    if (filename == nullptr) {
        throw -1; // 오류
    }

    // ...

    return 0; // 결과
}

int main()
{
    // OpenFile("a.txt");
    try {
        OpenFile(nullptr);
    } catch (int& r) {
        cout << "error: " << r << endl;
    }
}