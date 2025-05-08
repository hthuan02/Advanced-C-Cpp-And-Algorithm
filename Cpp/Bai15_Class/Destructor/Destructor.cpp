
#include <iostream>

using namespace std;

class HinhChuNhat
{
public:
    string name_;     // Ở C là dùng char*
    double chieuDai;  // property // 0xc0 - 0c7
    double chieuRong; // property // 0xc8 - 0xcf
    void DienTich();  // method

    HinhChuNhat(string name, int dai = 5, int rong = 20) : name_(name), chieuDai(dai), chieuRong(rong)
    {
        cout << "Khởi tạo object: " << name_ << endl;
    }

    // Last In-First Out
    ~HinhChuNhat()
    {
        cout << "Destructor:" << name_ << endl;
    }
};

void HinhChuNhat::DienTich() // :: là toán tử truy cập
{
    cout << "Diện tích = " << chieuDai * chieuRong << endl;
}

void test()
{
    HinhChuNhat hcn1("Hình 1", 10, 20); // lưu ở Stack (LI-FO)
    HinhChuNhat hcn2("Hình 2", 15, 30);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
