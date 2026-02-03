#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
/*                                                     DATE -15/MAR/2024 */
void travers(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct node *ins_at_beg(struct node *head, int val)
{
    struct node *ptr = head;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;

    new->next = ptr;
    printf("\nInserted Succeccfully\n");
    travers(new);
    return new;
}

struct node *ins_at_end(struct node *head, int val)
{
    struct node *ptr;
    struct node *qtr;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    new->data = val;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
        qtr = ptr;
    }
    qtr->next = new;
    new->next = NULL;

    printf("\nInserted Succeccfully\n");
    travers(head);
    return head;
}

struct node *ins_at_ind(struct node *head, int val, int inde)
{

    struct node *ptr = head;
    struct node *new;
    new = (struct node *)malloc(sizeof(struct node));
    new->data = val;
    int i = 0;        //                              new
    while (i != inde) //          1     2    3     4      5     6
    {                 //         qtr   qtr  qtr   ptr
        ptr = ptr->next;
        i++;
    }

    new->next = ptr->next;
    ptr->next = new;
    travers(head);
    return head;

    /*
        struct node *new;
        new = (struct node *)malloc(sizeof(struct node));
        new->data = val;
        struct node *ptr = head;
        int i = 0;
                                        //  0    1     2     3 new 4
        while (i != index - 1)          //  1    2     3     4     5
        {                               // ptr  ptr   ptr   ptr
            ptr = ptr->next;            //
            i++;
        }
        new->next = ptr->next;
        ptr->next = new;
        return head;
    }
    */
}

struct node *del_first(struct node *head)
{

    head = head->next;
    return head;
}

struct node *del_last(struct node *head)
{
    struct node *ptr = head;
    struct node *qtr;
    while (ptr->next != NULL) //            11        222        222        222       NULL
    {                         //           qtr        qtr        qtr        ptr
        qtr = ptr;
        ptr = ptr->next;
    }
    qtr->next = NULL;
    free(ptr);

    return head;
}

struct node *del_ind(struct node *head, int ind)
{
    struct node *ptr = head;
    struct node *qtr;
    int i = 0;
    while (i != ind - 1)
    {
        qtr = ptr;       //            11     22      33     44      55
        ptr = ptr->next; //            qtr   qtr     ptr
        i++;
    }
    qtr->next = ptr->next;
    free(ptr);
    return head;
}
// mamin fn start from here
int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));
    fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;
    fifth->data = 50;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    printf("\t\t\t\t        ~::~::~::~::~::~::~::~ JAI SHRI RAM ~::~::~::~::~::~::~::~\n");
    printf("\n General Linked List\n");
    travers(head);

    printf("\nInsert 17 at the begining of the List \n");
    head = ins_at_beg(head, 17);

    printf("\nInsert 58 at the end of the linked List\n");
    head = ins_at_end(head, 58);
    printf("\n");
    travers(head);
    printf("\nInsert 35 at the 4th position in the linked List\n");
    head = ins_at_ind(head, 35, 2);

    printf("\nNow performing deletion in Linked List\n");

    printf("Perform deletion on the first element in Linked List\n");

    head = del_first(head);
    travers(head);
    printf("\n                            Done\n");

    printf("Perform deletion on the last element in Linked List\n");
    head = del_last(head);
    travers(head);
    printf("\n                            Done\n");

    printf("Perform deletion on the given index in Linked List\n");
    head = del_ind(head, 3);
    travers(head);
    printf("\n                            Done\n");

    printf("\n                  -::-::-::-::-Traversal, Insertion and Deletion operation done in a Linked List-::-::-::-::-\n");

    return 0;

}
