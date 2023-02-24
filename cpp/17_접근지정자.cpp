// 17_접근지정자.cpp
#include <iostream>
#include <string>
using namespace std;

// 1. struct: 기본 접근 지정자가 public 입니다.
//     class: 기본 접근 지정자가 private 입니다.

// 2. public: 외부에서 접근이 가능합니다.
//   private: 외부에서 접근이 불가능합니다.

// 3. friend
//    - 클래스에서 friend로 선언된 함수나 클래스는
//      자신의 private 멤버에 접근이 가능합니다.

class User {
private:
    string name;
    int age;

public:
    // > 접근자 메소드 - getter
    // string GetName() { return name; }
    // int GetAge() { return age; }

    User(string s, int n)
    {
        name = s;
        age = n;
    }

    // 캡슐화의 정책을 깨뜨리지 않고, 캡슐화의 경계를 확장할 수 있습니다.
    friend void PrintUser(User user);
    friend class UserPrinter;
};

class UserPrinter {
public:
    void PrintUser(User user)
    {
        cout << user.name << ", " << user.age << endl;
    }
};

void PrintUser(User user)
{
    cout << user.name << ", " << user.age << endl;

    // cout << user.GetName() << ", " << user.GetAge() << endl;
}

int main()
{
    User user("Tom", 42);
    PrintUser(user);

    UserPrinter printer;
    printer.PrintUser(user);
}

#if 0
struct AAA {
    int a; // public
};

class BBB {
    int b; // private
};

int main()
{
    AAA a;
    a.a = 10; /* OK */

    BBB b;
    b.b = 10; /* NO */
}
#endif