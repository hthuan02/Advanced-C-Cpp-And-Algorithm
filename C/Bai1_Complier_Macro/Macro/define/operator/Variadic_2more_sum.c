#include <stdio.h>

#define sum(...)                    \
do {                                \
    int arr[] = {__VA_ARGS__, 0};   \
    int tong = 0;                   \
    int i = 0;                      \
    while (arr[i] != 0) {           \
        tong += arr[i];             \
        i++;                        \
    }                               \
    printf("Tong = %d\n", tong);     \
} while (0)                         

int main(int argc, char const *argv[])
{
    sum(1, 2);
    sum(1, 2, 3);
    sum(1, 3, 5, 7, 9, 12, 15);

    return 0;
}   