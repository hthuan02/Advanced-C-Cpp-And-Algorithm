
#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;  // property // 0xc0 - 0c7     // 0x00 - 0x07   object2
    double chieuRong; // property // 0xc8 - 0xcf    // 0x08 - 0x0f
    static int var;   // property // 0xa0 - 0xa3

    static void display()
    {
        cout << "This is static method" << endl;
        var = 20;
    }
};

int HinhChuNhat::var;

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn1;
    HinhChuNhat hcn2;

    HinhChuNhat::display();
    return 0;
}
