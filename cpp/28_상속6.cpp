// 28_상속6.cpp

#include <iostream>
using namespace std;

class Animal {
    int age_;

public:
    Animal(int age)
        : age_(age)
    {
    }
};

class Dog : public Animal {
    int color_;

public:
    Dog(int age, int color)
        : Animal(age)
        , color_(color)
    {
    }
};

int main()
{
}