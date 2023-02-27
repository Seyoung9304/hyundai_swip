// 23_위임생성자.cpp
#include <iostream>
using namespace std;

#if 0
class Color {
    int red;
    int green;
    int blue;

private:
    void init() { }

public:
    Color()
        : red(0)
        , green(0)
        , blue(0)
    {
        init();
    }

    Color(int r, int g, int b)
        : red(r)
        , green(g)
        , blue(b)
    {
        init();
    }
};
#endif

class Color {
    int red;
    int green;
    int blue;

private:
    void init() { }

public:
    // 위임 생성자 => C++11
    //  정의: 자신의 다른 생성자를 통해 객체를 초기화할 수 있습니다.
    //   "생성자에서 다른 생성자를 호출할 수 있습니다."

    //  효과
    //  - 생성자 코드에서 발생하는 코드 중복을 해결할 수 있습니다.

    Color()
        : Color(0, 0, 0) // Color::Color(int, int, int)
    {
    }

    Color(int r, int g, int b)
        : red(r)
        , green(g)
        , blue(b)
    {
        init();
    }
};

int main()
{
}
