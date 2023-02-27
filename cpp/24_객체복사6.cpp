// 24_객체복사6.cpp
#include <iostream>
using namespace std;

#include <memory>

// - 깊은 복사
// - 참조 계수: shared_ptr(자원 공유)
//   복사 금지 + 소유권 이전: unique_ptr(자원 독점)
class Resource {
public:
    Resource() { cout << "Resource()" << endl; }
    ~Resource() { cout << "~Resource()" << endl; }
};

int main()
{
    std::unique_ptr<Resource> p1(new Resource);
    // std::unique_ptr<Resource> p2 = p1; /* 금지되었습니다. */
    cout << "p1: " << p1 << endl;

    std::unique_ptr<Resource> p2 = std::move(p1);
    cout << "p1: " << p1 << endl;
    cout << "p2: " << p2 << endl;
}

#if 0
int main()
{
    std::shared_ptr<Resource> p1(new Resource); // ref: 1
    std::shared_ptr<Resource> p2 = p1; // ref: 2

    cout << "------" << endl;
    p1 = nullptr; // ref: 1
    cout << "------" << endl;
    p2 = nullptr; // ref: 0 => 소멸자 호출
    cout << "------" << endl;
}
#endif