// main.c
#include <stdio.h>

extern int add(int a, int b);

int main(void)
{
    int result = add(10, 20);
    printf("result: %d\n", result);

    return 0;
}