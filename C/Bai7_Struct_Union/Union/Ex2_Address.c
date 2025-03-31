#include <stdio.h>
#include <stdint.h>

typedef union
{
    uint8_t var1; // 0-255
    uint32_t var2; //0-4294967295
    uint16_t var3; // 0-65535

    // Union sẽ lấy kiểu dữ liệu có kích thước lớn nhất 24 byte
} frame;

int main(int argc, char const *argv[])
{

    printf("Size = %d\n", sizeof(frame));
    frame data;
    data.var1 = 5;
    data.var2 = 6;
    data.var3 = 7;

    //Vì dữ liệu kiểu Union-> SD chung vùng nhớ
    //Lấy giá trị sau cùng
    printf("Var1 = %d\n", data.var1);
    printf("Var2 = %d\n", data.var2);
    printf("Var3 = %d\n", data.var3);
    return 0;
}