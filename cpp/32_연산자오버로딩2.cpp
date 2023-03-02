#include <iostream>
#include <cstdio>

namespace xstd {
class ostream {
public:
    ostream& operator<<(int n)
    {
        printf("%d", n);
        return *this;
    }

    ostream& operator<<(double d)
    {
        printf("%lf", d);
        return *this;
    }
};

ostream cout;
}

using xstd::cout;
// using namespace std;

int main()
{
    int n = 10;
    cout << n;
    // cout.operator<<(int n)

    double d = 3.14;
    cout << d;
    // cout.operator<<(double d)

    cout << n << d;
    // cout.operator<<(n).operator<<(d);
}