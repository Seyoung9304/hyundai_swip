// 3_iostream.cpp
#include <iostream>
#include <iomanip> // setw / setfill ...
using namespace std;

// stdio.h => cstdio
// 표준 입력: scanf
// 표준 출력: printf
#if 0
int main()
{
    int n;
    scanf("%d", &n);
    printf("n: %d\n", n);

    cin >> n;
    cout << "n :" << n << endl;

    char str[32];
    scanf("%s", str);
    printf("str: %s\n", str);

    cin >> str;
    cout << "str: " << str << endl;
}
#endif

int main()
{
    // 1111 1010 1111 1010
    // int n = 0xFAFA;

    // C++11에서 2진 상수 표현 문법이 도입되었습니다.
    //  => 작은 따옴표를 통해 가독성을 높일 수 있습니다.
    int n = 0b1'111'1010'111110'10;
    printf("%x\n", n); 
    printf("%X\n", n); //대문자로 출력

    cout << hex << n << endl;
    cout << hex << uppercase << n << endl;
    cout << dec;
    cout << n << endl;

    printf("%010d\n", n);
    cout << setw(10) << setfill('0') << n << endl;

    // IO 조정자
    //   : hex, uppercase, dec
    //     setfill, setw => iomanip 헤더 추가
}