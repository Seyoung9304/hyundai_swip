// add.cpp
#include <iostream>

extern "C" int add(int a, int b)
{
    std::cout << "C++" << std::endl;
    return a + b;
}