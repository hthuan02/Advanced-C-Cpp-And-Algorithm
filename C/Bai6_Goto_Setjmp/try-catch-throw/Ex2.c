#include <stdio.h>
#include <setjmp.h> // thư viện để sử dụng setjmp, longjmp

jmp_buf buf;        // biến môi trường `buf` kiểu `jmp_buf`

int exception_code; // biến đọc giá trị khi `setjmp` trả về    

// Danh sách enum, gồm những lỗi có thể có thay thế 1 2,...
typedef enum
{
    NO_ERROR,       // Không có lỗi
    NO_EXIT,        // Không  tồn tại
    DIVIDE_BY_0     // Lỗi chia 0
} ErrorCodes;  

#define TRY if ((exception_code = setjmp(buf)) == 0)
#define CATCH(x) else if (exception_code == x)
#define THROW(x) longjmp(buf, x)

double divide(int a, int b)
{
    if (a == 0 && b == 0)
    {
        THROW(NO_EXIT);
    }
    else if (b == 0)
    {
        THROW(DIVIDE_BY_0);
    }

    return (double)a/b;
}

int main(int argc, char const *argv[])
{
    exception_code = NO_ERROR;

    TRY
    {
        printf("Ket qua: %0.3f\n", divide(0,0));
    }
    CATCH(NO_EXIT)
    {
        printf("ERROR! Không tồn tại\n");
    }
    CATCH(DIVIDE_BY_0)
    {
        printf("ERROR! Chia cho 0\n");
    }

    // thêm code ở đây
    printf("Hello world\n");
    return 0;
}


