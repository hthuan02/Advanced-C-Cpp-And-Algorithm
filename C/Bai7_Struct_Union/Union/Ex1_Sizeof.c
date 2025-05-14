#include <stdio.h>
#include <stdint.h>

typedef union Ex1
{

    uint8_t  a;	// 1 + 15 padding 
    uint16_t b[5];	// 10 + 6 padding
    uint32_t c;	// 4 + 12 padding
    double   d;	// 8 + 8 padding
} frame;

int main(int argc, char const *argv[])
{
    printf(" Size of data: %d\n");
    frame data;

    printf("Size = %d\n", sizeof(frame));

    return 0;
}