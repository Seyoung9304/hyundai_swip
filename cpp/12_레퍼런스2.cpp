// 12_레퍼런스2.cpp
#include <iostream>
using namespace std;

// call by value
void inc1(int x) { ++x; }

// call by pointer
void inc2(int* p)
{
    if (p) {
        ++(*p);
    }
}

// call by reference
void inc3(int& r) { ++r; }

#if 1
int main()
{
    int n = 10;

    inc1(n);
    inc2(&n);
    inc3(n);

    cout << n << endl;
}
#endif
