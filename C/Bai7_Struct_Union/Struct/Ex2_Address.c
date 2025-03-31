// double(8byte): Chia het 8, 0x00 0x08 0x10 0x18,..
// int, int32_t, uint32_t(4byte): 0x00 0x04 0x08 0x0C...
// float, init16_t, uint16_t(2byte): 0x00 0x02 0x04 0x06...\

#include <stdio.h>
#include <stdint.h> // Thư viện để sử dụng uint32_t, uint8_t, uint16_t

typedef struct
{
    uint32_t var1;
    uint8_t var2;
    uint16_t var3;
} data; // Tên kiểu dữ liệu là data

int main(int argc, char const *argv[])
{
    printf(" Size of data: %d\n");
    data data;

    printf("Address of var1: %p\n", &data.var1);
    printf("Address of var2: %p\n", &data.var2);
    printf("Address of var3: %p\n", &data.var3);

    return 0;
}