#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint8_t var1;  // 0-255
    uint32_t var2; // 0-4294967295
    uint16_t var3; // 0-65535

} frame;

int main(int argc, char const *argv[])
{

    printf("Size = %d\n", sizeof(frame));
    frame data;

    data.var2 = 4294967294;

    printf("Var1 = %d\n", data.var1); // 254
    printf("Var2 = %u\n", data.var2); // 4294967294
    printf("Var3 = %d\n", data.var3); // 65534
    return 0;
}