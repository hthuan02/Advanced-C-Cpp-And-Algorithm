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

// Hàm lấy giá trị của node ở đầu LIST
int front(Node *array)
{

    if (array == NULL)
    {
        printf("Error: List is empty\n");
        return 0;
    }

    return array->data;
}

// Hàm lấy giá trị tại Node cuối cùng trong List
int back(Node *array)
{
    if (array == NULL)
    {
        printf("Error: List is Empty.\n");
        return 0;
    }

    // Duyệt đến Node cuối danh sách

    while (array->next != NULL)
    {
        array = array->next;
    }

    return array->data;
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

    // Lấy giá trị đầu và cuối
    int lastValue = back(n1);
    int frontValue = front(n1);

    // In ra giá trị
    if (frontValue != 0)
    {
        printf("Front Value: %d\n", frontValue);
    }

    if (lastValue != 0)
    {
        printf("Back Value: %d\n", lastValue);
    }

    return 0;
}
