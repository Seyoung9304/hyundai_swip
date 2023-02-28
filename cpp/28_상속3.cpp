// 28_상속3.cpp
#include <iostream>
using namespace std;

// 1. 부모 클래스의 private은 자식 클래스에서도 접근이 불가능합니다.

// 2. C++ 접근 지정자 3가지
//   -   private: 외부 접근 불가능, friend 가능, 자식 불가능
//   -    public: 외부 접근 가능
//   - protected: 외부 접근 불가능, 자식 가능
#if 0
class Animal {
protected:
    int age = 100;
};

class Dog : public Animal {
public:
    void PrintAge() const
    {
        cout << age << endl;
    }
};

int main()
{
    Dog d;
    d.PrintAge();

    // cout << d.age << endl; - 오류
}
#endif

#if 1
// 클래스의 멤버 데이터는 private으로 두는 것이 좋습니다.
class Animal {
    int age = 100;

protected:
    int GetAge() const { return age; }
};

class Dog : public Animal {
public:
    void PrintAge() const
    {
        // cout << age << endl;
        cout << GetAge() << endl;
    }
};

int main()
{
    Dog d;
    d.PrintAge();

    // cout << d.age << endl; - 오류
}
#endif