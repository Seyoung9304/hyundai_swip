// 2_namespace.cpp
#include <iostream>

// namespace
//  왜?
//  > 이름 충돌을 해결하기 위해서 도입된
//    문법입니다.
//  1. C는 이름 충돌을 해결할 수 있는 문법이
//     없기 때문에, 이름규칙을 약속해야합니다.
//  2. C++은 이름 충돌을 해결하기 위해
//     namespace를 약속합니다.

// 효과
//  1) 이름 충돌 해결
//  2) 프로그램의 각 요소를 관련된 요소끼리 그룹화할 수 있습니다.

// a.cpp
namespace audio {
void init() { std::cout << "audio init" << std::endl; }

namespace mp3 {
    void play() { }
}
namespace mp4 {
    void play() { }
}

};

// b.cpp
namespace video {
void init() { std::cout << "video init" << std::endl; }
}

int main()
{
    audio::init();
    video::init();

    audio::mp3::play();
    audio::mp4::play();
}