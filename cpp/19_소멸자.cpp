// 19_소멸자.cpp
#include <iostream>
#include <cstring>
using namespace std;

// 1. 사용자가 소멸자를 제공하지 않으면,
//    컴파일러는 아무일도 하지 않는 소멸자를 만들어줍니다.

// 2. 클래스 내부에서 자원(메모리, 파일)을 할당한경우,
//    객체가 파괴되는 시점에 소멸자를 통해 자원을 정리해주어야 합니다.
//    => 소멸자
//      - 소멸자 함수의 형태는 ~클래스이름() 형태입니다.
//      - 반환값도 없고, 반환타입도 명시하지 않습니다.
//      - 오버로딩도 불가능하고, 오직 1개만 제공할 수 있습니다.

class User {
    char* name;

public:
    ~User()
    {
        delete[] name;
    }

    User(const char* s)
    {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    void PrintName()
    {
        cout << name << endl;
    }
};

int main()
{
    User user("Tom");
    user.PrintName();
}