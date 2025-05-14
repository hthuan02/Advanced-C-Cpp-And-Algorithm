#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

int exception_code = 0;

/************************************************************************
 * `if(exception_code == 0)` = `if((exception_code = setjmp(buf)) == 0)` 
 * 
 * TRY: là định nghĩa 1 khối lệnh để kiểm tra có phát sinh lỗi hay không
 * 
 * Tạo macro TRY
 * #define TRY if((exception_code = setjmp(buf)) == 0)
 * 
 * Tạo macro CATCH, value env của setjmp
 * #define CATCH(x) else if(exception_code = x) 
 * 
 * Tạo macro THROW, value của longjmp
 * #define THROW(x) longjmp(buf, x)
 *   
 *************************************************************************/ 
 #define TRY if((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if(exception_code = x) 
#define THROW(x) longjmp(buf, x)

double divide(int a, int b)
{
    if (a == 0 && b == 0) // Nếu a, b truyền vào ==0 hết, value ==1 truyền vào setjmp thứ 2
    {
        THROW(1);
    }
    else if (b == 0)      // Nếu a,b truyền vào có b==0, value ==2 truyền vào setjmp thứ 3
    {
        THROW(2);
    }

    return (double)a/b;
}

int main(int argc, char const *argv[])
{
    TRY
    {
        printf("Kết quả: %f\n",divide(0,0)); // a,b thỏa mãn, phép tính thực thi
    }

    CATCH(1)
    {
        printf("Không tồn tại!\n");
    }
    CATCH(2)
    {
        printf("Chia cho 0!\n");
    }

    return 0;
}


