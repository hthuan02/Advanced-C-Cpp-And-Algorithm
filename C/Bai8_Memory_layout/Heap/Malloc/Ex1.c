#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // Cấp phát vùng nhớ mảng 100 phần tử int
    // sizeof(int) = 4
    int *a = (int *)malloc(100 * sizeof(int));
    // Cấp phát vùng nhớ mảng 1000 phần tử char
    // sizeof(char) = 1
    char *c = (char *)malloc(1000 * sizeof(char));
    return 0;
}