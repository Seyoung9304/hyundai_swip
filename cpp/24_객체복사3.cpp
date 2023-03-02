// 24_객체복사2.cpp
#include <iostream>
#include <cstring>
using namespace std;

// 3. 해결 방법
//  1) 깊은 복사
//  2) 참조 계수(Reference Counting)
class User {
    char* name;
    int age;

    int* ref; // 참조 계수

    void Release()
    {
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }
    }

public:
    ~User()
    {
        Release();
    }

    User(const User& rhs)
        : name(rhs.name)
        , age(rhs.age)
        , ref(rhs.ref)
    {
        ++(*ref);
    }

    User& operator=(const User& rhs)
    {
        // 1. 자신과 동일한 객체의 대입인지 확인
        if (this == &rhs)
            return *this;

        // 2. 자신이 가지고 있는 참조 계수 감소
        //    참조 계수가 0일 경우, 자원 해지
        Release();

        // 3. 복사, 참조 계수 증가
        name = rhs.name;
        age = rhs.age;
        ref = rhs.ref;

        ++(*ref);

        return *this;
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);

        ref = new int(1);
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

int main()
{
    User user1("Tom", 42);
    user1.Print();

    User user2(user1);
    user2.Print();
}