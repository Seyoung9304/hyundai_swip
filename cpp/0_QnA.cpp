
#include <iostream>
using namespace std;

class Sample {
    const char* name;

public:
    Sample(const char* s)
    {
        name = s;
        cout << "Sample(): " << name << endl;
    }
    ~Sample() { cout << "~Sample(): " << name << endl; }
};

Sample s2("global");

int main()
{
    cout << "--------" << endl;
    Sample s("local");

    cout << "--------" << endl;
}