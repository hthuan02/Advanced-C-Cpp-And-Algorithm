#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...) // count: tham số cố định, đại diện cho số lượng tham số biến đổi
{
    va_list args;
    va_start(args, count);

    int result = 0;
    for (int i = 0; i < count; i++)
    {
        result += va_arg(args, int);
    }

    va_end(args);
    return result;
}

int main()
{
    printf("Sum: %d\n", sum(3, 1, 5, 9));
    
    printf("Sum: %d\n", sum(5, 1, 5, 9, 10, 15));

    return 0;
}

