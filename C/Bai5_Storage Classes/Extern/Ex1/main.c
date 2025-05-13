#include <stdio.h>


extern int var_global;

extern void display();

int main(int argc, char const *argv[])
{
    display();
    return 0;
}

// nếu không khai báo include<File1.c>
// gcc main.c File1.c -o main
// ./main