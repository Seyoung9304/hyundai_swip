// 29_다형성9.cpp
#include <iostream>
using namespace std;

class Animal {
    int color;

public:
    virtual void Go() { cout << "Animal Go" << endl; }
    virtual void Hello() { cout << "Animal Go" << endl; }
};

class Dog : public Animal {
public:
    void Go() override { cout << "Dog Go" << endl; }
};

int main()
{
    cout << sizeof(Animal) << endl;
}

#if 0
int main()
{
    Animal a;
    Dog d;

    Animal* p = &a;
    p->Go();

    p = &d;
    p->Go();
}
#endif