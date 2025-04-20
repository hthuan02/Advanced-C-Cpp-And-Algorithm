#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 10;
    int *a = (int *)calloc(n, sizeof(int));
    if (a == NULL)
    {
        printf("Cap phat khong thanh cong !\n");
    }
    else
    {
        int i = 0;
        printf("Cap phat thanh cong !\n");
        printf("Mang ban dau : ");

        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        for (i = 0; i < n; i++)
        {
            a[i] = 28 + i; // *(a + i) = 28 cũng được
        }
        printf("\nMang sau khi thay doi : ");
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        free(a);
    }
    return 0;
}