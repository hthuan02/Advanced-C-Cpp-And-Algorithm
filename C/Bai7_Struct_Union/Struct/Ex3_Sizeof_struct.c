#include <stdio.h>
#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t  var1[4];    // 1 byte × 9
    uint16_t var2[10];   // 2 byte × 10
    uint32_t var3[5];    // 4 byte × 2
    uint64_t var4[3];    // 8 byte × 3
} User;

int main() {
    printf("Kích thước từng thành viên:\n");
    printf(" - sizeof(var1): %zu\n", sizeof(((User *)0)->var1));
    printf(" - sizeof(var2): %zu\n", sizeof(((User *)0)->var2));
    printf(" - sizeof(var3): %zu\n", sizeof(((User *)0)->var3));
    printf(" - sizeof(var4): %zu\n", sizeof(((User *)0)->var4));

    printf("\nOffset từng thành viên:\n");
    printf(" - Offset of var1: %zu\n", offsetof(User, var1));
    printf(" - Offset of var2: %zu\n", offsetof(User, var2));
    printf(" - Offset of var3: %zu\n", offsetof(User, var3));
    printf(" - Offset of var4: %zu\n", offsetof(User, var4));

    size_t total_member_size = sizeof(((User *)0)->var1) +
                               sizeof(((User *)0)->var2) +
                               sizeof(((User *)0)->var3) +
                               sizeof(((User *)0)->var4);

    size_t struct_size = sizeof(User);
    size_t padding = struct_size - total_member_size;

    printf("\nTổng kích thước struct: %zu bytes\n", struct_size);
    printf("Tổng kích thước thực của dữ liệu: %zu bytes\n", total_member_size);
    printf("Padding (phần dư): %zu bytes\n", padding);

    return 0;
}
