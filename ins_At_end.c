#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * next; //self referencing structure.

};

void lltraversal(struct node * str)
{
    while(str!=NULL)
    {
        printf("%d, ",str->data);
        str=str->next;
    }
}

struct node *insert(struct node * head,int data)
{
    struct node * ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
   ptr->data=data;
   struct node * p;
   p=head;
   while(p->next!=NULL)
   {
    p=p->next;
   }
   p->next=ptr;
   ptr->next=NULL;
   return head;
}

int main()
{
 struct node * fir;
 struct node * sec;
 struct node * thi;
 struct node * fou;
 struct node * fif;

 fir=(struct node *)malloc(sizeof(struct node));
 sec=(struct node *)malloc(sizeof(struct node));
 thi=(struct node *)malloc(sizeof(struct node));
 fou=(struct node *)malloc(sizeof(struct node));
 fif=(struct node *)malloc(sizeof(struct node));

 fir->data=10;
 sec->data=20;
 thi->data=30;
 fou->data=40;
 fif->data=50;

 fir->next=sec;
 sec->next=thi;
 thi->next=fou;
 fou->next=fif;
 fif->next=NULL;

 printf("LINKED LIST BEFORE INSERTION \n");
 lltraversal(fir);
 printf("\nLINKED LIST AFTER INSERTION AT END  \n");
 fir=insert(fir,78);
 lltraversal(fir);

    return 0;
}