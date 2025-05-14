#include <stdio.h>
#include <setjmp.h>

jmp_buf buf; // tham số bên trong hàm kiểu `jmp_buf`, khai báo toàn cục để truyền nhiều hàm 

int exception = 0;

void func2()
{
    printf("This is function 2\n");
    longjmp(buf, 2); // nhảy ngược về func1, gửi giá trị 2 cho func1
}

void func3()
{
    printf("This is function 3\n");
    longjmp(buf, 3); // nhảy ngược về func1, gửi giá trị 3 cho func1
}

void func1()
{
    exception = setjmp(buf); // lưu vị trí gọi setjmp
    if (exception == 0)      // Gọi setjmp lần đầu tiên, = 0
    {
        printf("This is function 1\n");
        printf("exception = %d\n", exception);
        func2();            // ==0 nên gọi func2
    }
    else if (exception == 2)
    {
        printf("exception = %d\n", exception);
        func3();            // ==2, gọi hàm func3
    }
    else if (exception == 3)
    {                       // ==3, kết thúc chương trình    
        printf("exception = %d\n", exception); 
    }
}

int main(int argc, char const *argv[])
{
    func1();
    return 0;
}


