#include <stdio.h>

int main()
{
    int value = 5;
    int test = 8;
    int const *ptr_const = &value;

    //*ptr_const = 7;    // wrong, k thể thay đổi giá trị bằng giải tham chiểu
    //ptr_const = &test; // right, thay đổi địa chỉ trỏ đến
   
    printf("value: %d\n", *ptr_const);

    value = 9;
    printf("value: %d\n", *ptr_const);
    return 0;
}

