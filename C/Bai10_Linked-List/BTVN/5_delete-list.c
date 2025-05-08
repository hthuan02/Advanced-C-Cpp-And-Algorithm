#include <stdio.h>
#include <stdlib.h>

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

// Hàm xóa 1 vị trí bất kỳ trong List
void delete_list(Node **array, int pos)
{
    // Xóa Node ở vị trí đầu tiên
    Node *p = *array;
    if (*array == NULL)
    {
        return;
    }

    if (pos == 0)
    {
        *array = p->next;
        free(p);
        return;
    }

    int i = 0;
    
    // Duyệt qua danh sánh đến trước vị trí cần xóa
    while (p != NULL && i < pos - 1)
    {
        p = p->next;
        i++;
    }

    // Kiểm tra vị trí xóa hợp lệ hay không
    if (p == NULL || p->next == NULL)
    {
        return;
    }

    Node *temp = p->next; // Lưu con trỏ cần xóa
    p->next = temp->next; // Cập nhật lại
    free(temp);
}

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

    // insert(&n1, 10, 3);
    delete_list(&n1, 10);
    printlist(n1);
    return 0;
}
