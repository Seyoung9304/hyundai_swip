// main.c
#include <stdio.h>

extern int _Z3addii(int a, int b);

int main(void)
{
    int result = _Z3addii(10, 20);
    printf("result: %d\n", result);

    return 0;
}