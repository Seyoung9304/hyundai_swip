// 3_iostream.cpp
#include <iostream>
using namespace std;

// stdio.h => cstdio
// 표준 입력: scanf
// 표준 출력: printf

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
