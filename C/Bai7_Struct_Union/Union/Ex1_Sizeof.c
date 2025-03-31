#include <stdio.h>
#include <stdint.h>

typedef union Ex1
{
    uint8_t var1;  // 1 byte + 3padding
    uint32_t var2; // 4 byte
    uint16_t var3; // 2 byte + 2padding
} frame;

int main(int argc, char const *argv[])
{
    printf(" Size of data: %d\n");
    frame data;

    printf("Size = %d\n", sizeof(frame));

    return 0;
}