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

#if 0
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
#endif

// 부모 클래스, Base, Super
class Animal {
    int age;
};

// C++ 상속
//  : class 자식클래스 : public 부모클래스

// 자식 클래스, Derived, Sub
class Dog : public Animal {
    int color;
};

int main()
{
    cout << sizeof(Animal) << endl;
    cout << sizeof(Dog) << endl;
}