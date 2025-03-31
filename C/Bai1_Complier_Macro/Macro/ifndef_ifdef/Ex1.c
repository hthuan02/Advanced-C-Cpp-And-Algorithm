#include <stdio.h> // Chỉ thị bao hàm tệp

// #ifndef, #ifdef, #else, #if, #elif                  

#ifndef size
#define size 5


int array[size] = {1,2,3,4,5};


#endif

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < size; i++)
    {
        printf("arr[%d] = d\n", i ,array[i]);
    }

    return 0;
}
