#include <stdio.h>

typedef struct
{
    char *name;
    int age;
    char *addr;
} User;

User user1, user2, *user3;

int main()
{   
    // Truy xuất dữ liệu đối với biến
    user1.name = "Anh";
    user1.age = 23;
    user1.addr = "HCM";

    // Đối với con trỏ
    user3->name = "Trung";
    user3->age = 30;
    user3->addr = "Da Nang";

    return 0;
}