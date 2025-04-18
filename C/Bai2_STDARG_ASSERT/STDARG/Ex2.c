#include <stdio.h>
#include <stdarg.h>

#define tong(...)   sum(__VA_ARGS__, 0)

// tong(3,1,4,5,-1,-2) -> sum(3,1,4,5,-1,-2,0) 

// K biết được số lượng tham số ban đầu -> while
int sum(int count, ...)
{
    va_list args;

    va_start(args, count);

    /************************************************************************
     * Khởi tạo result mang giá trị tham số đầu tiên count
     * Khi tính tổng thì đã có sẵn giá trị rồi và cộng dồn giá trị tiếp theo
     ************************************************************************/
    int result = count; 
    
    int value; // Biến tạm, để lưu trữ tạm thời giá trị để so sánh

    // Duyệt qua từng phần tử, khác 0 thì cộng dồn vào
    while ((value = va_arg(args, int)) != 0)
    {
        result += value;

        // Nếu không dùng biến tạm
        /**********************************************************************
         * result += va_arg(args, int);
         *
         * Gặp vấn đề: 
         * va_arg() lấy giá trị trước để so sánh
         * nhưng khi cộng thì cộng giá trị tiếp theo, bỏ qua 1 giá trị
         **********************************************************************/
    }
    
    va_end(args);
    
    return result;
}

int main()
{
    printf("Tổng: %d\n", tong(3, 1, -1, 0, 1, 2, 3, 15)); // Nhược điểm là chỉ tính tổng số trước số 0, tới 0 while sẽ dừng lại

    return 0;
}

