#include <stdio.h>

void count()
{
    // Static cục bộ
    static int a = 5;
    a++;
    printf("Gia tri: %d\n", a);
}

int main(int argc, char const *argv[])
{
    count();
    count();
    count();
    count();
}