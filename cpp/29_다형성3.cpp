// 29_다형성3.cpp
#include <iostream>
#include <vector>
using namespace std;

#if 0
class Dog { };
class Cat { };

int main()
{
    vector<Dog*> dogs;
    vector<Cat*> cats;
}
#endif

class Animal { };
class Dog : public Animal { };
class Cat : public Animal { };

// 활용 2. 동종을 보관하는 컨테이너를 정의할 수 있습니다.
int main()
{
    vector<Animal*> v;
    // 모든 동물 타입을 저장할 수 있는 컨테이너(컬렉션) 입니다.
}

#if 0
#include <vector> // 동적 배열, 템플릿

int main()
{
    int arr[10];

    vector<int> v = { 1, 2, 3, 4, 5 };

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (auto e : v) {
        cout << e << endl;
    }

    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
}
#endif