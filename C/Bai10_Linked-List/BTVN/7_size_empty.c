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

// Hàm kiểm tra List có rỗng hay không
bool empty(Node *array) // 0 1
{
    return (array == NULL);
}

// Hàm kiểm tra kích thước List
int size(Node *array)
{
    int count = 0;
   
    while (array != NULL)
    {
        count++;
        array = array->next;
    }

    return count;
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
    printlist(n1);

    // Kiểm tra List rỗng hay không
    if (empty(n1))
    {
        printf("The List is empty.\n");
    }
    else
    {
        printf("The List is not empty.\n");
    }

    // Kiểm tra kích thước
    int listSize = size(n1);
    printf("Size of the List: %d\n", listSize);

    return 0;
}
