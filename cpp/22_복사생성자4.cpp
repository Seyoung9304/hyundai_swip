// 22_복사생성자4.cpp
#include <iostream>
using namespace std;

#if 0
class Color {
    int red;
    int green;
    int blue;

public:
    Color()
        : red(0)
        , green(0)
        , blue(0)
    {
    }

    Color(int r, int g, int b)
        : red(r)
        , green(g)
        , blue(b)
    {
    }
};

class Button {
    Color backgroundColor;

public:
    // void SetColor(Color c)
    void SetColor(const Color& c)
    {
        backgroundColor = c;
    }

    void SetColor(Color&& r)
    {
        cout << "r" << endl;
        backgroundColor = r;
    }
};

int main()
{
    Color bg(10, 20, 30);

    Button b;
    b.SetColor(bg);
    b.SetColor(Color(10, 20, 30));

    // 임시 객체
    //  - TYPE()
    //  - Point(10, 20)

    // 1) 함수가 값으로 반환할 때, 생성될 수 있습니다.
    // 2) 임시 객체는 rvalue 입니다.
    //  - const & 통해서 참조하거나,
    //    rvalue reference를 통해서 참조할 수 있습니다.
}
#endif

class Temp {
public:
    Temp() { cout << "Temp()" << endl; }
    ~Temp() { cout << "~Temp()" << endl; }
};

int main()
{
    cout << "----" << endl;
    const Temp& r = Temp();
    cout << "----" << endl;
}