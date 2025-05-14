#include <stdio.h>

typedef struct
{
    char name;
    int age;
    char *addr;
} User;

User user1, user2, *user3;

int main()
{   
    printf("Kích thước struct: %d bytes\n",sizeof(User));

    return 0;
}