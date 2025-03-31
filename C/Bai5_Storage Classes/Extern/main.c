#include <stdio.h>
#include "File1.c"

extern int var_global;

extern void display();

int main(int argc, char const *argv[])
{
    display();
    return 0;
}

// gcc main.c File1.c -o main