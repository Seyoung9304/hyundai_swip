// 24_객체복사.cpp
#include <iostream>
#include <cstring>
using namespace std;

// 1. 소멸자를 반드시 정의해야 하는 경우
//  - 객체 내부에서 자원을 할당하는 경우

// 2. 복사생성자를 반드시 직접 정의해야 하는 경우
//  - 객체가 포인터 멤버 데이터를 가지고 있는 경우
//    반드시 복사 생성자를 제공해서, 얕은 복사의 문제를 해결해야 합니다.

class User {
    char* name;
    int age;

public:
    // 컴파일러가 만들어주는 복사 생성자의 형태
    User(const User& rhs)
        : name(rhs.name)
        , age(rhs.age)
    {
    }

    ~User() { delete[] name; }

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

    User user2(user1);
    user2.Print();
}