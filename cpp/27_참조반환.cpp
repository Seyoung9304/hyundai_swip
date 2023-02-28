// 27_참조반환.cpp
#include <iostream>
#include <string>
using namespace std;

#if 0
class User {
    string name_;
    int age_;
    string address_;
    string company_;

public:
    // 접근자 메소드 - Setter
    void SetName(const string& name) { name_ = name; }
    void SetAge(int age) { age_ = age; }
    void SetAddress(const string& address) { address_ = address; }
    void SetCompany(const string& company) { company_ = company; }
};

int main()
{
    User user;
    user.SetName("Bob");
    user.SetAge(42);
    user.SetAddress("Seoul");
    user.SetCompany("Hyundai");
}
#endif

#if 0
class User {
    string name_;
    int age_;
    string address_;
    string company_;

public:
    // 접근자 메소드 - Setter
    User* SetName(const string& name)
    {
        name_ = name;
        return this;
    }

    User* SetAge(int age)
    {
        age_ = age;
        return this;
    }

    User* SetAddress(const string& address)
    {
        address_ = address;
        return this;
    }

    User* SetCompany(const string& company)
    {
        company_ = company;
        return this;
    }
};

int main()
{
    User user;
    user.SetName("Bob");
    user.SetAge(42);
    user.SetAddress("Seoul");
    user.SetCompany("Hyundai");

    user.SetName("Bob")
        ->SetAge(42)
        ->SetAddress("Seoul")
        ->SetCompany("Hyundai");
}
#endif

class User {
    string name_;
    int age_;
    string address_;
    string company_;

public:
    // 접근자 메소드 - Setter
    User& SetName(const string& name)
    {
        name_ = name;
        return *this;
    }

    User& SetAge(int age)
    {
        age_ = age;
        return *this;
    }

    User& SetAddress(const string& address)
    {
        address_ = address;
        return *this;
    }

    User& SetCompany(const string& company)
    {
        company_ = company;
        return *this;
    }
};

int main()
{
    User user;
    user.SetName("Bob");
    user.SetAge(42);
    user.SetAddress("Seoul");
    user.SetCompany("Hyundai");

    user.SetName("Bob")
        .SetAge(42)
        .SetAddress("Seoul")
        .SetCompany("Hyundai");
}