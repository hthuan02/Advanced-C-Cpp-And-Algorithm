
#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    double chieuDai;  // property // 0xc0 - 0c7
    double chieuRong; // property // 0xc8 - 0xcf
    void DienTich();  // method

    // Cách 3: Constructor có tham số truyền vào, không có tham số mặc định
    // HinhChuNhat(int dai, int rong)
    // {
    //     chieuDai = dai;
    //     chieuRong = rong;
    // }

    // Cách 4: Viết kiểu khác của cách 3, có tham số mặc định 
    HinhChuNhat(int dai = 5, int rong = 20) : chieuDai(dai), chieuRong(rong)
    {
        DienTich();
    }
};

void HinhChuNhat::DienTich() // :: là toán tử truy cập
{
    cout << "Dien tich = " << chieuDai * chieuRong << endl;
}

int main(int argc, char const *argv[])
{
    HinhChuNhat hcn(15, 10); // object // 0xc0
    HinhChuNhat hcn1;
    // hcn.chieuDai = 10;
    // hcn.chieuRong = 20;
    // hcn.DienTich();
    return 0;
}
