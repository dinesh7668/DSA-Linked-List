#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int val)
{

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = val;
    ptr->next = NULL;
    return ptr;
}

void traversal(struct node *ptr)
{
    cout<<endl;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void insertionAfterNodeValue(struct node *head, int nodeVal, int val)
{

    struct node *ptr = head;
    while (ptr != NULL)
    {
        if (ptr->data == nodeVal)
        {
            struct node *newNode = createNode(val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            return;
        }

        ptr = ptr->next;
    }
    if (ptr == NULL)
    {
        cout << endl
             << "Error o_o : Node with value " << nodeVal << " does not exist in the list.";
    }
}


int main()
{

    struct node *head = createNode(10);
    struct node *second = createNode(20);
    struct node *third = createNode(30);
    struct node *fourth = createNode(40);

    head->next = second;
    second->next = third;
    third->next = fourth;

    cout<<"traversal before insertion";
    traversal(head);
    
    cout<<endl<<"traversal after insertion";
    insertionAfterNodeValue(head, 30, 35);
    traversal(head);
    return 0;
}
