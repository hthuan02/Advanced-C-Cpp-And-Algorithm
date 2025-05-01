#include <stdio.h>

int main(int argc, char const *argv[]){
    void *ptr;

    int a = 10;
    ptr = &a;

    // (int*): ép kiểu cho con trỏ `*ptr`
    // *(int*)(ptr): giải tham chiếu
    printf("Dia chi: %p, Gia tri: %d\n", ptr, *(int*)(ptr));

    double b = 5.5;
    ptr = &b;
    printf("Dia chi: %p, Gia tri: %f\n", ptr, *(double*)(ptr));

    char c = 'C';
    ptr = &c;
    printf("Dia chi: %p, Gia tri: %c\n", ptr, *(char*)(ptr));

    char arr[] = "HELLLO"; // ký tự NULL ('\0') // báo hiệu kết thúc 
    ptr = arr;
    for (int i = 0; i < (sizeof(arr)/sizeof(arr[0])); i++)
    {
        printf("Địa chỉ = %p - Giá trị: %c\n", ptr+i, *(char*)(ptr+i));
    }

    // Khai báo mảng lưu trữ địa chỉ của các biến trên
    // Mảng con trỏ void, từng phần tử của nó là địa chỉ của biến khác
    void *ptr1[] = {&a, &b, &c, &arr};
    printf("Dia chi: %p, Gia tri: %d\n", ptr1[0], *(int*)(ptr1[0]));
    printf("Dia chi: %p, Gia tri: %f\n", ptr1[1], *(double*)(ptr1[1]));
    

    return 0;
}