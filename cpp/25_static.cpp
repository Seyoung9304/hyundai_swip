// 25_static.cpp
#include <iostream>
using namespace std;

#if 0
// 전역 변수 문제점
// : 클래스의 상태를 외부에서 함부로 변경할 수 있습니다.
//  "정보 은닉" => 접근 지정자
int cnt = 0;

// Car 객체가 몇개 생성되었는지 관리하고 싶습니다.
class Car {

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

int main()
{
    Car c[5];

    cout << c[0].GetCount() << endl;
}
#endif

class Car {
private:
    static int cnt; // 정적 멤버 데이터 선언(헤더 파일)

public:
    Car() { ++cnt; }
    ~Car() { --cnt; }

    int GetCount() { return cnt; }
};

// 정적 멤버 데이터 변수는 외부 정의가 반드시 필요합니다.
int Car::cnt = 0; // 정적 멤버 데이터 정의(소스 파일)

int main()
{
    Car c[5];

    // cout << Car::cnt << endl;
    cout << c[0].GetCount() << endl;
}