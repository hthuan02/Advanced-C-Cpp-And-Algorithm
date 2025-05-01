#include <stdio.h>

void swap(int *a, int *b) // 0x01 = 10, 0xa4 = 20
{
    int tmp = *a; // tmp = 10
    *a = *b;       // a = 20
    *b = tmp;     // b = 10
}

void input(int *a, int *b)
{
    printf("Nhập a: "); scanf("%d", a); // Truyền vào `a` không truyền `&a`
    printf("Nhập b: "); scanf("%d", b);
}

int main()
{
   int a = 10, b = 20; // 0x01: 10; 0xa4: 20
   input(&a, &b);
   swap(&a, &b);
   printf("value a is: %d\n", a); // 20
   printf("value b is: %d\n", b); // 10
   return 0;
}

