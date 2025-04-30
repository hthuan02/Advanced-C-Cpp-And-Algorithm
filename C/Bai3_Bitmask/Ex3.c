#include <stdio.h>
#include <stdint.h>

// 2 thông tin riêng biệt, mỗi thông tin chỉ mang 1 giá trị đơn (1/0).
#define ENABLE  1   // 0b0000 0001 (1 bit được bật)
#define DISABLE 0   // 0b0000 0000

typedef struct
{
    uint8_t LED1 : 1;  // 0b0000 0001 (bit 0)
    uint8_t LED2 : 1;  // 0b0000 0010 (bit 1)
    uint8_t LED3 : 1;  // 0b0000 0100 (bit 2)
    uint8_t LED4 : 1;  // 0b0000 1000 (bit 3)
    uint8_t LED5 : 1;  // 0b0001 0000 (bit 4)
    uint8_t LED6 : 1;  // 0b0010 0000 (bit 5) 
    uint8_t LED7 : 1;  // 0b0100 0000 (bit 6)
    uint8_t LED8 : 1;  // 0b1000 0000 (bit 7)
} LEDStatus;

void displayAllStatusLed(LEDStatus status)
{
    uint8_t *statusPtr = (uint8_t*)&status; // 0x01

    for (int j = 0; j < 8; j++) // j = 0, 1, 2
    {
        // ledStatus  0b0101 0101 (1,3,5,7)
        // AND        0b0000 0001

        // >>0  0b0101 0101 Led1 = 1 (Sáng)
        // >>1  0b0010 1010 Led2 = 0
        // >>2  0b0001 0101 Led3 = 1 (Sáng)
        // >>3  0b0000 1010 Led4 = 0
        // >>4  0b0000 0101 Led5 = 1 (Sáng)
        // >>5  0b0000 0010 Led6 = 0 
        // >>6  0b0000 0001 Led7 = 1 (Sáng)
        // >>7  0b0000 0000 Led8 = 0

        printf("LED%d: %d\n", j+1, (*statusPtr >> j) & 1);
    }
}


int main()
{   
    
    LEDStatus ledStatus = {.LED7 = ENABLE, .LED5 = ENABLE};
    // Chỉ định rõ sẽ gán giá trị ENABLE cho LED7, LED5 trong struct

    // Bật LED 1 và 3
    ledStatus.LED1 = ENABLE;
    ledStatus.LED3 = ENABLE;

    // 0bxxxx xxxx
    // 0b0101 0101 (ledStatus-giá trị gốc ban đầu) // 0x01
    displayAllStatusLed(ledStatus);
    return 0;
}

