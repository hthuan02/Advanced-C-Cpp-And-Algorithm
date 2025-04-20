#include <stdio.h>

typedef struct
{
    int x;
    int y;
} Point_data;

Point_data p1 = {5, 7}; // data
Point_data p2;          // bss

int a = 0; // bss
int b = 5; // data

static int m = 0; // bss
static int n;     // bss

void test()
{
    static int c = 0; // bss
    static int d;     // bss
}

int main(int argc, char const *agrv[])
{
    /*code*/
    return 0;
}