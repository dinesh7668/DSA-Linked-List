#include<stdio.h>
#include<stdlib.h>
  struct node
  {
    int data;
    struct node * next;
  };

  struct node *deletion(struct node * head)
  {
    struct node * ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    return head;
  }
  void traversal(struct node * ptr)
  {
    while(ptr!=NULL)
    {
        printf("%d, ",ptr->data);
        ptr=ptr->next;
    }
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

    traversal(first);
    printf("\nafter deletion \n");
    first=deletion(first);
    traversal(first);
   
    return 0;
  }