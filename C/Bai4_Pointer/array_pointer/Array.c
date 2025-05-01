#include<stdio.h>
  
int main(){
    int arr[] = {1, 2, 3, 4, 5}; // Số lượng * sizeof(int) = 20byte
  
    int n = (sizeof(arr)/sizeof(arr[0])); // Tính số lượng

    int *ptr = arr; // mảng thì không cần dấu '&'
  
    // ptr:    vùng địa chỉ phần tử đầu tiên 0
    // ptr+1:  vùng địa chỉ phần tử thứ 1
    // ptr+2:  vùng địa chỉ phần tử thứ 2
    
    // ptr + i.sizeof(data_type)
    for (int i = 0; i < n; i++)
    {
        printf("Địa chỉ = %p - Giá trị: %d\n", ptr+i, *(ptr+i));
    }

    return 0;
}