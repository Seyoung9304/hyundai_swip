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

public:
    ~User()
    {
        if (--(*ref) == 0) {
            delete[] name;
            delete ref;
        }
    }

    User(const User& rhs)
        : name(rhs.name)
        , age(rhs.age)
        , ref(rhs.ref)
    {
        ++(*ref);
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