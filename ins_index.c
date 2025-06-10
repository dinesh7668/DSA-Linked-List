#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next;
};

void lltraversal(struct node * ptr)
{
    while(ptr!=NULL)
    {
        printf("%d, ",ptr->data);
        ptr=ptr->next;
    }
}

struct node * insertion(struct node *head,int index,int data)
 {
   struct node *ptr=(struct node *)malloc(sizeof(struct node));
   ptr->data=data;
   struct node *p=head;
   int i=0;

   while(i!=index-1)
   {
    p=p->next;
    i++;
   }
   ptr->next=p->next;
   p->next=ptr;
   return head;
 }
int main()
{
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;
    struct node *fifth;

   first=(struct node *)malloc(sizeof(struct node));
   second=(struct node *)malloc(sizeof(struct node));
   third=(struct node *)malloc(sizeof(struct node));
   fourth=(struct node *)malloc(sizeof(struct node));
   fifth=(struct node *)malloc(sizeof(struct node));
  
   
   first->data=10;
   second->data=20;
   third->data=30;
   fourth->data=40;
   fifth->data=50;
   

   first->next=second;
   second->next=third;
   third->next=fourth;
   fourth->next=fifth;
   fifth->next=NULL;

   printf("linked list before insertion \n");
   lltraversal(first);
   first = insertion(first,4,100);
   printf("linked list after insertion \n");
   lltraversal(first);
   //lltraversal(first);

   return 0;
}