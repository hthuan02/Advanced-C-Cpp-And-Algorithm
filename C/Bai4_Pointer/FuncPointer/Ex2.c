#include<stdio.h>

void tong(int a, int b){ printf("Tổng: %d\n", a+b);}

void hieu(int a, int b){ printf("Hiệu: %d\n", a-b);}
        
void tich(int a, int b){ printf("Tích: %d\n", a*b);}

void thuong(int a, int b){ printf("Hiệu: %f\n", (double)a/b);}

void tinhtoan(void(*pheptinh)(int, int), int a, int b){ pheptinh(a,b); }


int main(){
    
    // Cách 1: Khai báo con trỏ hàm như biến
    // void (*ptr)(int, int);
    
    // ptr = tong;
    // ptr(2,3);

    // ptr = hieu;
    // ptr(2,3);

    // ptr = tich;
    // ptr(2,3);

    // ptr = thuong;
    // ptr(2,3);

    // Cách 2: Khai báo con trỏ hàm như 1 mảng
    // void (*ptr1[])(int, int) = {tong, hieu, tich, thuong};
    
    // ptr1[0](2,3);
    // ptr1[1](2,3);
    // ptr1[2](2,3);
    // ptr1[3](2,3);

    // Cách 3: Khai báo con trỏ hàm như thâm số truyền vào 
    tinhtoan(tong, 2, 3);
    tinhtoan(hieu, 2, 3);
    tinhtoan(tich, 2, 3);
    tinhtoan(thuong, 2, 3);

    return 0;
}