// 11_if.c
#include <iostream>
using namespace std;

int foo()
{
    /* 실패할 경우, -1을 반환합니다.*/
    return -1;
}

int* goo()
{
    /* 실패할 경우, NULL을 반환합니다. */
    return NULL;
}

#if 0
int main()
{
    for (int i = 0; i < 10; i++) {
        // ..
    }
}
#endif

#if 0
int main()
{
    int ret;
    ret = foo();
    if (ret == -1) {
        cout << "에러 핸들링" << endl;
    }

    ret = foo();
    if (ret == -1) {
        cout << "에러 핸들링" << endl;
    }

    int* ret2;
    ret2 = goo();
    if (ret2 == NULL) {
        cout << "에러 핸들링" << endl;
    }
}
#endif

// C++17: if-statement with initializer
//    정의: 조건문, switch 에서만 유효한 변수를 정의할 수 있습니다.

enum {
    TASK_RUNNING,
    TASK_STOPPED,
};

int GetState() { return TASK_RUNNING; }

int main()
{
    switch (int state = GetState(); state) {
    case TASK_RUNNING:
        break;

    case TASK_STOPPED:
        break;

    default:
        break;
    }

    if (int ret = foo(); ret == -1) {
        cout << "에러 핸들링" << endl;
    }

    if (int ret = foo(); ret == -1) {
        cout << "에러 핸들링" << endl;
    }

    if (int* ret = goo(); ret == NULL) {
        cout << "에러 핸들링" << endl;
    }
}