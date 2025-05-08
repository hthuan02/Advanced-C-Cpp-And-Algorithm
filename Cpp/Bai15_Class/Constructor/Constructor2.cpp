
#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;  // property // 0xc0 - 0c7
    double chieuRong; // property // 0xc8 - 0xcf
    void DienTich();  // method

    // Cách 2: Constructor không có tham số truyền vào
    HinhChuNhat()
    {
        chieuDai = 20;
        chieuRong = 30;
    }
};

void HinhChuNhat::DienTich() // :: là toán tử truy cập
{
    cout << "Dien tich = " << chieuDai * chieuRong << endl;
}

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn; // object // 0xc0
    // hcn.chieuDai = 10;
    // hcn.chieuRong = 20;
    hcn.DienTich();
    return 0;
}
