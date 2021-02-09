#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node * Createlinkedlist(int n)
{
    node * head=NULL;//final linked list
    node * temp=NULL;//to create a temperorynode
    node * q=NULL;//used for iterating through linkedklist
    for(int i=0;i<n;i++)
    {
        temp=(node *)malloc(sizeof(node *));
        printf("Enter data:  ");
        scanf("%d",&(temp->data));
        temp->next=NULL;
        if(head==NULL){//if head is still empty
            head=temp;
        }
        else{
            q=head;
            while(q->next!=NULL){
                q=q->next;
            }
            q->next=temp;
        }    
    }
    return head;
}
void displaylist(node * head)
{
    node * q=head;
    while(q->next!=NULL)
    {
        printf("%d->",q->data);
        q=q->next;
    }
    printf("%d",q->data);
}
node * insertion_beg(node *head,int element)
{
    if(head==NULL)
    {
        node * t;
        t=(node *)malloc(sizeof(node *));
        t->data=element;
        t->next=NULL;
        head=t;
        printf("Insertion done succcessfully at the beginning ");
        return head;    
    }
    else
    {
        node *t;
        t=(node *)malloc(sizeof(node *));
        t->data=element;
        t->next=head;
        head=t;
         printf("\nInsertion done succcessfully at the beginning\n");
        return head;
    }
}
 node* insertion_end(node* head,int element){
     if(head==NULL){
        node * m;
        m=(node *)malloc(sizeof(node *));
        m->data=element;
        m->next=NULL;
        head=m;
        printf("\nInsertion done succcessfully in the end\n");
        return head;        
    }
    else
    {
        node * m;
        node * l;
        l=head;
        m=(node *)malloc(sizeof(node *));
        m->data=element;
        m->next=NULL;
        while(l->next!=NULL){
            l=l->next;
        }
        l->next=m;
        printf("\nInsertion done succcessfully in the end\n");    
       return head; 
    }
}
node * insertion_middle(node* head,int element,int pos){
    if(head!=NULL){
        node *p;
        p=head;
        int i=1;
        node* tempo;
        tempo=(node *)malloc(sizeof(node));
        tempo->data=element;
        
        while(i<pos-1){
            p=p->next;
            i=i+1;
        }
        tempo->next=p->next;
        p->next=tempo;
        printf("\nInsertion done successfully in the middle\n ");
        return head;
        
    }
}
node * deletion_beg(node* head){
    if(head==NULL){
        printf("No elements to delete");
    }
    else{
        node *t;
        t=(node *)malloc(sizeof(node *));
        t=head;
        head=head->next;
        free(t);
        printf("Deleted first element successfully!yo!!");
        return head;
    }
}
node * deletion_end(node * head){
    if(head==NULL){
        printf("Cannot delete element as linked list is element\n");
    }
    else{
        node *q;
        node *t;
        q=head;
       t=(node *)malloc(sizeof(node *));
        while(q->next->next!=NULL){
            q=q->next;
        }
        t=q->next;
        q->next=NULL;
        free(t);
        printf("\nDeleted successfully!\n");
        return head;
    }
}
node * deletion_between(node * head,int pos){
    if(head==NULL){
        printf("Deletion in between is not possible as list is empty\n");
    }
    else{
        node * q;
        int i=1;
        q=head;
        node * t;
        t=(node *)malloc(sizeof(node *));
        while(i<pos-1){
            q=q->next;
            i=i+1;
        }
        t=q->next;
        q->next=t->next;
        free(t);
        printf("\nDeleted successfully!");
        return head;   
    }
}
int main()
{//create a linked list
int n,choice;
float element;
int pos;
node * HEAD=NULL;
node *h;
h=(node *)malloc(sizeof(node *));
printf("How many nodes you want to create?");
scanf("%d",&n);
HEAD=Createlinkedlist(n);
int c;
displaylist(HEAD);
/*displaylist(insertion_beg(HEAD,10));
displaylist(insertion_middle(HEAD,90,3));*/
int s,position;
do{
printf("\nSelect one of the options:\nA.INSERTION\nB.DELETION\n");
scanf("%d",&s);
switch(s){
        case 5:   printf("\nwhere do you want to insert the element\n1.Beginning\n2.Middle\n3.End\n");
             scanf("%d",&choice);
      switch(choice){
       case 1: printf("\nEnter the element to be inserted:\n");
            scanf("%f",&element);
            displaylist(insertion_beg(HEAD,element));
            break;
       case 2: printf("Enter the element to be inserted and the position:\n");
            scanf("%f%d",&element,&pos);
            displaylist(insertion_middle(HEAD,element,pos));
            break;
       case 3: printf("\nEnter the element to be inserted:\n");
            scanf("%f",&element);
            displaylist(insertion_end(HEAD,element));
            break;
       default: printf("\nEnter valid option\n");
             break;}
        break;
    case 6: printf("Where do you want to delete the element?\n1.Beginning\n2.End\n3.Between\n");
            scanf("%d",&choice);
            switch(choice){
                case 1:displaylist(deletion_beg(HEAD));
                       break;
                case 2:displaylist(deletion_end(HEAD));
                       break;
                case 3:printf("Enter the position where you want to delete\n");
                       scanf("%d",&position);
                       displaylist(deletion_between(HEAD,position));
                       break;        
            }
        break;    
            
}
printf("\nWant to do make changes again?(1 or 0)\n");
scanf("%d",&c);
}while(c!=0);
/*if(c==0){
    printf("\nFinal linkedlist after insertions is :\n");
    displaylist(HEAD);
    printf("\nThankyou");
}*/

return 0;}/* #include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void main(){
    int n=5,i;
    struct node *head=NULL,*q=NULL;
    printf("Enter elements\n");
    q=head;
    for(i=0;i<n;i++)
    {
        struct node *t=(struct node *)malloc(sizeof(struct node));
        scanf("%d",&t->data);
        q->data=t->data;
        q=t;
    }
} */