#include <iostream>
#include <cstring>

using namespace std;

class User{
    char* name;

public:
    User(const char* s)
    {
        name = new char[strlen(s)+1];
        strcpy(name, s);
    }

    ~User()
    {
        delete[] name;
    }

    void PrintName()
    {
        cout << name << endl;
    }
};