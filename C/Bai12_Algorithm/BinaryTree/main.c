#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// them node va sap xep tu be den lon
// add_node thêm 1 node vào đầu danh sách, khi đưa 1 node vào, 
// thì nó tự động sắp xếp theo thứ tự từ bé đến lớn

void add_node(Node **head, int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL || (*head)->data >= value)
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *current = *head;

    //so sánh data của node đưa vào nhỏ hơn data node sắp xếpp
    while (current->next != NULL && current->next->data < value)
    {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;
}

typedef struct CenterPoint
{
    int value; //giá trị node gốc làm chuẩn, cây nhị phân
    struct CenterPoint *left; // nhánh trái data< giữa
    struct CenterPoint *right; // phải data> giữa
} CenterPoint;

// tim diem giua phia ben trai va ben phai su dung de quy
CenterPoint *buildTree(Node *head, int start, int end)
{
    if (head == NULL || start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *node = head;
    for (int i = start; i < mid; i++)
    {
        if (node->next == NULL)
        {
            break;
        }
        node = node->next;
    }
     
    //root, chứa data node giữa, vì cây nhị phân--> chứa nhánh trái-phải
    CenterPoint *root = (CenterPoint *)malloc(sizeof(CenterPoint));
    root->value = node->data;

    // buildTree tạo ra 1 cây nhị phân
    // lấy  node giữa làm chuẩn, sẽ có trái- phải(giống mảng)

    root->left = buildTree(head, start, mid - 1);
    root->right = buildTree(node->next, mid + 1, end);

    return root;
}

// tim diem giua
CenterPoint *centerPoint(Node *head) //  kiểu dl tự định nghĩa
{   
    // Đếm số lượng node có trong dsach
    int length = 0;
    Node *node = head;
    while (node != NULL)
    {
        node = node->next;
        length++; // số lượng --> lưu vào buildTree
    }

    return buildTree(head, 0, length - 1);
}

// ham tim kiem nhi phan
CenterPoint *binarySearch(CenterPoint *root, int value)
{
    static int loop = 0;
    loop++;
    printf("so lan lap: %d\n", loop);
    if (root == NULL)
    {
        return NULL;
    }

    if (root->value == value)
    {
        return root;
    }

    if (value < root->value)
    {
        return binarySearch(root->left, value);
    }
    else
    {
        return binarySearch(root->right, value);
    }
}

void print_list(Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    Node *head = NULL; // danh sách khởi tạo ban đầu là rỗng

    // tao ngau nhien 10000 node
    srand(time(NULL));
    for (int i = 0; i < 10000; i++)
    {
        int value = rand() % 10000 + 1; // %10000 +1 , giới hạn data 0-10000
        add_node(&head, value); // vì node đầu rỗng , nên nó chèn vào node 1, từ node 2-3 trở đi thực hiện so sánh
    }

    // add_node(&head, 5639);

    print_list(head); // sắp xếp thứ tự bé đến lớn

    //*ptr: trỏ đến địa chỉ node ở giữa ds
    CenterPoint *ptr = centerPoint(head); // Lấy node đầu, node cuối --> tìm (CenterPoint) Tìm kiếm node ở giữa

    int value = 5639;
    CenterPoint *result = binarySearch(ptr, value);
    if (result != NULL)
    {
        printf("Tim thay %d\n", result->value);
    }
    else
    {
        printf("Khong tim thay\n");
    }

    return 0;
}