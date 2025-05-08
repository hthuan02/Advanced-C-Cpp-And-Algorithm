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

// Hàm thêm 1 node ở vị trí bất kỳ trong List
void insert(Node **array, int value, int pos)
{
    Node *new_Node = createNode(value);
    Node *p = *array;
    int index = 0;

    // Nếu thêm vị trí đầu
    if (pos == 0)
    {
        new_Node->next = *array;
        *array = new_Node;
        return;
    }

    // Duyệt qua list đến vị trí pos-1 (trước new_Node)
    while (p != NULL && index < pos - 1)
    {
        p = p->next;
        index++;
    }

    // Node 0 - Node 1 -0xC9- Node 2 - Node3
    // Nếu đã tìm được vị trí hợp lệ

    if (index == pos - 1)
    {
        new_Node->next = (p->next); // Node mới ->> trỏ đến Node sau
        p->next = new_Node;         // Node tại vị trí pos -1 ->> trỏ đến Node mới
    }
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

    insert(&n1, 10, 3);
    printlist(n1);
    return 0;
}
