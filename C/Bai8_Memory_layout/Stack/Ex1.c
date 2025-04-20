#include <stdio.h>

int total(int a, int b)
{
    int c;
    c = a + b;
    return c;
}

int main(int argc, char const *argv[])
{
    printf("a+b = %d\n", total(5, 6));
}