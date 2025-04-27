#include <stdio.h>
#include <stdint.h>

// Quy định từng biến mang thông tin gì, bằng macro định nghĩa
#define GENDER        1 << 0  // Bit 0: 0 = Nữ, 1 = Nam                 0b00000001 << 0
#define TSHIRT        1 << 1  // Bit 1: 0 = Không, 1 = Có               0b00000010
#define HAT           1 << 2  // Bit 2: 0 = Không, 1 = Có               0b00000100
#define SHOES         1 << 3  // Bit 3: 0 = Không, 1 = Có               0b00001000      
#define FEATURE1      1 << 4  // Bit 4: Tính năng 1                     0b00010000
#define FEATURE2      1 << 5  // Bit 5: Tính năng 2                     0b00100000
#define FEATURE3      1 << 6  // Bit 6: Tính năng 3                     0b01000000
#define FEATURE4      1 << 7  // Bit 7: Tính năng 4                     0b10000000


// enable bit (0 -> 1)
// Tham số thứ 1: Truyền vào giá trị con trỏ, mang địa chỉ của 1 biến khacs
// Tham số thứ 2: Truyền vào từng bit mình muốn bật lên (đã quy định ở macro)

/*********************************************************************************************
 * Nếu không dùng con trỏ
 * Khi truyền vào biến `uint8_t features` hàm này cũng cấp pháp ra vùng nhớ để lưu trữ
 * 0xa5: 0b00000000(địa chỉ khác với 0x01)
 * -> Copy dữ liệu từ 0x01 qua 0xa5
 * -> Hàm không tác động đến 0x01, chỉ tác động 0xa5. Nên không thay đổi được biến gốc 0x01
 * -> Mà mục tiêu là thay đổi giá trị từng Bit của 0x01. Để thay đổi được thì phải biết địa chỉ.
 * 
 * Để thao tác với địa chỉ phải sử dụng con trỏ `*features`.
 * 0xa5:0x01 (lưu địa chỉ của biến gốc)
 * -> Thay đổi trực tiếp giá trị của features (32p)
 *********************************************************************************************/
void enableFeature(uint8_t *features, uint8_t feature)
{
    *features |= feature;
}

void disableFeature(uint8_t *features, uint8_t feature)
{
    *features &= ~feature;
}

int isFeatureEnabled(uint8_t features, uint8_t feature)
{
    return (features & feature) != 0;
}

void listSelectedFeatures(uint8_t features)
{
    printf("Selected Features:\n");

    if (features & GENDER) {
        printf("- Gender\n");
    }
    if (features & TSHIRT) {
        printf("- T-Shirt\n");
    }
    if (features & HAT) {
        printf("- Hat\n");
    }
    if (features & SHOES) {
        printf("- Shoes\n");
    }

    for (int i = 0; i < 8; i++)
    {
        printf("feature selected: %d\n", (features >> i) & 1);
    }
   
    // Thêm các điều kiện kiểm tra cho các tính năng khác
}

int main()
{   
    // Máy tính chỉ hiểu, 1 là địa chỉ, 2 là giá trị tại địa chỉ đó. Nên khi khai báo 1 biến, CPU sẽ có 1 nơi để lưu trữ địa chỉ VD: 0x01
    uint8_t options = 0;    // 0x01: 0b0000 0000

    // Mục tiêu: tác động từng Bit để thay đổi thành các giá trị cụ thể, mà để thay đổi được biến thì cần xác định địa chỉ
    // Vì vậy, muốn thay đổi biến `options` thông qua các hàm, thì phải biết đc địa chỉ 

    // Thêm tính năng
    enableFeature(&options, GENDER | TSHIRT | HAT);

    // Xóa tính năng
    disableFeature(&options, TSHIRT);

    // Liệt kê các tính năng đã chọn
    listSelectedFeatures(options);
   
    return 0;
}

