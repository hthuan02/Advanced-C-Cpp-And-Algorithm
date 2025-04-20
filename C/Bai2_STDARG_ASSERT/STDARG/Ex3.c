#include <stdio.h>
#include <stdarg.h>

#define tong(...)   sum(__VA_ARGS__, '\n')

int sum(int count, ...)
{
    va_list args;
    va_list check;

    va_start(args, count);
    va_copy(check, args);

    int result = count; 
    
    while ((va_arg(check, char*)) != (char*)'\n')
    {
        result += va_arg(args, int);
    }
    
    va_end(args); // Thu hồi 1 trong 2: args hoặc check
    
    return result;
}

int main()
{
    printf("Tổng: %d\n", tong(3, 1, -1, 0, 1, 2, 3, 15)); // Nhược điểm là chỉ tính tổng số trước số 0, tới 0 while sẽ dừng lại

    return 0;
}

