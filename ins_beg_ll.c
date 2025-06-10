#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;

};


struct node  lltraversal(struct node *ptr)
{
    while(ptr!=0)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }    
        printf("\n");
}

struct node * insertion(struct node * head,int data)
{
    struct node * ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
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

   lltraversal(first);
   first = insertion(first,5);
   lltraversal(first);

   return 0;
}
