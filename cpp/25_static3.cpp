// 25_static3.cpp
#include <iostream>
using namespace std;

class AAA {
public:
    int a; // 멤버 데이터
    static int b; // 정적 멤버 데이터

    void hoo() { }

    void foo() // void foo(Sample* this)
    {
        cout << "foo" << endl;

        a = 42;
        this->a = 42; // !!!!
        hoo(); // this->hoo();  // !!!!

    } // 멤버 함수

    static void goo()
    {
        cout << "goo" << endl;

        // a = 42; /* 오류 */
        // goo(); /* 오류 */

    } // 정적 멤버 함수
};

int AAA::b = 100; // 정적 멤버 데이터 외부 정의

// 1. 정적 멤버 데이터
//  1) 클래스이름::변수명 - *
//  2) 객체.변수명

// 2. 멤버 함수는 객체를 통해서만 접근 가능하기 때문에,
//    객체를 생성하지 않고 호출이 불가능합니다.
//   => this가 전달되어야 하기 때문입니다.

// 3. 정적 멤버 함수는 객체를 생성하지 않고 호출 가능합니다.
//   => this가 전달되지 않기 때문입니다.
//   1) 클래스이름::함수명()
//   2) 객체.함수명()

// 4. 멤버 함수는 this가 전달되기 때문에,
//    멤버 함수 안에서 멤버 데이터를 접근하거나, 멤버 함수를 호출할 수 있습니다.

// 5. 정적 멤버 함수는 this가 전달되지 않기 때문에,
//    정적 멤버 함수 안에서 멤버 데이터에 접근하거나, 멤버 함수를 호출할 수 없습니다.

int main()
{
    cout << AAA::b << endl; // 정적 멤버 데이터
    // 객체를 생성하지 않아도, 접근이 가능합니다.

    AAA::goo();

    AAA aaa;
    cout << aaa.b << endl;
    aaa.goo();

    AAA bbb;
    cout << sizeof(aaa) << endl; // ???
    cout << sizeof(bbb) << endl; // ???
}