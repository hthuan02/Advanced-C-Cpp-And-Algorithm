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

// Hàm xóa 1 node ở cuối List
void pop_back(Node **array)
{
    Node *p = *array;
    Node *temp; // tim duyet vi ke cuoi
    int i = 0;

    while (p->next != NULL)
    {
        p = p->next;
        i++;
    }
    free(p);

    int j;
    temp = *array;
    for (j = 0; j < i - 1; j++)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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

    //printlist(n1);

    pop_back(&n1);
    printlist(n1);
    return 0;
}
