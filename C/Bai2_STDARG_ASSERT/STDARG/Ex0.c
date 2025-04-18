#include <stdio.h>
#include <stdarg.h>

void test(int count, ...)
{ 
    va_list args; 
    // typedef char* va_list;
    // char* args;
    // args = "int count, 1, 2, 6"


    va_start(args, count); // args = "1,2,6" / args = {"\001","\002","\006"}(escape character)

    printf("value 1: %d\n",va_arg(args, int)); // (int)"\001" = 1, ép kiểu int // (int)'1' = mã ASCII
    printf("value 2: %d\n",va_arg(args, int)); // (int)"\002" = 2, int
    printf("value 3: %d\n",va_arg(args, int));
    printf("value 4: %f\n",va_arg(args, double));
    printf("value 5: %c\n",va_arg(args, char*)); // Chuỗi phải ép về kiểu `char*`
    printf("value 6: %s\n",va_arg(args, char*));

}

int main(int argc, char const *argv[])
{
    test(6, 1, 2, 6, 3.15, 'a',"HELLO");  // count: để xác định số lượng tham số
    
    return 0; 
}
