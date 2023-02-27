// 24_객체복사5.cpp
#include <iostream>
#include <cstring>
using namespace std;

// 3. 해결 방법
//  1) 깊은 복사
//  2) 참조 계수(Reference Counting)
//  3) 복사 금지
//-------------
//  4) rvalue reference, 소유권 이전

class User {
    char* name;
    int age;

public:
    // 깊은 복사
    User(const User& rhs)
        : age(rhs.age)
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
    }

    // Move constructor => 소유권 이전
    User(User&& rhs)
        : name(move(rhs.name))
        , age(move(rhs.age))
    {
        cout << "User&&" << endl;
        rhs.name = nullptr;
        rhs.age = 0;
    }

    ~User()
    {
        delete[] name;
    }

    User(const char* s, int n)
        : age(n)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    void Print()
    {
        printf("name: %p\n", name);

        if (name) {
            cout << name << ", " << age << endl;
        }
    }
};

int main()
{
    User user1("Tom", 42);
    user1.Print();

    // User user2(move(User("Bob", 100)));

    User user2(move(user1));
    user2.Print();
    user1.Print();
}