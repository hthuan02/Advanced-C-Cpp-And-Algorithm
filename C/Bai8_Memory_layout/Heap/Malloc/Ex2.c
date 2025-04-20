#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n = 10;
    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL)
    {
        printf("Cap phat khong thanh cong !\n");
    }
    else
    {
        int i = 0;
        printf("Cap phat thanh cong !\n");
        for (i = 0; i < n; i++)
        {
            a[i] = 28 + i; // *(a + i) = 28 cũng được
        }
        for (i = 0; i < n; i++)
        {
            printf("%d ", a[i]);
        }
        free(a);
    }
    return 0;
}

/*
ban đầu  int = 0

0  1  2  3....9
28 29 30 31...37

40 (byte cấp phát malloc) - 10 byte(sử dụng) = (dư) 30 byte 

--> Nhưng vì sử dụng hàm malloc(Cấp phát động).
--> Nên không xảy ra hiện tượng lãng phí bộ nhớ khi dư 30 byte.
*/