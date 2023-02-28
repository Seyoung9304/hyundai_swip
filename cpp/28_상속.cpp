#include <iostream>
#include <string>
using namespace std;

class User{
    string name;
    int age;
    string address;
public:
    string GetName() const {
        return name;
    }
    int GetAge() const {
        return age;
    }
    string GetAddress() const {
        return address;
    }
};

class Student : public User{
    int id;
public:
    int GetId() const {
        return id;
    }
};

class Teacher : public User{
    int major;
public:
    int GetMajor() const {
        return major;
    }
};