// 24_객체복사27.cpp
#include <iostream>
#include <cstring>
using namespace std;

// 1. 클래스 내부에서 자원을 할당한 경우,
//    소멸자를 통해 자원을 해지해주어야 합니다.

// 2. 클래스 내부에서 포인터 멤버가 있을 경우,
//    "얕은 복사(Shallow Copy)" 문제가 발생합니다.
//   => 직접 복사 생성자를 정의해서, 문제를 해결해야 합니다.
//    1) 깊은 복사
//    2) 참조 계수
//    3) 복사 금지
#if 0
class User {
    char* name;
    int age;

public:
    ~User()
    {
        delete[] name; // !!!
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
    User user2 = user1;

    user1.Print();
    user2.Print();
}
#endif

#if 0
class User {
    char* name;
    int age;

public:
    ~User()
    {
        delete[] name; // !!!
    }

    // 깊은 복사 복사 생성자
    User(const User& rhs)
        : age(rhs.age)
    {
        name = new char[strlen(rhs.name) + 1];
        strcpy(name, rhs.name);
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
    User user2 = user1;

    user1.Print();
    user2.Print();
}
#endif

#if 0
class User {
    char* name;
    int age;
    int* ref; // !!!

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
        // 참조 계수 증가
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
    User user2 = user1;

    user1.Print();
    user2.Print();
}
#endif

class User {
    char* name;
    int age;

    // C++98
    // => 복사 생성자를 private 영역에 선언만 한다. => 복사 금지
    //  : 링크 오류

public:
    // C++11
    // => 복사 금지 문법 / Delete Function
    User(const User& rhs) = delete;

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
    // User user2 = user1;

    user1.Print();
    // user2.Print();
}