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
class InvalidFilenameException { };
class OutOfMemoryError { };

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
    } catch (OutOfMemoryError& e) {
    } catch (InvalidFilenameException& e) {
    } catch (...) {
    }
}