#include <stdio.h>

int a = 5;
static int b = 6; // Lưu ở data (Static global)
void *ptr = &b;   // Data

void test()
{
    static int c = 7; // Static local
}

int main(int argc, char const *ptr[])
{
    a = 15;
    b = 16;
    printf("a=%d\n", a);
    printf("b=%d\n", b);
    return 0;
}