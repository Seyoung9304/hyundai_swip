// 34_예외.cpp
#include <iostream>
using namespace std;

// C의 오류 처리
//  => 함수의 반환값
//   int: 0(성공) / 0이 아닌값(실패 코드)
//  포인터: 유효한 주소(성공) / nullptr
int OpenFile(const char* filename)
{
    if (filename == nullptr) {
        return -1;
    }

    // ...

    return 0;
}

// - 실패 가능한 함수를 사용하면, 반드시 반환값을 통해 오류를 체크해야 합니다.
// 반환값을 통한 오류 처리의 문제점
// 1) 반환값이 오류인지 유효한 값인지 구분하기 어려울 수 있습니다.
//   atoi()
// 2) 오류 처리를 강제할 수 없습니다.

#include <cstdlib>

int main()
{
    int result = atoi("x123123120");
    printf("result: %d\n", result);

    int ret = OpenFile("a.txt");
    if (ret != 0) {
        // 오류 처리
    }
}