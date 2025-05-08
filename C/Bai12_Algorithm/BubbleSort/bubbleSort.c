#include <stdio.h>

// Hàm in mảng
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Hàm sắp xếp nổi bọt
void bubbleSort(int arr[], int n)
{
    // Duyệt qua từng phần tử 0 đến n-2
    for (int i=0; i<=n-2; i++)
    {
        // Duyệt qua từng phần tử 0 đến n-i-2
        for (int j=0; j<=n-i-2; j++)
        {
            // Mỗi lần sẽ so sánh từng cặp liền kề (j và j+1)
            // Nếu j > j+1 thì hoán đổi vị trí j và j+1
            if (arr[j] > arr[j+1])
            {   
                // Thực hiện hoán đổi trực tiếp 
                // Hoặc tách ra hàm `swap()` rồi gọi ra
                int temp = arr[j];
                arr[j]   = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }  
}

int main ()
{
    int arr[] = {1, 3, -3, -8, 5, 10, 13, 9, 12, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Mảng ban đầu: ");
    
    printArray(arr, n);
    bubbleSort(arr, n);

    printf("Mảng sau khi sắp xếp: ");
    printArray(arr, n);
    
    return 0;
}