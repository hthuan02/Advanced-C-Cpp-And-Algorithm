#include <stdio.h>
#include <stdlib.h>

/**
 * l: left
 * r: right
 * x: số cần tìm
 */
int binarySearch(int *arr, int l, int r, int x)
{
    // Điều kiện để bắt đầu tìm kiếm
    // Dùng while nếu không dùng đệ quy
    if (r >= l)
    {
        /**
         * Tính trung bình cộng, so sánh:
         * - Nếu mid = x, trả về giá trị mid
         * - Nếu mid > x, dùng đệ quy quay lại binarySearch, tìm kiếm bên trái
         */

        int mid = (r + l) / 2;

        if (arr[mid] == x)
            return mid;

        // Đệ quy trả về cái hàm
        // Số cần tìm < mid: bên trái
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Số cần tìm > mid: bên phải
        return binarySearch(arr, mid + 1, r, x); // Trả về số tìm kiếm
    }

    return -1; // Không có số đó trong  mảng muốn tìm
}

// Hàm hoán đổi trong hàm sắp xếp phần tử
void swap(int *a, int *b)
{
    int temp = *a; // 0x02 (10), 0x03 (20)
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp mảng tăng dần
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - i - 1; j++)
        {

            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

int main()
{
    int n, x, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);

    // Dùng malloc để cấp phát động theo số lượng phần tử nhập vào
    int *arr = (int *)malloc(n * sizeof(int));

    // Tạo 1 mảng ban đầu, chưa được sắp xếp
    printf("Nhap cac phan tu cua mang: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Gọi lại hàm sắp xếp và in ra mảng mới đã sắp xếp
    bubbleSort(arr, n);
    for (i = 0; i < n; i++)
    {
        printf("i = %d\n", arr[i]);
    }

    // Nhập số cần tìm
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);

    /**
     * Thực hiện tìm kiếm
     * left = 0
     * right = n-1
     */
    int result = binarySearch(arr, 0, n - 1, x);
    if (result == -1)
        printf("Khong tim thay %d trong mang.\n", x);
    else
        printf("Tim thay %d tai vi tri %d trong mang.\n", x, result);
    free(arr);
    return 0;
}
