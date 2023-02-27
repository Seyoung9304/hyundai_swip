// 25_static4.cpp
#include <iostream>
#include <string>
using namespace std;

class Test {
public:
    int n = 10; // C++11, 필드 초기화
    // static int s = 0; // 허용 X

    constexpr static int c = 42; // 허용!
};

int main()
{
    cout << Test::c << endl;
}

// email / facebook

// 생성자 오버로딩 한계
//  1. 동일한 타입의 생성자를 여러개 만들 수 없습니다.
//  2. 생성자 호출 형식으로 생성의 방법을 짐작하기 어렵다.
// => 정적 멤버 함수를 통해 객체를 생성하는 방법을 통해 해결할 수 있습니다.

// 팩토리: 객체를 생성하는 역활
#if 0
class User {
    string id;

    User(const string& i)
        : id(i)
    {
    }

public:
    // 정적 팩토리 함수
    static User CreateUserWithEmail(const std::string& email)
    {
        return User(email);
    }

    static User CreateUserWithFacebook(const std::string& facebookId)
    {
        return User(facebookId);
    }
};

int main()
{
    User user = User::CreateUserWithEmail("hello@gmail.com");
    User user2 = User::CreateUserWithFacebook("aslkdjalks");
}
#endif

#if 0
class User {
    string id;

public:
    User(const string& email) { }
    User(const string& facebookId) { }
};

int main()
{
    User user1("hello@gmail.com");
    User user2("facebook@...");
}
#endif

#if 0
class Cursor {
private:
    Cursor() { }

    Cursor(const Cursor&) = delete;

public:
    static Cursor& GetInstance()
    {
        static Cursor instance;
        return instance;
    }

    void Move(int x, int y) { }
};

int main()
{
    Cursor& c1 = Cursor::GetInstance();
    c1.Move(10, 20);
}
#endif

#if 0
class Car {
    static int count;

public:
    static int GetCount() { return count; }
};

int Car::count = 0;

int main()
{
}
#endif