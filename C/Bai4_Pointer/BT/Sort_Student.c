// Sắp xếp lại thông tin SV: Tên, điểm, ID

#include <stdio.h>
#include <string.h>

/*************************************************************************
 * @struct  SinhVien
 * @brief   Cấu trúc dữ liệu lưu trữ thông tin sinh viên
 * @details Cấu trúc này bao gồm tên, điểm trung bình và ID của sinh viên.
 *************************************************************************/
typedef struct
{
    char ten[50];
    float diemTrungBinh;
    int id;
} SinhVien;

/*************************************************************************
 * @brief   So sánh hai chuỗi ký tự
 * @details Hàm so sánh hai chuỗi ký tự từng ký tự một.
 *          Nếu chuỗi đầu lớn hơn chuỗi thứ hai thì trả về giá trị dương,
 *          ngược lại trả về giá trị âm, và trả về 0 nếu hai chuỗi bằng nhau
 * @param   str1    Con trỏ tới chuỗi ký tự đầu 
 * @param   str2    Con trỏ tới chuỗi ký tự hai
 * @return  int     Kết quả so sánh giữa hai chuỗi
 *************************************************************************/
// Vì sao tham số truyền vào là con trỏ hằng, cú pháp so sánh, kq trả về unsigned? 
 int stringCompare(const char *str1, const char *str2)
{
    while (*str1 && (*str1 == *str2))
    {
        str1++;
        str2++;
    }
    return (*(const unsigned char*)str1 - *(const unsigned char*)str2);
}

/*************************************************************************
 * @brief   So sánh hai tên của sinh viên
 * @details Sử dụng hàm `stringCompare` để so sánh trường `ten` của hai sinh viên.
 * @param   a   Con trỏ tới đối tượng sinh viên đầu tiên 
 * @param   a   Con trỏ tới đối tượng sinh viên thứ hai
 * @return  int     Kết quả so sánh tên của hai sinh viên
 *************************************************************************/
// Vì sao tham số truyền vào là con trỏ hằng + con trỏ void, ss tên mà kp const char, return?
 int compareByName(const void *a, const void *b)
{
    SinhVien *sv1 = (SinhVien *)a;
    SinhVien *sv2 = (SinhVien *)b;
    return stringCompare(sv1->ten, sv2->ten);
}

/*************************************************************************
 * @brief   Hàm so sánh điểm trung bình của hai sinh viên
 * @details Sử dụng hàm `diemTrungBinh` của hai sinh viên.
 *          Trả về 1 meeis `sv1` có điểm trung bình lớn hơn `sv2`, nhỏ hơn
 *          thì trả về -1, ngược lại thì trả về 0.
 * @param   a   Con trỏ tới đối tượng sinh viên đầu tiên 
 * @param   a   Con trỏ tới đối tượng sinh viên thứ hai
 * @return  int     Kết quả so sánh điểm trung bình
 *************************************************************************/
// Tại sao ss điểm tb kp là const double, float
int compareByDiemTrungBinh(const void *a, const void *b)
{
    SinhVien *sv1 = (SinhVien *)a;
    SinhVien *sv2 = (SinhVien *)b;
    if (sv1->diemTrungBinh > sv2->diemTrungBinh) return 1;
    return 0;
}

/*************************************************************************
 * @brief   Hàm so sánh ID của hai sinh viên
 * @details So sánh giá trị của trường `id` giữa hai sinh viên.
 * @param   a   Con trỏ tới đối tượng sinh viên đầu tiên 
 * @param   a   Con trỏ tới đối tượng sinh viên thứ hai
 * @return  int     Kết quả so sánh ID trung bình
 *************************************************************************/
// tại sao ID kp là const int mà const void. Tại sao tất cả là cons void
int compareByID(const void *a, const void *b)
{
   SinhVien *sv1 = (SinhVien *)a;
   SinhVien *sv2 = (SinhVien *)b;
   return sv1->id - sv2->id;
}

// Hàm sắp xếp chung
// i < size - 1 và i <= size -2
// i = 6
// TH1: i < 5: 0 1 2 ...4 (5 lượt)
// TH2: i <=4: 0 1 2 ...4 (5 lượt)
void sort(SinhVien array[], size_t size, int (*compareFunc)(const void *, const void *))
{   
    // Duyệt từng phần từ
    for (int i=0; i<size-1; i++) // Số lượt
    {   
        // Duyệt
        for (int j=0; j<size-i-1; j++) // Số lần so sánh
        {
            // So sánh từng cặp liền kề
            // so sánh khi j > j+1
            if (compareFunc(array+j, array+j+1)>0)
            {   
                // Thực hiện hoán đổi swap()
                SinhVien temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }        
}

void display(SinhVien *array, size_t size)
{
   for (size_t i = 0; i < size; i++)
   {
       printf("ID: %d, Ten: %s, Diem Trung Binh: %.2f\n", array[i].id, array[i].ten, array[i].diemTrungBinh);
   }
   printf("\n");
}

int main() {
    SinhVien danhSachSV[] =
    {
        {  
            .ten = "Hoang",
            .diemTrungBinh = 7.5,
            .id = 100
        },
        {
            .ten = "Tuan",
            .diemTrungBinh = 4.5,
            .id = 101
        },
        {
            .ten = "Vy",
            .diemTrungBinh = 6.8,
            .id = 102},
        {  
            .ten = "Ngan",
            .diemTrungBinh = 5.6,
            .id = 10
        },
    };

    size_t size = sizeof(danhSachSV) / sizeof(danhSachSV[0]);

    // Sắp xếp theo tên
    sort(danhSachSV, size, compareByName);
    display(danhSachSV, size);

    // Sắp xếp theo điểm trung bình
    sort(danhSachSV, size, compareByDiemTrungBinh);
    display(danhSachSV, size);

    // Sắp xếp theo ID
    sort(danhSachSV, size, compareByID);
    display(danhSachSV, size);

    return 0;
}

