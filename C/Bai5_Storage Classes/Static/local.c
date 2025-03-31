#include <stdio.h>

// Đặt con trỏ để thay đổi giá trị
int *ptr = NULL;
void count()
{
    // Static cục bộ
    static int a = 5;
    ptr = &a;
    a++;
    printf("Gia tri: %d\n", a);
}

int main(int argc, char const *argv[])
{
    count();
    count();
    count();
    *ptr = 99;
    count();
}