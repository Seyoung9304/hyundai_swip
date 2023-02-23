// 4_변수.cpp
#include <iostream>
using namespace std;

// 사용자 정의 타입
// 1) struct
// 2) union
// 3) enum
#if 0
typedef struct complex {
    int re;
    int im;
} COMPLEX;

typedef union data {
    int a;
    double b;
    char c;
} DATA;

typedef enum task_state {
    TASK_RUNNING,
    TASK_STOPPED
} STATE;

int main()
{
    struct complex c;
    union data d;
    enum task_state s;

    COMPLEX c2;
    DATA d2;
    STATE s2;
}
#endif

struct complex {
    int re;
    int im;
};

union my_data {
    int a;
    double b;
    char c;
};

enum task_state {
    TASK_RUNNING,
    TASK_STOPPED
};

int main()
{
    struct complex c;
    union my_data d;
    enum task_state s;

    // struct / union / enum을 생략할 수 있습니다.
    complex c2;
    my_data d2;
    task_state s2;
}