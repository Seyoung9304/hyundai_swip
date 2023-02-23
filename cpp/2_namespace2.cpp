// 2_namespace2.cpp

#include <iostream>

namespace audio {
namespace mp3 {
    void play() { std::cout << "audio play" << std::endl; }
}
}

void play() { std::cout << "play" << std::endl; }

// namespace 사용하는 방법 3가지
// 1) 전체 이름을 사용하는 방법
#if 0
int main()
{
    audio::mp3::play();
    play();

    std::cout << "Hello, C++" << std::endl;
}
#endif

// 2) using 선언(declaration)
#if 0
using audio::mp3::play;
using std::cout;
using std::endl;

int main()
{
    // audio::mp3::play();
    play();

    cout << "Hello, C++" << endl;
}
#endif

#if 0
// 3) using 지시어(directive)
//  : 이름 공간안에 있는 모든 요소를 암묵적으로 접근할 수 있습니다.
//  > 이름 충돌 문제가 발생할 가능성이 높습니다.

using namespace std;
// using namespace audio::mp3;

int main()
{
    play();

    cout << "Hello, C++" << endl;
}
#endif

namespace aaa {
void goo() { }
}

void foo()
{
    using namespace aaa; // 선언의 스코프를 지역으로 제한할 수 있다.
    goo();
}

int main()
{
    aaa::goo();
}