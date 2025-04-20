#include <stdio.h>
#include <assert.h>

#define LOG(condition, cmd) assert(condition && #cmd)

double divide(int a, int b)
{   

    // assert(b != 0 && "Lỗi chia cho 0");
    LOG(b != 0, Lỗi chia cho 0);
    return (double)a/b;
}

int main(int argc, char const *argv[])
{
    int x = 5;

    // assert(x == 5 && "X phải bằng 5");

    LOG(x == 5, X phải bằng 5);
    printf("x = %d\n", x);

    printf("Kết quả phép chia: %f\n",divide(2,0));
    return 0;
}
