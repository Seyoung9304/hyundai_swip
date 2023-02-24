#include <iostream>
using namespace std;

#include <cstdlib> // malloc, free - 메모리 누수, 할당/해제 비용 고려해야 함

// 1. malloc, free는 라이브러리 함수

int main(){
    int* p1 = static_cast<int*>(malloc(sizeof(int)));
    free(p1);

}