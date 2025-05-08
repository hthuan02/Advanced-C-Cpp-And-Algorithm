#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;

    return temp;
}

// Hàm lấy giá trị của Node ở vị tri bất kỳ List
int get1(Node *array, int pos)
{
    int i = 0;
    while (array != NULL && i < pos)
    {
        array = array->next;
        i++;
    }

    // Kiểm tra, đảm bảo không truy cập vượt quá List
    if (array == NULL)
    {
        return 0;
    }

    return array->data;
}

// // Phương pháp 2
// int get2(Node *array, int pos)
// {
//     int i = 0;
//     while (array->next != NULL && pos != i)
//     {
//         array = array->next;
//         i++;

//         // Nếu danh sách có ít phần tử hơn vị trí được yêu cầu
//         if (pos != i)
//         {
//             return 0;
//         }
//         return array->data;
//     }
// }
void printlist(Node *array)
{
    Node *p = array;
    int i = 0;

    while (p != NULL)
    {
        printf("Node = %d - Data = %d\n", i, p->data);
        p = p->next;
        i++;
    }
}

int main(int argc, char const *argv[])
{
    Node *n1 = createNode(5);
    Node *n2 = createNode(6);
    Node *n3 = createNode(7);

    n1->next = n2;
    n2->next = n3;
    printlist(n1);

    int pos;
    printf("\nEnter the position: ");
    scanf("%d", &pos);

    int value = get1(n1, pos);
    if (value != 0)
    {
        printf("Value is: %d\n", value);
    }


    return 0;
}
