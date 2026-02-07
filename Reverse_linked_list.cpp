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
}

void traverse(struct node *ptr)
{
    if (ptr == NULL)
    {
        cout << "Linked Lisst is emoty";
    }
    else
    {
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}

struct node * reverse(struct node *head){

    struct node * prev = NULL;
    struct node * curr = head;
    struct node * next = NULL;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main()
{
    struct node *head = createNode(10);
    struct node *sec = createNode(20);
    struct node *third = createNode(30);
    struct node *fourth = createNode(40);
    struct node *fifth = createNode(50);

    head->next = sec;
    sec->next = third;
    third->next = fourth;
    fourth->next = fifth;

    traverse(head);
    cout << endl
         << "list after reversing: ";
    head = reverse(head);
    traverse(head);

    return 0;
}
