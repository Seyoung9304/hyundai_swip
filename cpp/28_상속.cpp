// 28_상속.cpp
// => 객체 지향 언어의 핵심적인 문법입니다.
#include <iostream>
#include <string>
using namespace std;

#if 0
class Student {
    string name;
    int age;
    string address;
    int id;

public:
    string GetName() const { return "name:" + name; }
    int GetAge() const { return age; }
    string GetAddress() const { return address; }
    int GetId() const { return id; }
};

class Teacher {
    string name;
    int age;
    string address;
    int major;

public:
    string GetName() const { return "name:" + name; }
    int GetAge() const { return age; }
    string GetAddress() const { return address; }
    int GetMajor() const { return major; }
};
#endif
class User {
    string name;
    int age;
    string address;

public:
    string GetName() const { return "name:" + name; }
    int GetAge() const { return age; }
    string GetAddress() const { return address; }
};

class Student : public User {
    int id;

public:
    int GetId() const { return id; }
};

class Teacher : public User {
    int major;

public:
    int GetMajor() const { return major; }
};

int main()
{
    Student s;
    Teacher t;

    s.GetAddress();
    s.GetAge();
    s.GetId();

    t.GetAddress();
    t.GetAge();
    t.GetMajor();
}