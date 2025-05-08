#include<stdio.h>
#include<stdlib.h>

//Dùng đệ quy, nếu k dùng đệ quy thì dùng vòng lặp While

int binarySearch(int* arr, int l, int r, int x)
{ // trả về int, chỉ số con số tìm kiếm, -1 con số k có trong mảng mình tìm
// l- r, x là số mình tìm
    if(r>=1)
    {
        int mid = (r+1)/2;

        if(arr[mid] == x) return mid; // đệ quy

        if(arr[mid]>x) return binarySearch(arr,1,mid-1,x);

        return binarySearch(arr,mid+1,r,x);
        //Tìm kiếm bên phải - thay đổi left, và ngược lại
    }
}


void swap(int *a, int *b)
{
    int temp =*a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for(i=0;i< n-1;i++)
    {
        for(j=0;j<n-1-1;j++)
        {

        }
    }
}

int main()
{
    int n,x,i;
    printf("Nhap vao so phan tu cua mang:");
    scanf("%d",&n);

    //malloc
    int *arr = (int*)malloc(n * sizeof(int));
    printf("Nhap vao cac phan tu cua mang:");

}

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int* arr, int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (r + l) / 2;

  
        if (arr[mid] == x)  return mid;

   
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

  
        return binarySearch(arr, mid + 1, r, x);
    }




    return -1;
}

void swap(int *a, int *b)
{
    int temp = *a; // 0x02 (10), 0x03 (20)
    *a = *b;
    *b = temp;
}

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
