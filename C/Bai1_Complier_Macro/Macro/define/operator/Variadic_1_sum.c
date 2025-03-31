#include <stdio.h>

#define sum(...) \
int arr[] = {__VA_ARGS__, 0}; \
int tong = 0;                 \
int i = 0;                    \
while (arr[i] != 0){           \
  tong += arr[i];             \
  i++;                        \
}                             \
printf("Tong = %d\n", tong);                      

int main(int argc, char const *argv[])
{
    sum(1, 2);

    return 0;
}
