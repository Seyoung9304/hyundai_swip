// 34_예외3.cpp
#include <iostream>
using namespace std;

#if 0
void foo(int n)
{
    if (n == 0) {
        throw -1;
    } else if (n == 1) {
        throw 3.14;
    }
}
#endif

// 1. C++은 예외의 종류에 따라서 사용자 정의 타입 예외를 정의합니다.
// class InvalidFilenameException { };
// class OutOfMemoryError { };

// 2. std::exception 상속해서, 에러를 정의합니다.
class InvalidFilenameException : public std::exception {
public:
    const char* what() const noexcept override
    {
        return "잘못된 파일명입니다.";
    }
};
class OutOfMemoryError : public std::exception {
public:
    const char* what() const noexcept override
    {
        return "메모리 부족합니다.";
    }
};

void foo(int n)
{
    if (n == 0) {
        throw InvalidFilenameException();
    } else if (n == 1) {
        throw OutOfMemoryError();
    }
}

int main()
{
    try {
        foo(1);
    } catch (std::exception& e) {
        cerr << e.what() << endl;
    }

    try {
        foo(1);
    } catch (OutOfMemoryError& e) {
    } catch (InvalidFilenameException& e) {
    } catch (...) {
    }
}