// 32_연산자오버로딩3.cpp
#include <iostream>

namespace xstd {
class istream {
public:
    istream& operator>>(int& n)
    {
        scanf("%d", &n);
        return *this;
    }

    istream& operator>>(double& d)
    {
        scanf("%lf", &d);
        return *this;
    }
};

istream cin;
}

// using namespace std;
using namespace xstd;

int main()
{
    int n;
    double d;
    cin >> n >> d;
    // cin.operator>>(n).operator>>(d)

    printf("%d %lf\n", n, d);
}
