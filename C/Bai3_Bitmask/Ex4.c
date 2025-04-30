/*************************************************************
 * Quản lý thông tin cho 1 chiếc xe gồm: màu sắc, động cơ,
 * năng lượng và thông tin bổ sung.
 *************************************************************/

#include <stdio.h>
#include <stdint.h>


// Thông tin mang nhiều giá trị cần nhiều bit tương ứng (2 bit được bật)
#define COLOR_RED   0 // 0b0000 0000
#define COLOR_BLUE  1 // 0b0000 0001
#define COLOR_BLACK 2 // 0b0000 0010
#define COLOR_WHITE 3 // 0b0000 0011

#define POWER_100HP 0
#define POWER_150HP 1
#define POWER_200HP 2

#define ENGINE_1_5L 0
#define ENGINE_2_0L 1

typedef uint8_t CarColor; // typedef là từ khóa định nghĩa lại biến
typedef uint8_t CarPower;
typedef uint8_t CarEngine;

// Các thông tin bổ sung, cần 2 bit lưu trữ  (3 bit được bật)
#define SUNROOF_MASK        1 << 0  // 0001 
#define PREMIUM_AUDIO_MASK  1 << 1  // 0010
#define SPORTS_PACKAGE_MASK 1 << 2  // 0100
// Thêm các bit masks khác tùy thuộc vào tùy chọn

// Để quản lý cùng lúc nhiều thông tin, phải dùng struct để gom tất cả thông tin
typedef struct
{   
    // bit-field (trong struct): quy định số bit cụ thể để sử dụng `:2`, `:3`,...
    CarColor color : 2;            // 2 bit cho màu sắc (`:2` Sử dụng 2 bit trong tổng số 8 bit khai báo)
    CarPower power : 2;            // 2 bit cho năng lượng
    CarEngine engine : 1;          // 1 bit cho động cơ // CarEngine engine;(chiếm 1 byte)
    uint8_t additionalOptions : 3; // 3 bit  cho các tùy chọn bổ sung
} CarOptions;


void configureCar(CarOptions *car, CarColor color, CarPower power, CarEngine engine, uint8_t options)
{
    car->color = color;
    car->power = power;
    car->engine = engine;
    car->additionalOptions = options;
}

void setOption(CarOptions *car, uint8_t optionMask)
{
    car->additionalOptions |= optionMask;
}

void unsetOption(CarOptions *car, uint8_t optionMask)
{
    car->additionalOptions &= ~optionMask;
}

void displayCarOptions(const CarOptions car)
{
    const char *colors[] = {"Red", "Blue", "Black", "White"};
    const char *powers[] = {"100HP", "150HP", "200HP"};
    const char *engines[] = {"1.5L", "2.0L"};

    printf("Car Configuration: \n");
    printf("Color: %s\n", colors[car.color]);
    printf("Power: %s\n", powers[car.power]);
    printf("Engine: %s\n", engines[car.engine]);
    printf("Sunroof: %s\n", (car.additionalOptions & SUNROOF_MASK) ? "Yes" : "No");
    printf("Premium Audio: %s\n", (car.additionalOptions & PREMIUM_AUDIO_MASK) ? "Yes" : "No");
    printf("Sports Package: %s\n", (car.additionalOptions & SPORTS_PACKAGE_MASK) ? "Yes" : "No");
}

int main()
{
    CarOptions myCar;
    configureCar(&myCar, COLOR_BLACK, POWER_150HP, ENGINE_2_0L, 0);
   

    setOption(&myCar, SUNROOF_MASK);
    setOption(&myCar, PREMIUM_AUDIO_MASK);
   
    displayCarOptions(myCar);

    unsetOption(&myCar, PREMIUM_AUDIO_MASK);
    displayCarOptions(myCar);

    printf("size of my car: %d\n", sizeof(CarOptions));
    return 0;
}

