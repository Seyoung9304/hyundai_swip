// 21_초기화리스트3.cpp
#include <iostream>
#include <string>
using namespace std;

// C++에서 멤버 데이터를 초기화하는 방법 2가지
// 1. 초기화 리스트
// 2. 필드 초기화 - C++11

// > 초기화리스트로 초기화된 값이 최종 초기화 값입니다.

class User {
    string name = "Tom";
    int age = 42;

public:
    User() { }

    User(string s, int n)
        : name(s)
        , age(n)
    {
    }

    void Print()
    {
        cout << name << ", " << age << endl;
    }
};

int main()
{
    // User user("Bob", 100);
    User user;
    user.Print();
}