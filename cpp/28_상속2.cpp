// 28_상속2.cpp
#include <iostream>
using namespace std;

#if 0
class Dog {
    int age;
    int color;
};

class Cat {
    int age;
    double speed;
};
#endif

class Animal {
    int age;
};

class Dog : public Animal {
    int color;
};

class Cat : public Animal {
    double speed;
};

int main()
{
    cout << sizeof(Dog) << endl;
    cout << sizeof(Cat) << endl;
}