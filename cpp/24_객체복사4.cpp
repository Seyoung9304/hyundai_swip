// 24_객체복사4.cpp
#include <iostream>
#include <cstring>
using namespace std;

// 3. 해결 방법
//  1) 깊은 복사
//  2) 참조 계수(Reference Counting)
//  3) 복사 금지

class User {
    char* name;
    int age;

    // 복사 금지
    //  - private 영역에 선언만 합니다. => 링크 오류
    // User(const User& rhs);

    // C++11: 복사 금지(delete function)
    User(const User& rhs) = delete;
    User& operator=(const User& rhs) = delete;

public:
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
        cout << name << ", " << age << endl;
    }
};

int main()
{
    User user1("Tom", 42);
    user1.Print();

    User user2(user1); // 복사금지 시켜놓았기에 오류 발생
    // user2.Print();
}