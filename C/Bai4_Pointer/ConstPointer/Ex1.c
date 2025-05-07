#include<stdio.h>

int a = 10;
int b = 3;
int *const ptr = &a;

int main()
{
    printf("%p\n", ptr);
    printf("%d\n", *ptr); // ptr_const = 10

    *ptr = 15; // Thay đổi giá trị tại con trỏ
    printf("%p\n", ptr);
    printf("%d\n", *ptr); // ptr_const = 15
}