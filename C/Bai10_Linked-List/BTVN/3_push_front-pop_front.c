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

// Hàm thêm 1 node ở đầu List
void push_front(Node **array, int value)
{
    Node *new_Node = createNode(value);
    new_Node->next = *array;
    *array = new_Node;
}
// Xóa 1 node ở đầu List
void pop_front(Node **array)
{
    if (*array == NULL)
    {
        return;
    }

    else
    {
        Node *p = *array;
        *array = p->next; // cap nhat lai *array, bo qua phan tu dau tien
        free(p);
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

        push_front(&n1, 10);
    pop_front(&n1);
    printlist(n1);

    return 0;
}
