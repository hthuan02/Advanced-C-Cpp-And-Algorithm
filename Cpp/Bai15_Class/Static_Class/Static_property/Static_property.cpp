
#include <iostream>

using namespace std;

class HinhChuNhat{
    public:
        double chieuDai;  // property // 0xc0 - 0c7  object1 // 0x00 - 0x07   object2
        double chieuRong; // property // 0xc8 - 0xcf         // 0x08 - 0x0f
        // int var;       // property // 0xd0 - 0xd3         // 0x10 - 0x13

        /* Static
         * - Địa chỉ của biến static sẽ tồn tại xuyên suốt chương trình.
         * - Để sử dụng thì phải cấp phát địa chỉ thông qua truy cập từ class.
         * - Những object khác vùng địa chỉ sẽ được sử dụng chung biến var.
         */
        static int var; // property // 0xa0 - 0xa3 (chung cho cả 2object)
};

int HinhChuNhat::var; // Truy cập từ trong class, không cần object

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn1;
    HinhChuNhat hcn2;

    cout << "Address of var: " << &hcn1.var << endl; // &: C++ là tham chiếu
    cout << "Address of var: " << &hcn2.var << endl;
    return 0;
}

