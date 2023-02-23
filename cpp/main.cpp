// main.cpp - C++
#include <iostream>
using namespace std;

extern "C" int add(int a, int b);

int main()
{
    int result = add(10, 20);
    cout << result << endl;
}

// $ g++ main.cpp -c
// $ gcc add.c -c