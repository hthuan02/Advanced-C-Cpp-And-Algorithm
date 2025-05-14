#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

int exception_code = 0;

double divide(int a, int b)
{
    if (a == 0 && b == 0) // Nếu a, b truyền vào ==0 hết, value ==1 truyền vào setjmp thứ 2
    {
        longjmp(buf, 1);
    }
    else if (b == 0)      // Nếu a,b truyền vào có b==0, value ==2 truyền vào setjmp thứ 3
    {
        longjmp(buf, 2);
    }

    return (double)a/b;
}

int main(int argc, char const *argv[])
{
    exception_code = setjmp(buf);    // Lưu vị trí hiện tại của `setjmp`

    if (exception_code == 0)         // Gọi `setjmp` lần đầu tiên, ==0

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
    {
        printf("Kết quả: %f\n",divide(6,0)); // a,b thỏa mãn, phép tính thực thi
    }
    else if (exception_code == 1)    // Lưu vị trí, setjmp ==2 -> Không tồn tại
    {
        printf("Không tồn tại!\n");
    }
    else if (exception_code == 2)    // Lưu vị trí, setjmp ==3 -> Chia cho 0 
    {
        printf("Chia cho 0\n");
    }


    return 0;
}


