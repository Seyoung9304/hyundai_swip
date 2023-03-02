// 0_QnA3.cpp

// stack 만들고 싶습니다.
// 이미 잘 만들어진 vector가 있습니다.

#include <iostream>
#include <vector>
using namespace std;

// Adapter Pattern
// : 기존 클래스를 재활용해서, 인터페이스만 변경해서,
//   새로운 클래스처럼 제공하는 설계 방법
#if 0
class stack : public vector<int> {
public:
    void push(int n)
    {
        vector<int>::push_back(n);
    }

    int& top()
    {
        return vector<int>::back();
    }
    void pop()
    {
        return vector<int>::pop_back();
    }
};

int main()
{
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
#endif

// Stack Adapter
#if 0
template <typename T>
class stack : private vector<T> {
public:
    void push(const T& n)
    {
        vector<T>::push_back(n);
    }

    T& top()
    {
        return vector<T>::back();
    }

    void pop()
    {
        return vector<T>::pop_back();
    }
};
#endif

#include <list>

// 포함 => 기존 클래스를 재활용하는데 가장 보편적으로 사용되는
//        설계 방법
template <typename T, typename C = list<int>>
class stack {
    C v;

public:
    void push(const T& n)
    {
        v.push_back(n);
    }

    T& top()
    {
        return v.back();
    }

    void pop()
    {
        return v.pop_back();
    }
};

int main()
{
    // stack<int, vector<int>> s;
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);

    // s.pop_back(); // !!!

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}