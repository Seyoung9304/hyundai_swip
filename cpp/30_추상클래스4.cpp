// 30_추상클래스4.cpp
#include <iostream>
using namespace std;

//  C++11: Modern C++
// Java 8: Modern Java

// 인터페이스 문제점
//  - 새로운 함수의 추가가 어렵습니다.
//  - ISP(Interface Segregation Principle, 인터페이스 분리 원칙)
//   : 범용 인터페이스 보다 세분화된 인터페이스가 낫다.

struct MP3 {
    virtual ~MP3() { }

    virtual void Play() = 0;
    virtual void Stop() = 0;

    // virtual void PlayOneMinute() = 0;

    // defender method
    //  : 인터페이스에 기본 구현을 제공함으로써, 확장할 수 있습니다.
    virtual void PlayOneMinute()
    {
        Play();
        // 1분 후
        Stop();
    }
};

class Sample1 : public MP3 {
public:
    void Play() override { }
    void Stop() override { }
};

class Sample2 : public MP3 {
public:
    void Play() override { }
    void Stop() override { }
};

int main()
{
}