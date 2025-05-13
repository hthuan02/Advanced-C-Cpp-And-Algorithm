#include <stdio.h>

// Đặt con trỏ để thay đổi giá trị
int *ptr = NULL;
void count()
{
    // Static cục bộ
    static int a = 5; // 0x01 0x02 0x03 0x04
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