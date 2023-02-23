// 10_for.cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x[5] = { 10, 20, 30, 40, 50 };

    // index 정보가 필요할 때
    for (int i = 0; i < 5; ++i) {
        cout << x[i] << endl;
    }

    // index 정보가 필요하지 않을 때,
    //  : C++11 - ranged for
    for (auto e : x) {
        cout << e << endl;
    }

    char str[] = "hello"; // NULL까지 순회
    for (auto e : str) {
        cout << "str1: " << e << endl;
    }

    string str2 = "world"; // NULL 순회 안함
    for (auto e : str2) {
        cout << "str2: " << e << endl;
    }
}